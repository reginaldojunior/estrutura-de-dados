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
    TipoFila FF, aux1, aux2;

	for (int i = 0; i < N; i++) { // indica valores entre 1 à 100
        CriaPilha(&P);
        CriaFila(&FF);

		scanf("%d", &K);

        if (K < 2 || K > 100) {
            printf("impossivel 1\n");
            return 0;
        }
		
        CriaFila(&aux1);
		for (int j = 0; j < K; j++) { // indica os valores do caso de teste entre 2 a 100
			scanf(" %c %d", &C, &I);

            TipoItemFila auxF;
            auxF.chave = I;
            auxF.nome = C;

            enfileira(&aux1, auxF);
            
            if (C == 'i') {
                enfileira(&FF, auxF);
                
                TipoItemPilha auxP;
                auxP.chave = I;
                InserePilha(&P, auxP);
            }
		}

        TipoApontadorFila F = aux1.primeiro;

        int i = 0;
        while(F != NULL) {
            if (F->prox != NULL) {
                if (F->item.nome == 'r') {
                    TipoItemPilha pItem = UltimoPilha(&P);    
                    TipoItemFila fItem = frente(&FF);

                    if (pItem.chave == I && fItem.chave == I && tipoEstrutura != IMPOSSIVEL) {
                        desenfileira(&FF);
                        RemovePilha(&P);
                        tipoEstrutura = INDEFINIDO;
                    } else {
                        if (P.primeiro->prox != NULL) {
                            // printf("primeiro print / tipoEstrutura: %d pilha: %d: esperado=%d, atual=%d\n", tipoEstrutura, i, F->item.chave, pItem.chave);
                            if (F->item.chave == pItem.chave && tipoEstrutura != IMPOSSIVEL) {
                                RemovePilha(&P);
                                tipoEstrutura = PILHA;
                            }
                        }

                        // printf("segundo print / tipoEstrutura: %d fila: %d: esperado=%d, atual=%d\n", tipoEstrutura, i, F->item.chave, fItem.chave);
                        if (F->item.chave == fItem.chave && tipoEstrutura != IMPOSSIVEL) {
                            desenfileira(&FF);
                            tipoEstrutura = FILA;
                        }
                    }

                    // if (P.primeiro->prox == NULL &&
                    //     F->item.chave == fItem.chave &&
                    //     F->item.chave == pItem.chave) {
                    //     tipoEstrutura = INDEFINIDO;
                    // }
                }
            } else {
                if (F->item.nome == 'r') {
                    TipoItemPilha pItem = UltimoPilha(&P);    
                    TipoItemFila fItem = frente(&FF);

                    if (pItem.chave == I && fItem.chave == I) {
                        if (P.primeiro->prox == NULL && tipoEstrutura != IMPOSSIVEL) {
                            desenfileira(&FF);
                            RemovePilha(&P);
                            tipoEstrutura = INDEFINIDO;
                        }
                    } else {
                        if (P.primeiro->prox != NULL && tipoEstrutura != IMPOSSIVEL) {
                            // printf("terceiro print / tipoEstrutura: %d pilha: %d: esperado=%d, atual=%d\n", tipoEstrutura, i, F->item.chave, pItem.chave);
                            if (F->item.chave == pItem.chave) {
                                RemovePilha(&P);
                                tipoEstrutura = PILHA;
                            }
                        }

                        // printf("quarto print / tipoEstrutura: %d fila: %d: esperado=%d, atual=%d\n", tipoEstrutura, i, F->item.chave, fItem.chave);
                        if (F->item.chave == fItem.chave && tipoEstrutura != IMPOSSIVEL) {
                            desenfileira(&FF);
                            tipoEstrutura = FILA;
                        }
                    }
                }
                // printf("%d: chave=%d, Nome=%c Froximo=NULO\n", i, F->item.chave, F->item.nome);
            }
            
            F = F->prox;

            desenfileira(&aux1);
            i++;
        }
        // printf("countFila=%d, countPilha=%d, tipoEstrutura=%d\n", countFila, countPilha, tipoEstrutura);

        if (tipoEstrutura == IMPOSSIVEL) {
            printf("impossivel\n");    
        } else if (tipoEstrutura == PILHA) {
            printf("pilha\n");
        } else if (tipoEstrutura == FILA) {
            printf("fila\n");
        } else {
            printf("indefinido\n");
        }

        // printf("\n");
        tipoEstrutura = 0;
	}

    return 0;
}