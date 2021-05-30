main.out: main.o print.o
	gcc -o main.out main.o print.o

print.o: print.c
	gcc -o print.o -c print.c

main.o: main.c
	gcc -o main.o -c main.c

clean:
	rm *.o *.out