C:\IC86_41\ASM86 CSTART.ASM PRINT %define(controls)(sm ram fp mod86 asm86 em)
C:\IC86_41\IC86 hello.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 ReadData.c mod86 code searchinclude(C:\IC86_41\)

C:\IC86_41\LINK86 hello.obj, ReadData.obj, cstart.obj

C:\IC86_41\LOC86 hello.lnk START(MAIN) ADDRESSES(SEGMENTS(CODE(100H),DATA(200H),CONST(300H),STACK(400H))) MAP
rem C:\IC86_41\OH86 hello TO hello.hex