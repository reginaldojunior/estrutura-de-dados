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

    TipoPilha P;
    TipoFila F;

	for (int i = 0; i < N; i++) { // indica valores entre 1 à 100
        CriaPilha(&P);
        CriaFila(&F);

		scanf("%d", &K);

		for (int j = 0; j < K; j++) { // indica os valores do caso de teste entre 2 a 100
			scanf(" %c %d", &C, &I);

            if (C == 'i') {
                TipoItemPilha Ip;
                Ip.chave = I;
                TipoItemFila If;
                If.chave = I;

                InserePilha(&P, Ip);
                enfileira(&F, If);
            } else if (C == 'r') {
                TipoItemPilha pilhaRemovido = TopoPilha(&P);
                RemovePilha(&P);
                TipoItemFila filaRemovido = frente(&F);
                desenfileira(&F);

                if (pilhaRemovido.chave == I && itemNotFoundStack != 1) {
                    isStack++;
                } 

                if (filaRemovido.chave == I && itemNotFoundQueue != 1) {
                    isQueue++;
                }

                if (filaRemovido.chave == I && pilhaRemovido.chave == I) {
                    isNotDefinedMoreOneTime++;
                }

                if (pilhaRemovido.chave != I) { // invalida pilha
                    itemNotFoundStack = 1;
                }

                if (filaRemovido.chave != I) { // invalida fila
                    itemNotFoundQueue = 1;
                }
            }
		}

        // printf("isStack %d isQueue %d itemNotFoundQueue %d itemNotFoundStack %d isNotDefinedMoreOneTime %d\n", isStack, isQueue, itemNotFoundQueue, itemNotFoundStack, isNotDefinedMoreOneTime);
        if (isStack > isQueue) {
            if (itemNotFoundStack == 1) {
                printf("impossivel\n");   
            } else {
                printf("pilha\n");
            }
        } else if (isQueue > isStack) {
            if (itemNotFoundQueue == 1) {
                printf("impossivel\n");   
            } else {
                printf("fila\n");
            }
        } else if (isQueue == isStack && (itemNotFoundQueue > 0 || itemNotFoundStack > 0)) {
            printf("impossivel\n"); 
        } else {
            printf("indefinido\n");
        }

        isQueue = 0;
        isStack = 0;
        itemNotFoundStack = 0;
        itemNotFoundQueue = 0;
	}

    return 0;
}