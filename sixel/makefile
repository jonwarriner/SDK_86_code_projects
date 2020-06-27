test : main.o sixel.o
	cc -o test main.o sixel.o

main.o : main.c sixel.h
	cc -Wall -Werror -c main.c

sixel.o : sixel.c sixel.h
	cc -Wall -Werror -c sixel.c

clean :
	rm test main.o sixel.o

