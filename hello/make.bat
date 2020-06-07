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

rem C:\IC86_41\LINK86 hello.obj,digits.obj,keys.obj,Intl8279.obj,Intl8255.obj,Intl8251.obj,msDelay.obj,cstart.obj,my_stdio.obj,logo.obj
rem C:\IC86_41\LINK86 hello.obj,    & ; comment rem digits.obj,                     & ; comment rem keys.obj,                       & ; comment rem Intl8279.obj,                   & ; comment rem Intl8255.obj,                   & ; comment rem Intl8251.obj,                   & ; comment rem msDelay.obj,                    & ; comment rem cstart.obj,                     & ; comment rem my_stdio.obj,                   & ; comment rem logo.obj                        & ; comment rem to hello.86

C:\IC86_41\LINK86 &<link.con

rem RAM Memory Map 
rem      _______________________
rem 0H  |                       |
rem   	|       Interrupt       |
rem   	|      Vectors 0-4      |
rem 13	|_______________________|
rem 14	|                       |
rem     |                       |
rem     |                       |
rem     |        Monitor        |
rem     |         Data          |
rem     |         Area          |
rem     |                       |
rem     |                       |
rem CF  |_______________________|
rem D0  |                       |
rem     |                       |
rem     |         User          |
rem     |         Stack         |
rem     |                       |
rem FF  |_______________________|
rem 100 |                       |
rem     |       INITCODE        |
rem     |        CSTART         |
rem 11F |_______________________|
rem 120 |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |         CODE          |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem BFF |_______________________|
rem C00 |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |          DATA         |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem DFF |_______________________|
rem E00 |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |         CONST         |
rem     |                       |
rem     |                       |
rem     |                       |
rem EFF |_______________________|
rem F00 |                       |
rem     |                       |
rem     |                       |
rem     |                       |
rem     |         STACK         |
rem     |                       |
rem     |                       |
rem     |                       |
rem FFF |_______________________|

C:\IC86_41\LOC86 hello.lnk START(MAIN) INITCODE(100H) ADDRESSES(SEGMENTS(CODE(120H),DATA(C00H),CONST(E00H),STACK(F00H))) MAP
C:\IC86_41\OH86 hello TO hello.hex