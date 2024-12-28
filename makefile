
output: main.o MathsFuncs.o game.o
	gcc main.o MathsFuncs.o game.o -o output

main.o: main.c MathsFuncs.h game.h
	gcc -c main.c -o main.o -Wall -g

MathsFuncs.o: MathsFuncs.c MathsFuncs.h
	gcc -c MathsFuncs.c -o MathsFuncs.o -Wall -g

game.o: game.c game.h
	gcc -c game.c -o game.o -Wall -g

clean:
	rm -f *.o output
