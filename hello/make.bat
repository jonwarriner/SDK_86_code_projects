C:\IC86_41\ASM86 CSTART.ASM PRINT %define(controls)(sm ram fp mod86 asm86 em)
C:\IC86_41\ASM86 msDelay.ASM PRINT %define(controls)(sm ram fp mod86 asm86 em)
C:\IC86_41\IC86 hello.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 digits.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 keys.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 Intl8279.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 Intl8255.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 Intl8251.c mod86 code searchinclude(C:\IC86_41\)
C:\IC86_41\IC86 my_stdio.c mod86 code searchinclude(C:\IC86_41\)

C:\IC86_41\LINK86 hello.obj,digits.obj,keys.obj,Intl8279.obj,Intl8255.obj,Intl8251.obj,msDelay.obj,cstart.obj,my_stdio.obj

C:\IC86_41\LOC86 hello.lnk START(MAIN) INITCODE(100H) ADDRESSES(SEGMENTS(CODE(120H),DATA(800H),CONST(900H),STACK(A00H))) MAP
C:\IC86_41\OH86 hello TO hello.hex