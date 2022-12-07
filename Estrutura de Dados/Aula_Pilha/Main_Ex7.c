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

int copiaPilha(stack *p1, stack *p2){
    int aux;
    stack p3;
    p3.topo = -1;
    while(p1->topo > -1){
        aux = desempilha(p1);
        empilha(&p3, aux);
    }
    while(p3.topo > -1){
        aux = desempilha(&p3);
        empilha(p2, aux);
    }
}

int main (){
    stack p1;
    stack p2;
    p1.topo = -1;
    p2.topo = -1;
    int N = 0;
    int stop = 0;
    printf("Digite os valores da Pilha (Ate 10 valores):\n");
    while(stop != 1 && scanf("%d",&N) == 1){
        stop = empilha(&p1, N);
    }

    copiaPilha(&p1, &p2);

    for(int i = 0; i < 10;i++){
        printf("%d - %d\n", p1.dados[i], p2.dados[i]);
    }




    return 0;
}