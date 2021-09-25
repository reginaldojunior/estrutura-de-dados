#include "ListaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaLista(TipoLista *L) 
{
    (*L).primeiro = NULL;
    (*L).ultimo = NULL;

    printf("Lista criada com sucesso.\n");
}

int Insere(TipoLista *L, TipoItem I)
{
    TipoApontador p;

    p = (TipoApontador) malloc(sizeof(TipoNo));
    
    if (p == NULL) {
        printf("Lista está cheia. \n");

        return LISTA_CHEIA;
    }

    p->Item = I;
    p->prox = NULL;

    if (ListaVazia(L)) {
        L->primeiro = p;
        L->ultimo = p;
    } else {
        L->ultimo->prox = p;
        L->ultimo = p;
    }
}

int RemovePosicao(TipoLista *L, TipoApontador P)
{
    if (P == NULL) {
        printf("Posição Invalida. \n");
        return POSICAO_INVALIDA;
    }

    // unico elemento
    if (P == L->primeiro && P == L->ultimo) {
        CriaLista(L);
        free(P);

        return SEM_ERRO;
    }

    // remove do inicio
    if (P == L->primeiro) {
        L->primeiro = L->primeiro->prox;
        free(P);

        return SEM_ERRO;
    }
    
    // remove do meio
    TipoApontador aux = L->primeiro;
    while (aux->prox != NULL && aux->prox != P) {
        aux = aux->prox;
    }

    aux->prox = P->prox;

    // remove do fim
    if (aux->prox == NULL) {
        L->ultimo = aux;
    }

    free(P);
    return SEM_ERRO;
}

int Remove(TipoLista *L, TipoChave C)
{
    TipoApontador p = Pesquisa(L, C);
    
    int removido = RemovePosicao(L, p);
    if (removido == POSICAO_INVALIDA) {
        printf("Posição Inválida. \n");
    } else {
        printf("Sucesso! \n");
    }
}

TipoApontador Pesquisa(TipoLista *L, TipoChave C)
{
    TipoApontador p;

    p = L->primeiro;
    while (p != NULL) {
        if (p->Item.chave == C) {
            return p;
        }

        p = p->prox;
    }

    return p;
}

char ListaVazia(TipoLista *L)
{
    return L->ultimo == NULL && L->primeiro == NULL;
}

char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L)
{
    TipoApontador aux;
    TipoApontador p = L->primeiro;

    printf("Lista:\n");

    int i = 0;
    while (p != NULL) {
        if (p->prox != NULL) {
            printf("\t %d: Chave=%d, Proximo=%d \n", i, p->Item.chave, p->prox->Item.chave);
        } else {
            printf("\t %d: Chave=%d, Proximo=NULO \n", i, p->Item.chave);
        }
        p = p->prox;
        i++;
    }

    printf("\n\n");
}