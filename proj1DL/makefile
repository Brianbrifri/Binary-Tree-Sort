testscanner: main.o scanner.o
	gcc main.o scanner.o -o testscanner
main.o: main.c  scanner.h
	gcc -c main.c
scanner.o: scanner.c token.h scanner.h
	gcc -c scanner.c

clean:
	rm scanner.o main.o testscanner
	echo clean done
