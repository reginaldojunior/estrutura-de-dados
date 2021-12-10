#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#define SEM_ERRO 0
#define POSICAO_INVALIDA -1
#define NAO_ENCONTROU -2
#define ARVORE_CHEIA -3

typedef int TipoChave;
typedef struct {
    TipoChave chave;
} TipoItem;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo {
    TipoItem Item;
    struct TipoNo *esquerdo, *direito;
} TipoNo;

typedef struct {
    TipoApontador esquerdo, direito;
} TipoArvore;

void CriaArvore(TipoNo *A, TipoItem I, TipoNo *E, TipoNo *D);
TipoNo* CriaNo(TipoItem I, TipoNo *E, TipoNo *D);
int Insere(TipoNo *A, TipoItem I);
int SubstituiItemPorChave(TipoArvore *A, TipoChave C, TipoItem I);
int Remove(TipoArvore *A, TipoChave C);
int RemovePosicao(TipoArvore *A, TipoApontador P);
TipoNo* Pesquisa(TipoNo* N, TipoChave C);

char ArvoreVazia(TipoArvore *A);
char ArvoreCheia(TipoArvore *A);

void ImprimeArvore(TipoNo *A);

#endif