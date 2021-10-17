#ifndef PILHA_H
#define PILHA_H

#define SEM_ERRO 0
#define POS_INVALIDA -1
#define NAO_ENCONTROU -2
#define PILHA_CHEIA -3

typedef int TipoChave;
typedef struct {
	TipoChave chave;
	char nome;
} TipoItemPilha;

typedef struct TipoNoPilha *TipoApontadorPilha;

typedef struct TipoNoPilha {
	TipoItemPilha item;
	struct TipoNoPilha *prox;
} TipoNoPilha;

typedef struct {
	TipoApontadorPilha primeiro;
} TipoPilha;

void CriaPilha(TipoPilha *P);
int InserePilha(TipoPilha *P, TipoItemPilha I);
void RemovePilha(TipoPilha *P);
TipoItemPilha UltimoPilha(TipoPilha *P);
TipoItemPilha TopoPilha(TipoPilha *P);

char PilhaVazia(TipoPilha *P);
char PilhaCheia(TipoPilha *P);

void ImprimePilha(TipoPilha *P);

#endif