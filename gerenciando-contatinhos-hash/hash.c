#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000

struct dados {
  int telefone;
  int chave;
};

typedef struct dados* dado;

int stringParaInt(char *string) {
    int tamanho, primeira, segunda;

    tamanho =  strlen(string);
    primeira = string[0];
    segunda = string[1];

    int resultado = (tamanho * primeira) + segunda;

    return resultado;
}

int hash(int valor) {
    return valor % SIZE;  
}

// dado *Pesquisa(dado tabela, int chave) {
//     return tabela[chave];
// }

int main() {
    char acao, nome[10];
    int telefone;

    dado tabelaContatos[SIZE];
    dado Apontador;

    int i = 0;
    
    while (i != -1) {
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
        // printf("%i: acao: %c, nome: %s, telefone: %d\n", i, acao, nome_temp, telefone);
        // printf("%i: acao: %c\n", i, acao);
        
        struct dados *item = (struct dados*) malloc(sizeof(struct dados));
        item->chave = hash_code;
        item->telefone = telefone;

        Apontador = tabelaContatos[hash_code];

        if (acao == 'A') {     
            if (Apontador == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }

            tabelaContatos[hash_code] = item;

            continue;
        }

        if (acao == 'P') {
            if (Apontador != NULL) {
                printf("Contatinho encontrado: telefone %d\n", Apontador->telefone);
                continue;
            }

            printf("Contatinho nao encontrado\n");
            continue;
        }

        if (acao == 'I') {
            if (Apontador != NULL) {
                printf("Contatinho ja inserido\n");
                continue;
            }

            tabelaContatos[hash_code] = item;
            continue;
        }

        if (acao == 'R') {
            if (Apontador == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }

            free(tabelaContatos[hash_code]);
            continue;
        }
    }

    return 0;
}