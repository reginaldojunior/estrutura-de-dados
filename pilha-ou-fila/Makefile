CC = gcc
CFLAGS = -Wall
	
main: PilhaDinamica.c main.c
	$(CC) -o main PilhaDinamica.c FilaDinamica.c main.c
	
clean:
	rm main *.o

executa: main
	./main