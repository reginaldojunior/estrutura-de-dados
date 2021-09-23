#include <stdio.h>
#include <stdlib.h>

#include "conjunto.h"

int main(int argc, char *argv[])
{
    inicializa(vetor_a, vetor_b, vetor_c);

    insere(vetor_a, 10, 0);
    insere(vetor_a, 20, 1);
    insere(vetor_a, 14, 2);
    insere(vetor_a, 30, 2);
    insere(vetor_a, 16, 3);
    insere(vetor_a, 5, 4);

    insere(vetor_b, 10, 0);
    insere(vetor_b, 20, 1);
    insere(vetor_b, 30, 2);

    printf("a: "); imprime(vetor_a, 5);

    printf("\n");
    printf("b: "); imprime(vetor_b, 5);

    printf("\n\n");
    printf("uniao: "); 
    uniao(vetor_a, vetor_b, vetor_c);    
    imprime(vetor_c, 5);
    
    limpar(vetor_c);
    
    printf("\n");
    printf("interseccao: "); 
    interseccao(vetor_a, vetor_b, vetor_c);

    imprime(vetor_c, 5);
    
    printf("\n");
    return 0;
}
