#include <stdio.h>
#include <stdlib.h>

struct cel {
    int dado;
    struct cel *prox;
};
typedef struct cel celula;

celula c;
celula *p;

void insere(int x, celula *p)
{
    celula *nova;
    
    nova = (celula *) malloc (sizeof(celula));
    nova->dado = x;
    nova->prox = p->prox;
    
    p->prox = nova;
}

void imprime(celula *ini)
{
    celula *p;

    for (p = ini->prox; p != NULL; p = p->prox) {
        printf ("%d\t", p->dado);
    }

    printf ("\n");
}

int main()
{
    p = (celula *) malloc (sizeof(celula));
    insere(1, p);
    insere(6, p);
    insere(9, p);
    insere(4, p);
    insere(8, p);
    insere(12, p);
    imprime(p);
 
    return EXIT_SUCCESS;
}