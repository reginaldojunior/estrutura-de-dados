#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *prox;
};
typedef struct cel celula;

celula c;
celula *p;

void insere(int x, celula *p)
{
    celula *nova;
    
    nova = (celula *) malloc (sizeof(celula));
    nova->conteudo = x;
    nova->prox = p->prox;
    
    p->prox = nova;
}

celula busca(int x, celula *lst)
{
    celula *p;
    
    p = lst->prox;
    while (p != NULL && p->conteudo != x)
        p = p->prox;

    return *p;
}

void remove(celula *p)
{
    celula *lixo;

    lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
}

void imprime(celula *ini)
{
    celula *p;

    for (p = ini->prox; p != NULL; p = p->prox) {
        printf ("%d\t", p->conteudo);
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

    return EXIT_SUCCESS;
}