#include <stdio.h>
#include <stdlib.h>

#include "ListaDinamica.h"

int main() {
    TipoLista L;
    TipoItem Item;
    TipoApontador P;
    
    CriaLista(&L);
    
    Item.chave = 5;
    Insere(&L, Item);

    Item.chave = 1;
    Insere(&L, Item);

    Item.chave = 7;
    Insere(&L, Item);

    Item.chave = 8;
    Insere(&L, Item);

    TipoChave chave = 987;
    Item.chave = 6;
    SubstituiItemPorChave(&L, chave, Item);

    ImprimeLista(&L);
    // ImprimeListaInvertida(&L);

    return 0;
}