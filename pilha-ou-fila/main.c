#include <stdio.h>
#include "PilhaDinamica.h"
#include "FilaDinamica.h"

#define FILA 1
#define PILHA 2
#define IMPOSSIVEL 3
#define INDEFINIDO 4

int main() {
	int N, K, I;
    int tipoEstrutura = 0; // tipo fila
    int countFila, countPilha, countIndefinido, countImpossivel;
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
            } else if (C == 'r') {
                TipoItemPilha pilhaRemovido = TopoPilha(&P);
                TipoItemFila filaRemovido = frente(&F);

                if (filaRemovido.chave == I) {
                    desenfileira(&F);

                    if (pilhaRemovido.chave == I) {
                        RemovePilha(&P);
                        tipoEstrutura = INDEFINIDO;
                        countIndefinido++;
                    } else {
                        tipoEstrutura = FILA;
                        countFila++;
                    }
                } else {
                    if (pilhaRemovido.chave == I) {
                        RemovePilha(&P);
                        tipoEstrutura = PILHA;
                        countPilha++;
                    } else {
                        tipoEstrutura = IMPOSSIVEL;
                        countImpossivel++;
                    }
                }
            }
		}

        printf("\t impossivel %d / pilha %d / fila %d / indefinido %d \n", countImpossivel, countPilha, countFila, countIndefinido);
        if (tipoEstrutura == IMPOSSIVEL) {
            printf("impossivel");
        } else if (tipoEstrutura == PILHA) {
            printf("pilha");
        } else if (tipoEstrutura == FILA) {
            printf("fila");
        } else {
            printf("indefinido");
        }

        printf("\n");
        tipoEstrutura = INDEFINIDO;
	}

    return 0;
}