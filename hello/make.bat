C:\IC86_41\ASM86 CSTART.ASM PRINT %define(controls)(sm ram fp mod86 asm86 em)
C:\IC86_41\IC86 hello.c mod86 code searchinclude(C:\IC86_41\)
rem C:\IC86_41\IC86 ReadData.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 digits.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 keys.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 Intl8279.c mod86 code searchinclude(C:\IC86_41\)

rem C:\IC86_41\LINK86 hello.obj, digits.obj, ReadData.obj, cstart.obj
C:\IC86_41\LINK86 hello.obj, digits.obj, keys.obj, Intl8279.obj, cstart.obj

rem C:\IC86_41\LOC86 hello.lnk START(MAIN) INITCODE(100H) ADDRESSES(SEGMENTS(CODE(120H),DATA(200H),CONST(300H),STACK(400H))) MAP
C:\IC86_41\LOC86 hello.lnk START(MAIN) INITCODE(100H) ADDRESSES(SEGMENTS(CODE(120H),DATA(300H),CONST(400H),STACK(500H))) MAP
C:\IC86_41\OH86 hello TO hello.hex