#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dados;
    struct no *prox;
}noptr;

noptr *inicio;


void insereLista(noptr *novo, int valor){
    novo->dados = valor;
    if(inicio == NULL){
        novo->prox = NULL;
    }else{
        novo->prox = inicio;
    }
    inicio = novo;
}

void removeLista(){
    noptr *p;
    if(inicio == NULL){
        printf("\nListaVazia");
        return;
    }else{
        while(inicio != NULL){
            p = inicio;
            printf("\nValor Removido: %d", p->dados);
            inicio = p->prox;
            free(p);
        }
    }
}

void removeUltimo(){
    if(inicio == NULL){
        printf("\nLista Vazia\n");
        return;
    }
    noptr *p;
    noptr *j;
    j = inicio;
    p = inicio;
    p = p->prox;
    if(j->prox == NULL){//se for null
        inicio = NULL;
        free(p);
        return;
    }
    while(p){
        if(p->prox == NULL){//se for null
            p = p->prox;
            j->prox = NULL;
            free(p);
        }else{
            p = p->prox;
            j = j->prox;
        }
    }
    printf("\n");
}

void listaTodos(){
    if(inicio == NULL){
        printf("\nLista Vazia\n");
        return;
    }
    noptr *p;
    p = inicio;
    while(p != NULL){
        printf("\nSaida: %d", p->dados);
        p = p->prox;
    }
    printf("\n");
}

void main(){
    int recebe = -1;
    inicio = NULL;
    noptr *info;
    do{
        printf("Digite um Valor\n");
        scanf("%d", &recebe);
        if(recebe != 0){
            info = (struct no *) malloc (sizeof(noptr));
            if(!info){
                printf("\nSem Memoria!!!!\n");
                return;
            }
            insereLista(info, recebe);
        }
    }while(recebe != 0);
    listaTodos();
    removeLista();
    listaTodos();


    return 0;
}
