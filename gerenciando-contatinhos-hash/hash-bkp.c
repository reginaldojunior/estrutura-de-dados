#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

struct dados {
  int telefone;
  int chave;
};

typedef struct dados* dado;

int stringParaInt(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return (valor & 0x7FFFFFFF);
}

int hash(int valor) {
    return (valor & 0x7FFFFFFF) % SIZE;
}

int insereHash_SemColisao(dado *p_dado, int chave, int telefone){
    if(p_dado == NULL)
        return 0;

    int pos = hash(chave);

    struct dados *item = (struct dados*) malloc(sizeof(struct dados));
    item->chave = chave;
    item->telefone = telefone;

    if(item == NULL)
        return 0;

    p_dado[pos] = item;
    
    return 1;
}

int main() {
    char acao, nome[10];
    int telefone;

    dado tabelaContatos[SIZE];
    dado Apontador;

    int i = 0;
    
    while (i != -1) {
        telefone = -1;

        fflush(stdout);
        i++;
            
        scanf("%c ", &acao);

        if (acao == '0') {
            i = -1;
            break;
        } else if (acao == 'R' || acao == 'P') {
            scanf("%s ", nome);
        } else {
            scanf("%s %d ", nome, &telefone);
        }
        
        int hash_code = hash(stringParaInt(nome));
        // printf("%i: acao: %c, nome: %s, hash-code: %d, telefone: %d\n", i, acao, nome, hash_code, telefone);
        // printf("%i: acao: %c\n", i, acao);
        
        Apontador = tabelaContatos[hash_code];

        if (acao == 'A') {     
            if (Apontador == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }
            
            insereHash_SemColisao(&tabelaContatos, nome, telefone);

            continue;
        }

        if (acao == 'P') {
            if (Apontador != NULL) {
                if (Apontador->telefone != -1) {
                    printf("Contatinho encontrado: telefone %d\n", Apontador->telefone);
                    continue;
                }
            }

            printf("Contatinho nao encontrado\n");
            continue;
        }

        if (acao == 'I') {
            if (Apontador != NULL) {
                printf("Contatinho ja inserido\n");
                continue;
            }

            insereHash_SemColisao(&tabelaContatos, nome, telefone);
            continue;
        }

        if (acao == 'R') {
            if (Apontador == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }

            insereHash_SemColisao(&tabelaContatos, nome, -1);
            continue;
        }
    }

    return 0;
}