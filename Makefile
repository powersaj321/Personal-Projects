CFLAGS= -g -O0 -Wall --std=c99 -pedantic -o

flashcard: main.c logic.c
	gcc $(CFLAGS) RPSLSGame main.c logic.c

clean:
	rm -f RPSLSGame
