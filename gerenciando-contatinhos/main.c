#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#define SEM_ERRO 0
#define POSICAO_INVALIDA -1
#define NAO_ENCONTROU -2
#define LISTA_CHEIA -3

typedef char* TipoChave;
typedef struct {
    TipoChave chave;
    int telefone;
} TipoItem;

typedef struct TipoNo *TipoApontador;
typedef struct TipoNo {
    TipoItem Item;
    struct TipoNo *prox, *ant;
} TipoNo;

typedef struct {
    TipoApontador primeiro, ultimo;
} TipoLista;

void CriaLista(TipoLista *L);
int Insere(TipoLista *L, TipoItem I);
int Remove(TipoLista *L, TipoChave C);
int RemovePosicao(TipoLista *L, TipoApontador P);
TipoApontador Pesquisa(TipoLista *L, TipoChave C);

char ListaVazia(TipoLista *L);
char ListaCheia(TipoLista *L);

void ImprimeLista(TipoLista *L);
void ImprimeListaInvertida(TipoLista *L);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void CriaLista(TipoLista *L) 
{
    (*L).primeiro = NULL;
    (*L).ultimo = NULL;
}

int Insere(TipoLista *L, TipoItem I)
{
    TipoApontador p;

    p = (TipoApontador) malloc(sizeof(TipoNo));
    
    if (p == NULL) {
        printf("Lista está cheia. \n");

        return LISTA_CHEIA;
    }

    p->Item = I;
    p->ant = NULL;

    if (ListaVazia(L)) {
        L->primeiro = p;
        L->ultimo = p;

        p->prox = NULL;
    } else if (L->primeiro->Item.chave > I.chave) { // primeiro posicao
        p->prox = L->primeiro;
        L->primeiro->ant = p;
        L->primeiro = p;
    } else { // todos os demais
        TipoApontador aux;
        aux = L->primeiro;
        while (aux->prox != NULL && aux->prox->Item.chave < I.chave) {
            aux = aux->prox;
        }

        p->prox = aux->prox;
        p->ant = aux;
        aux->prox = p;

        if (p->prox != NULL)
            p->prox->ant = p;
    }

    return SEM_ERRO;
}

int RemovePosicao(TipoLista *L, TipoApontador P)
{
    if (P == NULL) {
        printf("Posição Invalida. \n");
        return POSICAO_INVALIDA;
    }

    // remove do inicio
    if (P == L->primeiro) {
        L->primeiro = L->primeiro->prox;
        L->primeiro->ant = NULL; 
        free(P);

        return SEM_ERRO;
    }

    P->ant->prox = P->prox;

    // remove do fim
    if (P == L->ultimo) {
        L->ultimo = P->ant;
    } else {
        P->prox->ant = P->ant;
    }

    free(P);
    return SEM_ERRO;
}

int Remove(TipoLista *L, TipoChave C)
{
    TipoApontador p = Pesquisa(L, C);
    
    int removido = RemovePosicao(L, p);
    
    if (removido == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    return SEM_ERRO;
}

TipoApontador Pesquisa(TipoLista *L, TipoChave C)
{
    TipoApontador p;

    p = L->primeiro;
    while (p != NULL) {
        if (strcmp(p->Item.chave, C) == 0) {
            return p;
        }

        p = p->prox;
    }

    return p;
}

char ListaVazia(TipoLista *L)
{
    return L->ultimo == NULL && L->primeiro == NULL;
}

char ListaCheia(TipoLista *L);

// void ImprimeLista(TipoLista *L)
// {
//     TipoApontador aux;
//     TipoApontador p = L->primeiro;

//     printf("Lista:\n");

//     int i = 0;
//     while (p != NULL) {
//         if (p->prox != NULL && p->ant != NULL) {
//             printf("\t %d: Nome=%s, Telefone=%d, Proximo=%d, Anterior=%d \n", i, p->Item.chave, p->Item.telefone, p->prox->Item.chave, p->ant->Item.chave);
//         } else if (p->prox == NULL && p->ant != NULL) {
//             printf("\t %d: Nome=%s, Telefone=%d, Proximo=NULO, Anterior=%d \n", i, p->Item.chave, p->Item.telefone, p->ant->Item.chave);
//         } else {
//             printf("\t %d: Nome=%s, Telefone=%d, Proximo=NULO, Anterior=NULO \n", i, p->Item.chave, p->Item.telefone);
//         }
//         p = p->prox;
//         i++;
//     }

//     printf("\n\n");
// }

char *generate_string_memory(size_t length, char *nome) {
    char *string = NULL;

    if (length) {
        string = malloc(sizeof(char) * (length + 1));
        int n;
        if (string) {
            for (n = 0; n < length; n++) {
                string[n] = nome[n];
            }

            string[length] = '\0';
        }
    }

    return string;
}

int main() {
    TipoLista Lista;
    TipoItem Contato;
    TipoApontador Apontador;
    
    CriaLista(&Lista);

	char acao[2], nome[10];
    int telefone;

    acao[2] = '1';
        
    // struct timeval  tv1, tv2;
    // gettimeofday(&tv1, NULL);
    
    while (strcmp(acao, "0") != 0) {
        scanf("%c", acao);

        if (strcmp(acao, "A") == 0) {
            scanf("%s %d", nome, &telefone);
            Apontador = Pesquisa(&Lista, nome);
     
            if (Apontador == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }
            
            RemovePosicao(&Lista, Apontador);

            Contato.chave = generate_string_memory(10, nome);
            Contato.telefone = telefone;
            Insere(&Lista, Contato);

            continue;
        } 

        if (strcmp(acao, "P") == 0) {
            scanf("%s", nome);
            Apontador = Pesquisa(&Lista, nome);

            if (Apontador != NULL) {
                printf("Contatinho encontrado: telefone %d\n", Apontador->Item.telefone);
                continue;
            }

            printf("Contatinho nao encontrado\n");
            continue;
        }

        if (strcmp(acao, "I") == 0) {
            scanf("%s %d", nome, &telefone);
            Apontador = Pesquisa(&Lista, nome);

            if (Apontador != NULL) {
                printf("Contatinho ja inserido\n");
                continue;
            }

            Contato.chave = generate_string_memory(10, nome);
            Contato.telefone = telefone;
            Insere(&Lista, Contato);
            continue;
        }

        if (strcmp(acao, "R") == 0) {
            scanf("%s", nome);
            Apontador = Pesquisa(&Lista, nome);

            if (Apontador == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }

            RemovePosicao(&Lista, Apontador);
            continue;
        }
    }

    return 0;
}