#include <stdio.h>

#define MAX 30

typedef struct{
    int topo;
    int dados[10];
}stack;

void empilha(stack *pilha, int valor){
    if(pilha->topo == 9){
        printf("stack overflow");
    }else{
        pilha->dados[++pilha->topo] = valor;
    }
}

int desempilha(stack *pilha, int *x){
    if(pilha->topo == -1){
        printf("stack underflow");
        return 0;
    }else{
        *x = pilha->dados[pilha->topo--];
        return 1;
    }
}

typedef struct{
    int item[MAX];
    int inicio,fim;
}Fila;

void inicia(Fila *F){
    F->inicio = F->fim = 0;
}

int Insere(Fila *F, int x){
    if(F->fim == MAX){
        return 0;
    }else{
        F->item[F->fim] = x;
        F->fim++;
        return 1;
    }
}

int Remove(Fila *F,int *X)
{
	if((*F).inicio==(*F).fim)
		return 0;
	else
	{
	   *X = F->item[F->inicio];
	   for(int i=0; i<MAX-1; i++)
		   F->item[i] = F->item[i+1];
        F->fim--;
	   return 1;
       }
}

void inverteFila(Fila *F1, Fila *F2){
    stack pilha;
    pilha.topo = -1;
    int x;
    int r1 = Remove(F1, &x);
    while(r1 == 1){
        empilha(&pilha, x);
        r1 = Remove(F1, &x);
    }

    r1 = desempilha(&pilha, &x);
    while(r1 == 1){
        Insere(F2, x);
        r1 = desempilha(&pilha, &x);
    }

}

void ImprimeFila(Fila *F){
    printf("\n\nFila: ");
    for(int i = F->inicio; i<F->fim; i++){
        printf(" %d ", F->item[i]);
    }
    printf("\n");
}



int main(){
    Fila f1;
    Fila f2;
    inicia(&f1);
    inicia(&f2);
    printf("Digite os elementos da fila 1: (para parar digite -1)\n");
    int n;
    scanf("%d", &n);
    while(n != -1){
        Insere(&f1, n);
        scanf("%d", &n);
    }

    inverteFila(&f1, &f2);

    ImprimeFila(&f2);

    return 0;
}