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

int SubstituiItemPorChave(TipoLista *L, TipoChave C, TipoItem I)
{
    if (ListaVazia(L)) {
        return NAO_ENCONTROU;
    }

    TipoApontador p;
    int encontrou = 0;
    p = Pesquisa(L, C);

    if (p != NULL) {
        TipoItem old = p->Item;
        p->Item = I;
        Insere(L, old);
        encontrou = 1;
    }

    if (encontrou == 0) {
        return POSICAO_INVALIDA;
    }

    p = L->primeiro;
    while (p != NULL) {
        if (p->prox != NULL) {
            if (strcmp(p->Item.chave, p->prox->Item.chave) > 0) {
                printf("eu chego aqui?\n");
                TipoItem aux = p->Item;
                p->Item = p->prox->Item;
                p->prox->Item = aux;
            }
        }

        p = p->prox;
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
        free(P);

        return SEM_ERRO;
    }
    
    // remove do meio
    TipoApontador aux = L->primeiro;
    while (aux->prox != NULL && aux->prox != P) {
        aux = aux->prox;
    }

    aux->prox = P->prox;

    // remove do fim
    if (aux->prox == NULL) {
        L->ultimo = aux;
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
    char *string;
    // free(string);
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
    TipoApontador Apontador;
    
    CriaLista(&Lista);

	char acao, nome[10];
    int telefone;
    char *nome_temp;

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
        
        nome_temp = generate_string_memory(10, nome);
        // printf("%i: acao: %c, nome: %s, telefone: %d\n", i, acao, nome_temp, telefone);
        // printf("%i: acao: %c\n", i, acao);
        
        TipoItem Contato;
        Contato.chave = nome_temp;
        Contato.telefone = telefone;

        Apontador = Pesquisa(&Lista, nome_temp);

        if (acao == 'A') {     
            if (Apontador == NULL) {
                printf("Operacao invalida: contatinho nao encontrado\n");
                continue;
            }

            RemovePosicao(&Lista, Apontador);
            Insere(&Lista, Contato);

            continue;
        } 

        if (acao == 'P') {
            if (Apontador != NULL) {
                printf("Contatinho encontrado: telefone %d\n", Apontador->Item.telefone);
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

            Insere(&Lista, Contato);
            continue;
        }

        if (acao == 'R') {
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