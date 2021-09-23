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

    Item.chave = 1;
    Item.nome[25] = "Reginaldo";
    Insere(&L, Item);

    ImprimeLista(&L);

    return 0;
}