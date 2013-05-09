Declare Function GetShortPathName Lib "kernel32" Alias "GetShortPathNameA" (Byref lpszLongPath As String, Byref lpszShortPath As String, ByVal cchBuffer As Long) As Long
Declare Function GetShortFileName(Fn As String) As String

Function GetShortFileName(Fn As String) As String
Dim rc As Long
Dim ShortPath As String
Dim tmpStr as string
dim PATH_LEN as long
PATH_LEN = 164
tmpStr = Fn
ShortPath = String$(PATH_LEN + 1, 0)
rc = GetShortPathName(tmpStr, ShortPath, PATH_LEN)
GetShortFileName = Left$(ShortPath, rc)
End Function
