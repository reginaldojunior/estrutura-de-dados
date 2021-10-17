#include <stdio.h>
#include "PilhaDinamica.h"
#include "FilaDinamica.h"

int main() {
	int N, K, I;
    int isQueue = 0; // tipo fila
    int isStack = 0; // tipo pilha
    int isNotDefinedMoreOneTime = 0;
    int itemNotFoundStack = 0;
    int itemNotFoundQueue = 0;
	char C;

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

		scanf("%d", &K);

        if (K < 2 || K > 100) {
            printf("impossivel 1\n");
            return 0;
        }
		
		for (int j = 0; j < K; j++) { // indica os valores do caso de teste entre 2 a 100
			scanf(" %c %d", &C, &I);

            if (C == 'i') {
                TipoItemPilha Ip;
                Ip.chave = I;
                TipoItemFila If;
                If.chave = I;

                InserePilha(&P, Ip);
                enfileira(&F, If);
                // printf("inserindo \n");
                // ImprimePilha(&P);
                // printf("\n\n");
            } else if (C == 'r') {
                // printf("removendo \n");
                // ImprimePilha(&P);
                // printf("\n\n");
                TipoItemPilha pilhaRemovido = TopoPilha(&P);
                RemovePilha(&P);
                TipoItemFila filaRemovido = frente(&F);
                desenfileira(&F);
                // printf("fila: %d, pilha: %d, esperado: %d \n", filaRemovido.chave, pilhaRemovido.chave, I);
                
                // if (isStack == isQueue && isQueue > 0 && isStack > 0) {
                //     isNotDefinedMoreOneTime++;
                // }
                
                if (pilhaRemovido.chave == I) {
                    isStack++;
                } 
                
                if (filaRemovido.chave == I) {
                    isQueue++;
                }

                if (isStack >= 1 && pilhaRemovido.chave != I) { // invalida pilha
                    itemNotFoundStack = 1;
                }

                if (isQueue >= 1 && filaRemovido.chave != I) { // invalida fila
                    itemNotFoundQueue = 1;
                } else if (isQueue >= 1 && filaRemovido.chave != I) { // invalida fila
                    isQueue = 0;
                }

                if (filaRemovido.chave == I && pilhaRemovido.chave == I) {
                    isNotDefinedMoreOneTime++;
                }
            }
		}
        
        // printf("isStack %d isQueue %d itemNotFoundQueue %d itemNotFoundStack %d isNotDefinedMoreOneTime %d\n", isStack, isQueue, itemNotFoundQueue, itemNotFoundStack, isNotDefinedMoreOneTime);
        if (isStack > isQueue) {
            if (itemNotFoundStack == 1) {
                printf("impossivel");   
            } else {
                printf("pilha");
            }
        } else if (isQueue > isStack) {
            if (itemNotFoundQueue == 1) {
                printf("impossivel");   
            } else {
                printf("fila");
            }
        } else if (isQueue == isStack && (itemNotFoundQueue > 0 || itemNotFoundStack > 0)) {
            printf("impossivel"); 
        } else {
            printf("indefinido");
        }

        printf("\n");
        isQueue = 0;
        isStack = 0;
        itemNotFoundStack = 0;
        itemNotFoundQueue = 0;
	}

    return 0;
}