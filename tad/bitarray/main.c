#include <stdio.h>
#include <string.h>

#include "conjunto.h"

int main()
{
    t_conjunto A, B, C;
    t_elemento e;

    inicializar(A);
    inicializar(B);
    inicializar(C);

    insercao(2, A);
    insercao(22, A);
    insercao(65, A);

    remocao(65, A);

    insercao(10, A);
    insercao(20, A);
    insercao(30, A);
    insercao(40, A);


    insercao(50, B);
    insercao(60, B);
    insercao(70, B);
    insercao(80, B);
    insercao(10, B);

    imprimir(A);
    imprimir(B);

    uniao(A, B, C);

    imprimir(C);

    interseccao(A, B, C);

    imprimir(C);

    return 0;
}