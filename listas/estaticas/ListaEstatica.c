#include "ListaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaLista(TipoLista *L) 
{
    L->ultimo = -1;
    printf("Lista criada com sucesso\n");
}

int Insere(TipoLista *L, TipoItem I)
{
    if (ListaCheia(L)) {
        printf("Lista está cheia \n");
        return LISTA_CHEIA;
    }

    L->ultimo++;
    L->itens[L->ultimo] = I;
}

int RemoveTodasAsChaves(TipoLista *L, TipoChave C)
{
    for (int i = 0; i < L->ultimo; i++) {
        TipoApontador P = Pesquisa(L, C);
        TipoApontador aux;

        for (aux = P; aux < L->ultimo; aux++) {
            L->itens[aux] = L->itens[aux+1];
        }

        L->ultimo--;
    }
}

int Remove(TipoLista *L, TipoChave C)
{
    RemovePosicao(L, Pesquisa(L, C));
}

int RemovePosicao(TipoLista *L, TipoApontador P)
{
    TipoApontador aux;

    if (P < 0 || P > L->ultimo) {
        printf("Posição Invalida. \n");
        return POSICAO_INVALIDA;
    }

    for (aux = P; aux < L->ultimo; aux++) {
        L->itens[aux] = L->itens[aux+1];
    }

    L->ultimo--;
}

TipoApontador Pesquisa(TipoLista *L, TipoChave C)
{
    TipoApontador aux;

    for (aux = 0; aux <= L->ultimo; aux++) {
        if (L->itens[aux].chave == C)
            return aux;
    }

    return NAO_ENCONTROU;
}

char ListaVazia(TipoLista *L)
{
    return L->ultimo == -1;
}

char ListaCheia(TipoLista *L)
{
    return L->ultimo == MAXTAM - 1;
}

void ImprimeLista(TipoLista *L)
{
    TipoApontador aux;

    printf("Lista:\n");
    for (aux = 0; aux <= L->ultimo; aux++) {
        printf("\t{ Chave: %d }\n", L->itens[aux].chave);
    }
    printf("\n\n");
}