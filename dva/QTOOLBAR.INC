Type QToolBar extends QPanel

'Public
   ButtonX as integer          'Button Clicked
   ShowHint as short           
   Hint() as string            'Hint of buttons 
   Enabled() as short          'Button enable or nott
   Flat as short               'Flat buttons or not
   imglHandle as integer       'Handle 
   imglDHandle as integer      'Handel 2

'Private
   imgl1 as Qimagelist         'Active buttton
   imgl2 as Qimagelist         'Disabel button
   img as qcanvas              'on paint Buttons 
   Butbmp as QBitmap           'our False button
   CButton as qCoolBtn         ' one real button
   Buttons as integer          'Number of buttons
   X as Integer                'Height of bmp
   Y as Integer                'Width of bmp

   Sub load
      With QtoolBar
         .imgl1.handle = .imglHandle     'QIamgeList 1  Enabled button
         .imgl2.handle = .imglDHandle    'QImageList 2  Disabled Button
         .Buttons = .imgl1.Count         'How many buttons?
         .X = .imgl1.Width+6.: .Y = .imgl1.Width+6     'Dimensions
         if .Align =1 or .Align =2 or .Align =0 then   '& position
             if .Height <> .X + 12 then .Height = .X + 12
             if .Width <> .Y*.Buttons then .Width = .Y*.Buttons + 12
         else
             if .Height <> .X*.Buttons then .Height = .X*.Buttons + 12
             if .Width  <> .Y + 12 then .Width = .Y +12
         end if
         
         'Drawing one false button
         .ButBmp.Height = .X: .ButBmp.Width = .Y
         if .Flat Then                          'is a flat toolbar
            .ButBmp.FillRect (0, 0, .X, .Y, &HC0C0C0)
         Else                                   'isn`t flat tool bar  
            .ButBmp.FillRect (0, 0, .X, .Y, &HC0C0C0)
            .ButBmp.Line (0, 0, .X-2, 0, &HFFFFFF)
            .ButBmp.Line (0, 0, 0, .Y-2, &HFFFFFF)
            .ButBmp.Line (1, 1, .X-3, 1, &HDFDFDF)
            .ButBmp.Line (1, 1, 1, .Y-3, &HDFDFDF)
            .ButBmp.Line (0, .Y-1, .X-1, .Y-1, &H000000)
            .ButBmp.Line (.X-1, .Y-1, .X-1, 0, &H000000)
            .ButBmp.Line (1, .Y-2, .X-2, .Y-2, &H808080)
            .ButBmp.Line (.X-2, .Y-2, .X-2, 1, &H808080)
         end if
         
         'a lot of propieties
         .img.parent = Qtoolbar
         .img.Top = 6: .img.Left = 6
         if .Align =1 or .Align =2 or .Align =0 then
            .img.Height = .X: .img.Width = .Buttons*.X
         else
            .img.Width = .Y: .img.Height = .Buttons*.Y
         end if
         .Cbutton.Parent = QtoolBar
         .Cbutton.Height = .X:.Cbutton.Width = .Y
         if .Align =1 or .Align =2 or .Align =0 then
            .Cbutton.top = 6 : .CButton.Left = -100
         else
            .Cbutton.Left = 6 : .CButton.Top = -100
         end if
         .Cbutton.Flat = .Flat
         .Cbutton.ShowHint = .ShowHint 
      End With
   End Sub

   Sub Paint 'Draw Buttons 
      Dim a as integer 
      With QtoolBar
         .CButton.Down = 0
         For a = 0 to .Buttons -1
            if a <> .ButtonX then
               If .Enabled(a) then
                  .ButBmp.Draw (3,3,Qtoolbar.imgl1.GetBMP(a))
               else
                  .ButBmp.Draw (3,3,Qtoolbar.imgl2.GetBMP(a))
               end if
               if .Align =1 or .Align =2 or .Align =0 then
                  .img.Draw (a*.X, 0, .ButBmp.Bmp)
               else
                  .img.Draw (0,a*.Y, .ButBmp.Bmp)
               End if
            end if
         Next
      End With
   end sub

   Sub showButton 'Show the correct button
      With QToolBar
         if .Align =1 or .Align =2 or .Align =0 then
            .ButtonX = mouseX \ .X
         else
            .ButtonX = mouseY \ .Y
         end if
         IF .Enabled(.ButtonX) then
            .CButton.BMP = Qtoolbar.imgl1.GetBMP(.ButtonX)
         else
            Exit sub
         end if
         if .Align =1 or .Align =2 or .Align =0 then
            .CButton.Left = .ButtonX*.X + 6
         else
            .CButton.Top = .ButtonX*.Y + 6
         end if
         .CButton.hint = .hint(.ButtonX)
         .CButton.Visible = 1
       end With
   end Sub

   Sub Reset 'Reset toolbar 
      QToolbar.ButtonX = -1
      QToolbar.CButton.Visible = 0
      QToolbar.Paint
   end Sub

   Event img.onpaint
      QtoolBar.Paint
   end Event

   Event img.OnMouseMove
      QtoolBar.ShowButton
   end Event

   Event OnMouseMove
      QToolbar.Reset
   end Event

   Constructor
      Width = 0
      Height = 0
      Buttons = 0
      ButtonX = -1
      Flat = 1
      Enabled() = 1
      Hint() = ""
      ShowHint = 1
      Cursor=crHandPoint
   end constructor
end type
