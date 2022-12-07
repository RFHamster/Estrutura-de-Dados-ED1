#include <stdio.h>

#define MAX 30

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

int Remove(Fila *F)
{
	if((*F).inicio==(*F).fim)
		return 0;
	else
	{
	   for(int i=0; i<MAX-1; i++)
		   F->item[i] = F->item[i+1];
        F->fim--;
	   return 1;
       }
}

void ImprimeFila(Fila *F){
    printf("\n\nFila: ");
    for(int i = F->inicio; i<F->fim; i++){
        printf(" %d ", F->item[i]);
    }
    printf("\n");
}

void contaFila(Fila *F1, Fila *F2){
    int r1 = 1, r2 = 2, cont1 = 0, cont2 = 0;
    while(r1 == 1 || r2 == 1){
        r1 = Remove(F1);
        r2 = Remove(F2);
        if(r1 == 1){
            cont1++;
        }
        if(r2 == 1){
            cont2++;
        }
    }
    if(cont1 > cont2){
        printf("Fila 1 eh maior\n");
    }else if(cont2 > cont1){
        printf("Fila 2 eh maior\n");
    }else{
        printf("Filas do mesmo tamanho\n");
    }
    
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
    printf("Digite os elementos da fila 2: (para parar digite -1)\n");
    scanf("%d", &n); 
    while(n != -1){
        Insere(&f2, n);
        scanf("%d", &n);    
    }
    contaFila(&f1, &f2);
    return 0;
}