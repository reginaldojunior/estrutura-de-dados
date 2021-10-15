#include "FilaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaFila(TipoFila *F) {
	(*F).primeiro = NULL;
    (*F).ultimo = NULL;
}

int enfileira(TipoFila *F, TipoItemFila I) {

	TipoApontadorFila p;

	p = (TipoApontadorFila) malloc(sizeof(TipoNoFila));
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


TipoItemFila desenfileira(TipoFila *F) {
	TipoItemFila itemEmpty;
	if (FilaVazia(F)) {
		printf("Deu nao\n");
		return itemEmpty;
	}

	// unico elemento
	if (F->primeiro->prox == NULL) {
		free(F->primeiro);
		CriaFila(F);
		return itemEmpty;
	}

	// remove do inicio
	TipoApontadorFila p = F->primeiro;
	F->primeiro = F->primeiro->prox;

	return p->item;
}

TipoItemFila frente(TipoFila *F) {

	if (!FilaVazia(F)) {
		return F->primeiro->item;
	}
	TipoItemFila I;
	I.chave = -1;
	return I;

}

char FilaVazia(TipoFila *F) {
	return F->primeiro == NULL;
}
char FilaCheia(TipoFila *F);

void ImprimeFila(TipoFila *L)  {
    TipoApontadorFila F = L->primeiro;

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