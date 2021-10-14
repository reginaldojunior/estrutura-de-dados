#include <stdio.h>
#include <stdlib.h>

#include "PilhaEstatica.h"

int main() {
    TipoPilha P;
    TipoItem Item;
    
    CriaPilha(&P);
    
    // Item.chave = 5;
    // Insere(&P, Item);

    // Item.chave = 6;
    // Insere(&P, Item);

    // Item.chave = 7;
    // Insere(&P, Item);

    // ImprimePilha(&P);

    // printf("TopoPilha: %d \n", TopoPilha(&P));

    // Remove(&P);

    // ImprimePilha(&P);
    // Remove(&P);
    // Remove(&P);
    // ImprimePilha(&P);

    BalanceamentoParenteses(&P);

    return 0;
}