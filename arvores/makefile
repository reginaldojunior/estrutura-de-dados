CC = gcc
CFGLAGS = -Wall
programa = arvores

arvores: ArvoreBinaria.c main.c
	$(CC) -o $(programa) ArvoreBinaria.c main.c

executa: arvores
	./$(programa)

clean:
	rm $(programa)
