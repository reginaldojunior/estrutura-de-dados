
#ifndef CONJUNTO_H
#define CONJUNTO_H

#define SIZE_VETOR 5
#define VALOR_VAZIO_CONJUNTO 0

int vetor_a[SIZE_VETOR];
int vetor_b[SIZE_VETOR];
int vetor_c[SIZE_VETOR];

int pertence(int *vetor, int value);
void imprime(int *vetor, int tamanho);
int insere(int *vetor, int value, int posicao);
int remove_item(int *vetor, int value);
int uniao(int *vetor_a, int *vetor_b, int *vetor_c) ;
int interseccao(int *vetor_a, int *vetor_b, int *vetor_c) ;
int inicializa(int *vetor_a, int *vetor_b, int *vetor_c);
int ordernar(int *vetor, int tamanho);
int limpar(int *vetor);

#endif