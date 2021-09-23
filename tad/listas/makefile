CC = gcc
CFGLAGS = -Wall
programa = lista

lista: ListaEstatica.c main.c
	$(CC) -o $(programa) ListaEstatica.c main.c

executa: lista
	./$(programa)

clean:
	rm $(programa)
