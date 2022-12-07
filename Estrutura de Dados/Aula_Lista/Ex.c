#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dados;
    struct no *prox;
}noptr;

noptr *insereLista(noptr *lista, noptr *novo, int valor){
    novo->dados = valor;
    if(lista == NULL){
        novo->prox = NULL;
    }else{
        novo->prox = lista;
    }
    return novo;
}

void removeLista(noptr *lista){
    noptr *p;
    if(lista == NULL){
        printf("\nListaVazia");
        return;
    }else{
        while(lista != NULL){
            p = lista;
            printf("\nValor Removido: %d", p->dados);
            lista = p->prox;
            free(p);
        }
    }
}

void removeUltimo(noptr *lista){
    if(lista == NULL){
        printf("\nLista Vazia\n");
        return;
    }
    noptr *p;
    noptr *j;
    j = lista;
    p = lista;
    p = p->prox;
    if(j->prox == NULL){//se for null
        lista = NULL;
        free(p);
        return;
    }
    while(p){
        if(p->prox == NULL){//se for null
            printf("\n\n No removido: %d \n", p->dados);
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

void listaTodos(noptr *lista){
    if(lista == NULL){
        printf("\nLista Vazia\n");
        return;
    }
    noptr *p;
    p = lista;
    while(p != NULL){
        printf("\nSaida: %d", p->dados);
        p = p->prox;
    }
    printf("\n");
}

void concat(noptr *lista1, noptr *lista2){
    noptr *aux;
    aux = lista1;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = lista2;
    lista2 = NULL;
}

void inserePosition(noptr *lista, int valor, int posicao){
    noptr *novo;
    novo = (struct no *) malloc (sizeof(noptr));
    novo->dados = valor;
    if(posicao == 0){
        lista = insereLista(lista, novo, valor);
        return;
    }
    noptr *aux;
    aux = lista;
    int confere = 1;
    for(int i = 1; i<posicao; i++){
        if(aux->prox == NULL){
            if(i - posicao != 1){
                printf("\nLOCALIZACAO INEXISTENTE\n");
                confere = 0;
                i = posicao;
            }
        }else{
            aux = aux->prox;
        }
    }
    if(confere == 1){
        novo->prox = aux->prox;
        aux->prox = novo;
    }   
}

void insereValor(noptr *lista, int valor){
    printf("\nEscolha um valor da lista a baixo para colocar o valor na frente");
    listaTodos(lista);
    int valorPosicao;
    scanf("%d", &valorPosicao);

    noptr *novo;
    novo = (struct no *) malloc (sizeof(noptr));
    novo->dados = valor;
    noptr *aux;
    aux = lista;
    int confere = 1;
    while(aux->dados != valorPosicao && confere == 1){
        if(aux->prox == NULL){
            confere = 0;
        }else{
            aux = aux->prox;
        }
    }
    if(confere == 1){
        novo->prox = aux->prox;
        aux->prox = novo;
    }else{
        printf("\nVALOR INEXISTENTE!\n");
    }
}

void main(){
    noptr *lista1;
    noptr *lista2;
    lista1 = NULL;
    lista2 = NULL;
    noptr *info;
    noptr *info2;
    int recebe = -1;
    do{
        printf("Digite um Valor\n");
        scanf("%d", &recebe);
        if(recebe != 0){
            info = (struct no *) malloc (sizeof(noptr));
            info2 = (struct no *) malloc (sizeof(noptr));
            if(!info || !info2){
                printf("\nSem Memoria!!!!\n");
                return;
            }
            lista1 = insereLista(lista1, info, recebe);
            lista2 = insereLista(lista2, info2, recebe+1);
        }
    }while(recebe != 0);
    listaTodos(lista1);
    //listaTodos(lista2);
    removeLista(lista1);
    listaTodos(lista1);
    //listaTodos(lista2);


    return 0;
}
