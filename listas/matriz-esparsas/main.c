#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct tempNo {
    int valor;
    int coluna;
    struct tempNo* prox;
} NO;

typedef NO* PONT;

typedef struct {
    PONT* A;
    int linhas;
    int colunas;
} MATRIZ;

void InicializaMatriz(MATRIZ* m, int linhas, int colunas)
{
    int i;
    m->linhas = linhas;
    m->colunas = colunas;
    m->A = (PONT*) malloc(linhas * sizeof(PONT));
    for (i = 0; i < linhas; i++) m->A[i] = NULL;
}

int AtribuiMatriz(MATRIZ* m, int linha, int coluna, int valor)
{
    if (linha < 0 || linha >= m->linhas ||
        coluna < 0 || coluna >= m->colunas) return -1;

    PONT ant = NULL;
    PONT atual = m->A[linha];

    while (atual != NULL && atual->coluna < coluna) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->coluna == coluna) {
        atual->valor = valor;
    } else {
        PONT novo = (PONT) malloc(sizeof(NO));
        novo->coluna = coluna;
        novo->valor = valor;
        novo->prox = atual;

        if (ant == NULL) m->A[linha] = novo;
    }
    
    return 1;
}

int RemocaoMatriz(MATRIZ* m, int linha, int coluna)
{
    if (linha < 0 || linha >= m->linhas ||
        coluna < 0 || coluna >= m->colunas) return -1;

    PONT ant = NULL;
    PONT atual = m->A[linha];

    while (atual != NULL && atual->coluna < coluna) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->coluna == coluna) {
        if (ant == NULL) m->A[linha] = atual->prox;
        else ant->prox = atual->prox;
        free(atual);
    }
}

int AcessaValor(MATRIZ* m, int linha, int coluna)
{
    if (linha < 0 || linha >= m->linhas ||
        coluna < 0 || coluna >= m->colunas) return -1;

    PONT atual = m->A[linha];

    while(atual != NULL && atual->coluna < coluna)
        atual = atual->prox;

    if (atual != NULL && atual->coluna == coluna)
        return atual->valor;

    return -1;
}

int main() 
{
    MATRIZ matriz;

    InicializaMatriz(&matriz, 10, 10);
    AtribuiMatriz(&matriz, 0, 0, 99);
    AtribuiMatriz(&matriz, 7, 6, 59);
    printf("\n %d", AcessaValor(&matriz, 7, 6));
    RemocaoMatriz(&matriz, 7, 6);
    printf("\n %d", AcessaValor(&matriz, 7, 6));

    return 0;
}