#include "PilhaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaPilha(TipoPilha *P) 
{
    P->ultimo = -1;
    printf("Pilha criada com sucesso\n");
}

int Insere(TipoPilha *P, TipoItem I)
{
    if (PilhaCheia(P)) {
        printf("Pilha está cheia \n");
        return PILHA_CHEIA;
    }

    P->ultimo++;
    P->itens[P->ultimo] = I;
}

int Remove(TipoPilha *P)
{   
    if (!PilhaVazia(P)) {
        P->ultimo--;
    }
}

TipoItem TopoPilha(TipoPilha *P)
{
    if (!PilhaVazia(P))
        return P->itens[P->ultimo];

    TipoItem I;
    I.chave = -1;

    return I;
}

char PilhaVazia(TipoPilha *P)
{
    return P->ultimo == -1;
}

char PilhaCheia(TipoPilha *P)
{
    return P->ultimo == MAXTAM - 1;
}

void ImprimePilha(TipoPilha *P)
{
    TipoApontador aux;

    printf("Pilha:\n");
    for (aux = P->ultimo; aux >= 0; aux--) {
        printf(" %d ", P->itens[aux].chave);
    }
    printf("\n\n");
}