#include <stdio.h>
#include <string.h>
#include "conjunto.h"


void inicializar(t_conjunto A)
{
    memset(A, 0, sizeof(t_conjunto));
}

int pertence(t_elemento e, t_conjunto A)
{
    if (e < 0 || e >= MAX) {
        printf("Posição informada inválida \n");
        return -1;
    }

    return A[e];
}

void uniao(t_conjunto A, t_conjunto B, t_conjunto C)
{
    for (int i = 0; i < MAX; i++) {
        C[i] = A[i] || B[i];
    }
}

void interseccao(t_conjunto A, t_conjunto B, t_conjunto C) 
{

    for (int i = 0; i < MAX; i++) {
        C[i] = A[i] && B[i];
    }
}

void insercao(t_elemento e, t_conjunto A) 
{
    if (e < 0 || e >= MAX) {
        printf("Posição informada inválida \n");
        return;
    }

    if (pertence(e, A)) {
        printf("Elemento já foi inserido \n");
        return;
    }

    A[e] = 1;
}

void imprimir(t_conjunto A)
{
    printf("{");
    for (int i = 0; i < MAX; i++)
        if (pertence(i, A))
            printf("%d, ", i);
    printf("}  \n");
}

void remocao(t_elemento e, t_conjunto A)
{
    if (e < 0 || e >= MAX) {
        printf("Posição informada inválida \n");
        return;
    }

    if (!pertence(e, A)) {
        printf("Elemento não pertence ao conjunto \n");
        return;
    }

    A[e] = 0;
}