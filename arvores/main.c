#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"

int main() {
    TipoNo A, B;
    TipoItem Item;
    TipoApontador P;
    
    Item.chave = 5;
    CriaArvore(&A, Item, NULL, NULL);
    
    Item.chave = 16;
    Insere(&A, Item);

    Item.chave = 10;
    Insere(&A, Item);

    printf("raiz %d\n", A.Item.chave);
    printf("direito %d\n", A.direito->Item.chave);
    printf("esquerdo %d\n", A.esquerdo->Item.chave);

    Item.chave = 11;
    Insere(&A, Item);

    // Item.chave = 10;
    // InsereParaDireita(&A, Item);

    Item.chave = 7;
    Insere(&A, Item);

    ImprimeArvore(&A);

    return 0;
}