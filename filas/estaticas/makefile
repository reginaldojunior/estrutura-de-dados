CC = gcc
CFGLAGS = -Wall
programa = lista

lista: PilhaEstatica.c main.c
	$(CC) -o $(programa) PilhaEstatica.c main.c

executa: lista
	./$(programa)

clean:
	rm $(programa)
