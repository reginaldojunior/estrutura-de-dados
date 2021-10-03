#include <stdio.h>
#include <stdlib.h>

#include "ListaEstatica.h"

int main() {
    TipoLista L;
    TipoItem Item;
    TipoApontador P;
    
    CriaLista(&L);
    
    Item.chave = 5;
    Item.nome[25] = "Debora";
    Insere(&L, Item);

    Item.chave = 8;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    Item.chave = 7;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    Item.chave = 65;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    Item.chave = 8;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    ImprimeLista(&L);

    RemoveTodasAsChaves(&L, 8);

    ImprimeLista(&L);

    return 0;
}