#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#define SEM_ERRO 0
#define POSICAO_INVALIDA -1
#define NAO_ENCONTROU -2
#define LISTA_CHEIA -3

typedef int TipoChave;
typedef struct {
    TipoChave chave;
} TipoItem;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo {
    TipoItem Item;
    struct TipoNo *prox, *ant;
} TipoNo;

typedef struct {
    TipoApontador primeiro, ultimo;
} TipoLista;

void CriaLista(TipoLista *L);
int Insere(TipoLista *L, TipoItem I);
int SubstituiItemPorChave(TipoLista *L, TipoChave C, TipoItem I);
int Remove(TipoLista *L, TipoChave C);
int RemovePosicao(TipoLista *L, TipoApontador P);
TipoApontador Pesquisa(TipoLista *L, TipoChave C);

char ListaVazia(TipoLista *L);
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L);
void ImprimeListaInvertida(TipoLista *L);

#endif