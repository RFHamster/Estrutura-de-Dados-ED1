#include <stdio.h>

typedef struct{
    int dados[10];
    int topo;
}stack;

int empilha(stack *pilha, int valor){
    if(pilha->topo == 9){
        printf("stack overflow\n");
        return 1;
    }else{
        pilha->dados[++pilha->topo] = valor;
        return 0;
    }
}

int desempilha(stack *pilha){
    if(pilha->topo == -1){
        printf("stack underflow\n");
        return (-1);
    }else{
        return pilha->dados[pilha->topo--];
    }
}

int main (){
    stack pilha;
    pilha.topo = -1;
    int N = 0;
    int stop = 0;
    printf("Digite os valores da Pilha (Ate 10 valores):\n");
    while(stop != 1 && scanf("%d",&N) == 1){
        stop = empilha(&pilha, N);
    }
    int maior, menor, cont = 0;
    float media;

    maior = desempilha(&pilha);
    menor = maior;
    media += menor;
    cont++;

    int aux = 0;
    while(aux != -1){
        aux = desempilha(&pilha);
        if(aux > maior && aux != -1){
            maior = aux;
            media += aux;
            cont++;
        }else if (aux < menor && aux != -1){
            menor = aux;
            media += aux;
            cont++;
        }
    }
    media = media/cont;
    printf("Maior: %d, Menor: %d, Media: %.2f\n", maior, menor, media);





    return 0;
}