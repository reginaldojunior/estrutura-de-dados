#include <stdio.h>
#include <stdlib.h>

#include "conjunto.h"

int pertence(int *vetor, int value)
{
    for (int i = 0; i < SIZE_VETOR; i++) {
        if (vetor[i] == value) {
            return i;
        }
    }

    return -1;
}

void imprime(int *vetor, int tamanho_vetor)
{
    printf("{ ");
    for (int i = 0; i < tamanho_vetor; i++) { 
        if ((i + 1) == tamanho_vetor) {
            printf(" %d", vetor[i]);
        } else {
            printf(" %d,", vetor[i]);
        }
    }
    printf(" }");
}

int insere(int *vetor, int value, int posicao) 
{
    if (pertence(vetor, value) == -1) {
        vetor[posicao] = value;
    }
}

int remove_item(int *vetor, int value)
{
    int chave = pertence(vetor, value);

    if (chave != -1) {
        vetor[chave] = VALOR_VAZIO_CONJUNTO;
    }
    
    return -1;
}

int uniao(int *vetor_a, int *vetor_b, int *vetor_c) 
{
    for (int i = 0; i < SIZE_VETOR; i++) {
        vetor_c[i] = vetor_a[i];
    }

    for (int i = 0; i < SIZE_VETOR; i++) {
        insere(vetor_c, vetor_b[i], SIZE_VETOR + i);
    }
}

int interseccao(int *vetor_a, int *vetor_b, int *vetor_c) 
{
    // conjunto_a
    for (int i = 0; i < SIZE_VETOR; i++) {
        // conjunto_b
        for (int j = 0; j < SIZE_VETOR; j++) {
            if (vetor_a[i] == vetor_b[j]) {
                vetor_c[i] = vetor_a[i];
            }
        }
    }
}

int inicializa(int *vetor_a, int *vetor_b, int *vetor_c)
{
    vetor_a = (int *) malloc(VALOR_VAZIO_CONJUNTO * sizeof(int));
    vetor_b = (int *) malloc(VALOR_VAZIO_CONJUNTO * sizeof(int));
    vetor_c = (int *) malloc(VALOR_VAZIO_CONJUNTO * sizeof(int));
}

int limpar(int *vetor)
{
    for (int i = 0; i < (SIZE_VETOR + SIZE_VETOR); i++) {
        vetor_c[i] = VALOR_VAZIO_CONJUNTO;
    }
}
