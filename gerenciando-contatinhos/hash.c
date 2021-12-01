#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct dados
{
    int info;
    struct dados *prox;
};

typedef struct dados Dados;
typedef Dados* Hash[SIZE];

int stringParaInt(char *string) {
    int tamanho, primeira, segunda; //Inteiros que representam o tamanho,
                                    //o código da primeira letra da string
                                    //e o código da segunda letra.
    tamanho =  strlen(string);      //Mede o tamanho da string
    primeira = string[0];           //Obtém o código da primeira letra
    segunda = string[1];            //Obtém o código da segunda letra
    int resultado = (tamanho * primeira) + segunda; //Função de transformação
    return resultado;  //Retorna número que representa a string
}

int hash(int valor) {
    return valor % SIZE;  
}

int main() {
    int i;
    char dado[50];
    int vetor[10]
    
    vetor[stringParaInt('abc')];
}