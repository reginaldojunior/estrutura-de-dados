#include <stdio.h>
#include "PilhaDinamica.h"
#include "FilaDinamica.h"

int main() {
	int N, K, I;
	char C;
    
    printf("\t Digite o valor de N entre 1 à 100: ");
	scanf("%d", &N);

    if (N < 1 || N > 100) {
        printf("impossivel\n");
        return 0;
    }

    TipoPilha P;
    TipoFila F;
    CriaPilha(&P);
    CriaFila(&F);

	for (int i = 0; i < N; i++) { // indica valores entre 1 à 100
        printf("\t Digite o valor de K entre 2 à 100: ");
		scanf("%d", &K);

        if (K < 2 || K > 100) {
            printf("impossivel\n");
            return 0;
        }
		
		for (int j = 0; j < K; j++) { // indica os valores do caso de teste entre 2 a 100
            printf("\t Digite os pares C / I: ");
			scanf("%c %d", &C, &I);
            printf("\n");

            if (C == 'i') {
                TipoItemPilha Ip;
                Ip.chave = I;
                TipoItemFila If;
                If.chave = I;

                InserePilha(&P, Ip);
                enfileira(&F, If);
            } else if (C == 'r') {
                RemovePilha(&P);
                desenfileira(&F);
            }
		}

        ImprimePilha(&P);
        ImprimeFila(&F);
	}

    return 0;
}