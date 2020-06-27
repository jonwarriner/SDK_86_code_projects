@ECHO OFF

set :include:=C:\IC86_41

rem % is a special character in Windows 2000 (probably others too)
rem command prompt. Need to use %% 
C:\IC86_41\ASM86 CSTART.ASM PRINT %%define(controls)(sm ram fp mod86 asm86 em)
C:\IC86_41\ASM86 ..\utils\msDelay.ASM PRINT %%define(controls)(sm ram fp mod86 asm86 em)

C:\IC86_41\IC86 swan.c mod86 code searchinclude(C:\IC86_41\, ..\utils\)
C:\IC86_41\IC86 ..\utils\Intl8255.c mod86 code searchinclude(C:\IC86_41\, ..\utils\)
C:\IC86_41\IC86 ..\utils\Intl8251.c mod86 code searchinclude(C:\IC86_41\, ..\utils\)
rem C:\IC86_41\IC86 ..\utils\my_stdio.c mod86 code searchinclude(C:\IC86_41\, ..\utils\)
C:\IC86_41\IC86 logo.c mod86 code searchinclude(C:\IC86_41\, ..\utils\)

rem The line below would be the ideal way to call the linker
rem and redirect the input list to a file.
rem C:\IC86_41\LINK86 &<link.con
rem However, Windows 2000 (maybe other versions too) treat
rem the ampersand as a way to call multiple commands from
rem the same line.  We want to pass the ampersand to link86
rem to use as a continuation line.  So, we need to delay
rem expansion and create an argument variable to pass to 
rem link86.  
setlocal enableDelayedExpansion
set "linkarg=&<link.con"
C:\IC86_41\LINK86 !linkarg!

rem RAM Memory Map 
rem      _______________________
rem 0H  l                       l
rem     l       Interrupt       l
rem     l      Vectors 0-4      l
rem 13  l_______________________l
rem 14  l                       l
rem     l                       l
rem     l                       l
rem     l        Monitor        l
rem     l         Data          l
rem     l         Area          l
rem     l                       l
rem     l                       l
rem CF  l_______________________l
rem D0  l                       l
rem     l                       l
rem     l         User          l
rem     l         Stack         l
rem     l                       l
rem FF  l_______________________l
rem 100 l                       l
rem     l       INITCODE        l
rem     l        CSTART         l
rem 11F l_______________________l
rem 120 l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l         CODE          l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem 4FF l_______________________l
rem 500 l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l          DATA         l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem E7F l_______________________l
rem E80 l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l         CONST         l
rem     l                       l
rem     l                       l
rem     l                       l
rem EFF l_______________________l
rem F00 l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l         STACK         l
rem     l                       l
rem     l                       l
rem     l                       l
rem FFF l_______________________l

C:\IC86_41\LOC86 swan.lnk START(MAIN) INITCODE(100H) ADDRESSES(SEGMENTS(CODE(120H),DATA(500H),CONST(E80H),STACK(F00H))) MAP
C:\IC86_41\OH86 swan TO swan.hex