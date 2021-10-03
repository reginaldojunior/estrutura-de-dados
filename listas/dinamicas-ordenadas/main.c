#include <stdio.h>
#include <stdlib.h>

#include "ListaDinamica.h"

int main() {
    TipoLista L;
    TipoItem Item;
    TipoApontador P;
    
    CriaLista(&L);
    
    Item.chave = 5;
    Item.nome[25] = "Debora";
    Insere(&L, Item);

    Item.chave = 1;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    Item.chave = 7;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    Item.chave = 8;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    ImprimeLista(&L);
    OrdenaPorSelecao(&L);
    ImprimeLista(&L);

    // Remove(&L, 5);

    // ImprimeLista(&L);

    // Remove(&L, 5);

    // Item.chave = 1;
    // Item.nome[25] = "Reginaldo";
    // Insere(&L, Item);

    // Item.chave = 6;
    // Item.nome[25] = "Reginaldo";
    // Insere(&L, Item);

    // Item.chave = 97;
    // Item.nome[25] = "Reginaldo";
    // Insere(&L, Item);

    // Item.chave = 56;
    // Item.nome[25] = "Reginaldo";
    // Insere(&L, Item);

    // ImprimeLista(&L);
    // printf("Achou? %d \n", Pesquisa(&L, 3));
    // printf("Achou? %d \n", Pesquisa(&L, 7));
    // printf("Achou? %d \n", Pesquisa(&L, 1));

    return 0;
}