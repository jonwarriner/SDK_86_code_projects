@ECHO OFF

C:\IC86_41\ASM86 CSTART.ASM PRINT %define(controls)(sm ram fp mod86 asm86 em)
C:\IC86_41\ASM86 msDelay.ASM PRINT %define(controls)(sm ram fp mod86 asm86 em)
C:\IC86_41\IC86 hello.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 digits.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 keys.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 Intl8279.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 Intl8255.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 Intl8251.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 my_stdio.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 logo.c mod86 code searchinclude(C:\IC86_41\)

C:\IC86_41\LINK86 &<link.con

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
rem BFF l_______________________l
rem C00 l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l          DATA         l
rem     l                       l
rem     l                       l
rem     l                       l
rem     l                       l
rem DFF l_______________________l
rem E00 l                       l
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

C:\IC86_41\LOC86 hello.lnk START(MAIN) INITCODE(100H) ADDRESSES(SEGMENTS(CODE(120H),DATA(C00H),CONST(E00H),STACK(F00H))) MAP
C:\IC86_41\OH86 hello TO hello.hex