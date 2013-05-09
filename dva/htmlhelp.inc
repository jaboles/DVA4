'HTMLHelp Include file: copyright (c) Jonathan Boles 2000

const HH_DISPLAY_TOPIC=0
const HH_DISPLAY_TOC=1
const HH_DISPLAY_INDEX=2
const HH_DISPLAY_SEARCH=3

declare function HHelp lib "HHCTRL.OCX" alias "HtmlHelpA" (hwndCaller as integer, pszFile as string, uCommand as integer, dwdata as dword) as long
