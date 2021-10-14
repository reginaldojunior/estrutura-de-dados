#include <stdio.h>
#include "FilaDinamica.h"

int main() {
	TipoFila P;
	TipoItem item;

	CriaFila(&P);

	item.chave = 5;
	enfileira(&P, item);

	item.chave = 1;
	enfileira(&P, item);

	item.chave = 3;
	enfileira(&P, item);

	item.chave = 0;
	enfileira(&P, item);

	item.chave = 25;
	enfileira(&P, item);

	item.chave = -3;
	enfileira(&P, item);

	ImprimeFila(&P);
	
	item = frente(&P);
	printf("Topo = %d\n", item.chave);
	
	desenfileira(&P);
	desenfileira(&P);
	ImprimeFila(&P);

	item = frente(&P);
	printf("Topo = %d\n", item.chave);

	// while(!FilaVazia(&P)) {
	// 	desenfileira(&P);
	// }
}