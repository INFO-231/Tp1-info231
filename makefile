CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.o fonction_operation.o
	$(CC) $(CFLAGS) -o main main.o fonction_operation.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

fonction_operation.o: fonction_operation.c
	$(CC) $(CFLAGS) -c fonction_operation.c

clean:
	rm -f *.o main
