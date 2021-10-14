#include "FilaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaFila(TipoFila *F) {
	(*F).primeiro = NULL;
    (*F).ultimo = NULL;

	printf("Eh nois!\n");
}

int enfileira(TipoFila *F, TipoItem I) {

	TipoApontador p;

	p = (TipoApontador) malloc(sizeof(TipoNo));
	if (p == NULL) {
		printf("Deu ruim... tá com memória lotada!\n");
		return FILA_CHEIA;
	}

    p->item = I;
    p->prox = NULL;

    if (FilaVazia(F)) {
        F->primeiro = p;
        F->ultimo = p;
    } else {
        F->ultimo->prox = p;
        F->ultimo = p;
    }
	
	return SEM_ERRO;

}


void desenfileira(TipoFila *F) {
	
	if (FilaVazia(F)) {
		printf("Deu nao\n");
		return;
	}

	// unico elemento
	if (F->primeiro->prox == NULL) {
		free(F->primeiro);
		CriaFila(F);
		return;
	}

	// remove do inicio
	TipoApontador p = F->primeiro;
	F->primeiro = F->primeiro->prox;
	free(p);

}

TipoItem frente(TipoFila *F) {

	if (!FilaVazia(F)) {
		return F->primeiro->item;
	}
	TipoItem I;
	I.chave = -1;
	return I;

}

char FilaVazia(TipoFila *F) {
	return F->primeiro == NULL;
}
char FilaCheia(TipoFila *F);

void ImprimeFila(TipoFila *L)  {
    TipoApontador F = L->primeiro;

	int i = 0;
	while(F != NULL) {
		if (F->prox != NULL)
			printf("%d: chave=%d, Froximo=%d\n", i, F->item.chave, F->prox->item.chave);
		else
			printf("%d: chave=%d, Froximo=NULO\n", i, F->item.chave);
		F = F->prox;
		i++;
	}
}