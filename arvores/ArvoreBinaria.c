#include "ArvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>

void CriaArvore(TipoNo *A, TipoItem I, TipoNo *E, TipoNo *D) 
{
    A->Item = I;
    A->esquerdo = E;
    A->direito = D;
}

TipoNo* CriaNo(TipoItem I, TipoNo *E, TipoNo *D) 
{
    TipoNo* N = (TipoNo*)malloc(sizeof(TipoNo));

    N->Item = I;
    N->esquerdo = E;
    N->direito = D;

    return N;
}

int Insere(TipoNo *A, TipoItem I)
{
    if (A->esquerdo == NULL) {
        A->esquerdo = CriaNo(I, NULL, NULL);
        return 1;
    }

    if (A->direito == NULL) {
        A->direito = CriaNo(I, NULL, NULL);
        return 1;
    }

    if (A->esquerdo->Item.chave > I.chave) {
        Insere(A->direito, I);
    } else {
        Insere(A->esquerdo, I);
    }

    return 0;
}
 
TipoNo* Pesquisa(TipoNo* N, TipoChave C)
{
    printf("n.item %d chave %d \n", N->Item.chave, C);
    if (N == NULL) {
        return NULL;
    } else if (N->Item.chave > C) {
        return Pesquisa(N->esquerdo, C);
    } else if (N->Item.chave < C) {
        return Pesquisa(N->direito, C);
    } else {
        return N;
    }
}
 

void ImprimeArvore(TipoNo *raiz)
{
    if (raiz != NULL){
        printf("%d \n", raiz->Item.chave);

        if (raiz->esquerdo != NULL) {
            ImprimeArvore(raiz->esquerdo);
        }

        if (raiz->direito != NULL) {
            ImprimeArvore(raiz->direito);
        }
    }
}