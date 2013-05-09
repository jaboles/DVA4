sub LoadDVA4
            OpenFilestream.Open(Filename,fmOpenRead)
            OpenFilestream.ReadUDT(CurrentFile)
            OpenFilestream.Close
            dfHeader=Header
            dflTitle=len(rtrim$(CurrentFile.Title))
            dfTitle=rtrim$(CurrentFile.Title)
            dflAuthor=len(rtrim$(CurrentFile.Author))
            dfAuthor=rtrim$(CurrentFile.Author)
            dflComments=len(rtrim$(CurrentFile.Comments))
            dfComments=rtrim$(CurrentFile.Comments)
            dflDefaultDir=len(rtrim$(CurrentFile.DefaultDir))
            dfDefaultDir=rtrim$(CurrentFile.DefaultDir)
            dflContents=len(rtrim$(CurrentFile.Contents))
            dfContents=rtrim$(CurrentFile.Contents)
            FileEnhanced=True
end sub

sub LoadDVA00_41
            OpenFilestream.Open(Filename,fmOpenRead)
            dfHeader=OpenFilestream.ReadStr(8)
            dflTitle=OpenFilestream.Readnum(2)
            dfTitle=rtrim$(OpenFilestream.ReadStr(dflTitle))
            dflAuthor=OpenFilestream.Readnum(2)
            dfAuthor=rtrim$(OpenFilestream.ReadStr(dflAuthor))
            dflComments=OpenFilestream.Readnum(4)
            dfComments=rtrim$(OpenFilestream.ReadStr(dflComments))
            dflDefaultDir=OpenFilestream.Readnum(2)
            dfDefaultDir=rtrim$(OpenFilestream.ReadStr(dflDefaultDir))
            dflContents=OpenFilestream.Readnum(4)
            dfContents=rtrim$(OpenFilestream.ReadStr(dflContents))
            OpenFilestream.Close
            FileEnhanced=True
end sub