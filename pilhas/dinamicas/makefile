CC = gcc
CFGLAGS = -Wall
programa = lista

lista: ListaDinamica.c main.c
	$(CC) -o $(programa) ListaDinamica.c main.c

executa: lista
	./$(programa)

clean:
	rm $(programa)
