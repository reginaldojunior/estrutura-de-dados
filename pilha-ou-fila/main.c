#include <stdio.h>
#include "PilhaDinamica.h"
#include "FilaDinamica.h"

int main() {
	int N, K, I;
    int isQueue = 0; // tipo fila
    int isStack = 0; // tipo pilha
	char C;
    
    printf("\t Digite o valor de N entre 1 à 100: ");
	scanf("%d", &N);

    if (N < 1 || N > 100) {
        printf("impossivel\n");
        return 0;
    }

    TipoPilha P;
    TipoFila F;

	for (int i = 0; i < N; i++) { // indica valores entre 1 à 100
        CriaPilha(&P);
        CriaFila(&F);

        printf("\t Digite o valor de K entre 2 à 100: ");
		scanf("%d", &K);

        if (K < 2 || K > 100) {
            printf("impossivel\n");
            return 0;
        }
		
		for (int j = 0; j < K; j++) { // indica os valores do caso de teste entre 2 a 100
            printf("\nDigite os pares C / I: ");
			scanf(" %c %d", &C, &I);

            if (C == 'i') {
                TipoItemPilha Ip;
                Ip.chave = I;
                TipoItemFila If;
                If.chave = I;

                InserePilha(&P, Ip);
                enfileira(&F, If);
            } else if (C == 'r') {
                TipoItemPilha pilhaRemovido = RemovePilha(&P);
                TipoItemFila filaRemovido = desenfileira(&F);

                if (pilhaRemovido.chave == I && filaRemovido.chave == 1) {
                    isQueue = -1;
                    isStack = -1;
                } else {
                    if (pilhaRemovido.chave == I) {
                        isStack = 1;
                        printf("pilharemovido: %d \n", pilhaRemovido.chave);
                    } else if (filaRemovido.chave == I) {
                        isQueue = 1;
                        printf("filaremovido: %d \n", filaRemovido.chave);
                    }
                }
            }
		}

        if (isStack == 1 && isQueue == 1) {
            printf("\n\timpossivel\n");
        } else if (isStack == 1) {
            printf("\n\tpilha\n");
        } else if (isQueue == 1) {
            printf("\n\tfila\n");
        } else if (isStack == -1 && isQueue == -1) {
            printf("\n\tindefinido\n");
        }

        printf("\n");
        isQueue = 0;
        isStack = 0;
	}

    return 0;
}