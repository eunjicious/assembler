# Write this Makefile
myas: main.o trans.o check.o
	gcc -o myas main.o trans.o check.o
main.o: main.c
	gcc -c main.c
trans.o: trans.c
	gcc -c trans.c
check.o: check.c
	gcc -c check.c
