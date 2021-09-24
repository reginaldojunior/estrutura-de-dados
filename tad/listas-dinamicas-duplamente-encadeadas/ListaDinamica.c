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
    p->ant = NULL;

    if (ListaVazia(L)) {
        L->primeiro = p;
        L->ultimo = p;

        p->prox = NULL;
    } else if (L->primeiro->Item.chave > I.chave) { // primeiro posicao
        p->prox = L->primeiro;
        L->primeiro->ant = p;
        L->primeiro = p;
    } else { // todos os demais
        TipoApontador aux;
        aux = L->primeiro;
        while (aux->prox != NULL && aux->prox->Item.chave < I.chave) {
            aux = aux->prox;
        }

        p->prox = aux->prox;
        p->ant = aux;
        aux->prox = p;

        if (p->prox != NULL)
            p->prox->ant = p;
    }

    return SEM_ERRO;
}

int SubstituiItemPorChave(TipoLista *L, TipoChave C, TipoItem I)
{
    if (ListaVazia(L)) {
        return NAO_ENCONTROU;
    }

    TipoApontador p, aux;
    int encontrou = 0;
    p = L->primeiro;
    while (p != NULL) {
        if (p->Item.chave == C) {
            TipoItem old = p->Item;
            p->Item = I;
            Insere(L, old);
            encontrou = 1;
        }

        p = p->prox;
    }

    if (encontrou == 0) {
        printf("Posição Invalida. \n");
        return POSICAO_INVALIDA;
    }

    p = L->primeiro;
    while (p != NULL) {
        if (p->prox != NULL) {
            if (p->Item.chave > p->prox->Item.chave) {
                TipoItem aux = p->Item;
                p->Item = p->prox->Item;
                p->prox->Item = aux;
            }
        }

        p = p->prox;
    }

    return SEM_ERRO;
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
        L->primeiro->ant = NULL; 
        free(P);

        return SEM_ERRO;
    }

    P->ant->prox = P->prox;

    // remove do fim
    if (P == L->ultimo) {
        L->ultimo = P->ant;
    } else {
        P->prox->ant = P->ant;
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
        if (p->prox != NULL && p->ant != NULL) {
            printf("\t %d: Chave=%d, Proximo=%d, Anterior=%d \n", i, p->Item.chave, p->prox->Item.chave, p->ant->Item.chave);
        } else if (p->prox == NULL && p->ant != NULL) {
            printf("\t %d: Chave=%d, Proximo=NULO, Anterior=%d \n", i, p->Item.chave, p->ant->Item.chave);
        } else {
            printf("\t %d: Chave=%d, Proximo=NULO, Anterior=NULO \n", i, p->Item.chave);
        }
        p = p->prox;
        i++;
    }

    printf("\n\n");
}

void ImprimeListaInvertida(TipoLista *L)
{
    TipoApontador p = L->ultimo;

    printf("Lista Invertida:\n");

    int i = 0;
    while (p != NULL) {
        if (p->ant != NULL) {
            printf("\t %d: Chave=%d, Anterior=%d \n", i, p->Item.chave, p->ant->Item.chave);
        } else {
            printf("\t %d: Chave=%d, Anterior=NULO \n", i, p->Item.chave);
        }
        p = p->ant;
        i++;
    }

    printf("\n\n");
}