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

// void InsereParaEsquerda(TipoNo *raiz, TipoItem I, TipoNo *E)
// {
//     TipoNo* p = (TipoNo*) malloc(sizeof(TipoNo));

//     E->Item = I;
//     raiz->esquerdo = E;
// }

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