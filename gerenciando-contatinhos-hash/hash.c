#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10000000

struct Contatos {
   int telefone;   
   int key;
};

struct Contatos* hash_table[SIZE];
struct Contatos* Contato;
struct Contatos* item;

int stringParaInt(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return (valor & 0x7FFFFFFF);
}

int hashCode(int key) {
   return key % SIZE;
}

struct Contatos *search(int key) {
    int chave_array = hashCode(key);  

    while(hash_table[chave_array] != NULL) {	
        if(hash_table[chave_array]->key == key)
            return hash_table[chave_array]; 

        ++chave_array;

        chave_array %= SIZE;
    }        
	
    return NULL;        
}

void insert(int key, int telefone) {
   struct Contatos *item = (struct Contatos*) malloc(sizeof(struct Contatos));
   item->telefone = telefone;  
   item->key = key;

   int chave_array = hashCode(key);

    while(hash_table[chave_array] != NULL && hash_table[chave_array]->key != -1) {
        ++chave_array;
        chave_array %= SIZE;
    }
	
    hash_table[chave_array] = item;
}

struct Contatos* delete(struct Contatos* item) {
   int key = item->key;

   int chave_array = hashCode(key);

   while(hash_table[chave_array] != NULL) {
	
      if(hash_table[chave_array]->key == key) {
         struct Contatos* temp = hash_table[chave_array]; 

         hash_table[chave_array] = Contato; 
         return temp;
      }

      ++chave_array;

      chave_array %= SIZE;
   }      
	
   return NULL;        
}

int main() {
    Contato = (struct Contatos*) malloc(sizeof(struct Contatos));
    Contato->telefone = -1;  
    Contato->key = -1; 

    int i = 0;
    char acao, nome[10];
    int telefone;
    
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

        int chave_alfabeto = nome[0];
        int key = stringParaInt(nome);
        item = search(key);

        if (acao == 'A') {
            if(item == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }
            
            delete(item);
            insert(key, telefone);

            continue;
        }

        if (acao == 'P') {
            if (item != NULL) {
                if (item->telefone != -1) {
                    printf("Contatinho encontrado: telefone %d\n", item->telefone);
                    continue;
                }
            }

            printf("Contatinho nao encontrado\n");
            continue;
        }

        if (acao == 'I') {
            if (item != NULL) {
                printf("Contatinho ja inserido\n");
                continue;
            }

            insert(key, telefone);
            continue;
        }

        if (acao == 'R') {
            if (item == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }

            delete(item);
            continue;
        }
    }
}