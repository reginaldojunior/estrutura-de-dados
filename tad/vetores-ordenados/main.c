#include <stdio.h>
#include <stdlib.h>

#include "conjunto.h"

int main(int argc, char *argv[])
{
    inicializa(vetor_a, vetor_b, vetor_c);
    
    printf("Entre com 5 números para preencher o vetor_a: \n");
    
    int num;
    for (int i = 0; i < SIZE_VETOR; i++) {
        printf("Digite: ");
        scanf("%d", &num);
        insere(vetor_a, num, i);
    }

    ordernar(vetor_a, SIZE_VETOR);
    printf("\n vetor_a: "); imprime(vetor_a, SIZE_VETOR);
    
    printf("Entre com 5 números para preencher o vetor_b: \n");

    for (int i = 0; i < SIZE_VETOR; i++) {
        printf("Digite: ");
        scanf("%d", &num);
        insere(vetor_b, num, i);
    }

    ordernar(vetor_b, SIZE_VETOR);
    printf("\n vetor_b: "); imprime(vetor_b, SIZE_VETOR);
    
    uniao(vetor_a, vetor_b, vetor_c);
    
    ordernar(vetor_c, 10);
    imprime(vetor_c, 10);

    limpar(vetor_c);

    interseccao(vetor_a, vetor_b, vetor_c);
    ordernar(vetor_c, 10);
    imprime(vetor_c, 5);

    return 0;
}
