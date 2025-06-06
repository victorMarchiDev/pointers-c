#include <stdio.h>
#include <stdlib.h>

/*
Lista encadeada simples
Armazena o valor e o endereço de memória do próximo

[ 11 -> 13 -> 17 -> 19 -> 22 -> 42 -> 50 -> 99 ]

    VALOR          END. MEM
----------------------------------
#    50    #     FF400/FF406     #
#    13    #     FF401/FF403     #
#    22    #     FF402/FF407     #
#    17    #     FF403/FF405     #
#    11    #     FF404/FF401     #
#    19    #     FF405/FF402     #
#    99    #     FF406/NULL      #
#    42    #     FF407/FF400     #
----------------------------------
*/


typedef struct No{
    int valor; // valor a ser armazenado
    struct No *prox; // apontar para o próximo nó
} No;

No* criarNo(int valor){
    No* novoNo = (No*) malloc (sizeof(No));
    if(novoNo == NULL){
        printf("Erro");
    }

    novoNo->valor = valor;
    novoNo->prox = NULL;

    return novoNo;
}

No* inserirNovoNo(No *fim, int valor){
   No* novoNo = criarNo(valor);
   novoNo->prox=fim;
   return novoNo;
}


void listarLista(No* listaCompleta){
    No* valorAtual = listaCompleta;
    printf("Lista completa: \n");
    

    while(valorAtual != NULL){
     printf("%d -> ", valorAtual->valor);   
     valorAtual = valorAtual->prox;
    }
    printf("NULL \n");
    
}

int main(){
    No *lista = NULL;

    lista = inserirNovoNo(lista, 30);
    lista = inserirNovoNo(lista, 20);
    lista = inserirNovoNo(lista, 10);
    listarLista(lista);

    return 0;
}