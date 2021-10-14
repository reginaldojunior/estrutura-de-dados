#include "PilhaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

void CriaPilha(TipoPilha *P) {
	(*P).primeiro = NULL;
	printf("Eh nois!\n");
}

int InserePilha(TipoPilha *P, TipoItemPilha I) {

	TipoApontadorPilha p;

	p = (TipoApontadorPilha) malloc(sizeof(TipoNoPilha));
	if (p == NULL) {
		printf("Deu ruim... tá com memória lotada!\n");
		return PILHA_CHEIA;
	}

	p->item = I;
	if (PilhaVazia(P)) {
		p->prox = NULL;
		P->primeiro = p;
	} else {
		p->prox = P->primeiro;
		P->primeiro = p;
	}
	
	return SEM_ERRO;

}


void RemovePilha(TipoPilha *P) {
	
	if (PilhaVazia(P)) {
		printf("Deu nao\n");
		return;
	}

	// unico elemento
	if (P->primeiro->prox == NULL) {
		free(P->primeiro);
		CriaPilha(P);
		return;
	}

	// remove do inicio
	TipoApontadorPilha p = P->primeiro;
	P->primeiro = P->primeiro->prox;
	free(p);

}

TipoItemPilha TopoPilha(TipoPilha *P) {

	if (!PilhaVazia(P)) {
		return P->primeiro->item;
	}
	TipoItemPilha I;
	I.chave = -1;
	return I;

}

char PilhaVazia(TipoPilha *P) {
	return P->primeiro == NULL;
}
char PilhaCheia(TipoPilha *P);

void ImprimePilha(TipoPilha *L)  {
        TipoApontadorPilha P = L->primeiro;

	int i = 0;
	while(P != NULL) {
		if (P->prox != NULL)
			printf("%d: chave=%d, Proximo=%d\n", i, P->item.chave, P->prox->item.chave);
		else
			printf("%d: chave=%d, Proximo=NULO\n", i, P->item.chave);
		P = P->prox;
		i++;
	}
}