#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#define SEM_ERRO 0
#define POSICAO_INVALIDA -1
#define NAO_ENCONTROU -2
#define LISTA_CHEIA -3

typedef int TipoChave;
typedef struct {
    TipoChave chave;
    char nome[25];
} TipoItem;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo {
    TipoItem Item;
    struct TipoNo *prox;
} TipoNo;

typedef struct {
    TipoApontador primeiro, ultimo;
} TipoLista;

void CriaLista(TipoLista *L);
int Insere(TipoLista *L, TipoItem I);
int OrdenaPorSelecao(TipoLista *L);
int Remove(TipoLista *L, TipoChave C);
int RemovePosicao(TipoLista *L, TipoApontador P);
TipoApontador Pesquisa(TipoLista *L, TipoChave C);

char ListaVazia(TipoLista *L);
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L);

#endif