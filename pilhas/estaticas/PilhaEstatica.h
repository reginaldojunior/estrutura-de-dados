#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#define MAXTAM 1000
#define SEM_ERRO 0
#define POSICAO_INVALIDA -1
#define NAO_ENCONTROU -2
#define PILHA_CHEIA -3

typedef int TipoChave;
typedef int TipoApontador;

typedef struct {
    TipoChave chave;
    // char nome[25];
} TipoItem;

typedef struct
{
    TipoItem itens[MAXTAM];
    TipoApontador ultimo;
} TipoPilha;

void CriaPilha(TipoPilha *P);
int Insere(TipoPilha *P, TipoItem I);
int Remove(TipoPilha *P);
TipoItem TopoPilha(TipoPilha *P);

char PilhaVazia(TipoPilha *P);
char PilhaCheia(TipoPilha *P);

void ImprimePilha(TipoPilha *L);

#endif