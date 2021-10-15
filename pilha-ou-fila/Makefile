CC = gcc
CFLAGS = -Wall
	
all: PilhaDinamica.c main.c
	$(CC) -o main PilhaDinamica.c FilaDinamica.c main.c
	
clean:
	rm main *.o

run: main
	./main