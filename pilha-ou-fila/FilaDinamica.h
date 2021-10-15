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
} TipoItemFila;

typedef struct TipoNoFila *TipoApontadorFila;

typedef struct TipoNoFila {
	TipoItemFila item;
	struct TipoNoFila *prox;
} TipoNoFila;

typedef struct {
	TipoApontadorFila primeiro;
	TipoApontadorFila ultimo;
} TipoFila;

void CriaFila(TipoFila *F);
int enfileira(TipoFila *F, TipoItemFila I);
TipoItemFila desenfileira(TipoFila *F);
TipoItemFila frente(TipoFila *F);

char FilaVazia(TipoFila *F);
char FilaCheia(TipoFila *F);

void ImprimeFila(TipoFila *F);

#endif