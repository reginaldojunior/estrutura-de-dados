#ifndef FILADINAMICA_H
#define FILADINAMICA_H

#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU -2
#define FILA_CHEIA -3

typedef int TipoChave;
typedef struct {
	TipoChave chave;
	//char nome[50];
} TipoItem;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo {
	TipoItem item;
	struct TipoNo *prox;
} TipoNo;

typedef struct {
	TipoApontador primeiro;
	TipoApontador ultimo;
} TipoFila;

void CriaFila(TipoFila *F);
int enfileira(TipoFila *F, TipoItem I);
void desenfileira(TipoFila *F);
TipoItem frente(TipoFila *F);

char FilaVazia(TipoFila *F);
char FilaCheia(TipoFila *F);

void ImprimeFila(TipoFila *F);

#endif