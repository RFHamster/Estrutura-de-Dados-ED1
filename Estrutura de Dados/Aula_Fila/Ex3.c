#include <stdio.h>

#define MAX 3

typedef struct{
    int item[MAX];
    int inicio,fim;
}Fila;

typedef struct{
    int item[MAX+MAX];
    int inicio,fim;
}FilaOrdenada;

void inicia2(FilaOrdenada *F){
    F->inicio = F->fim = 0;
}

void inicia(Fila *F){
    F->inicio = F->fim = 0;
}

int insere(Fila *F, int x){
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

int insere2(FilaOrdenada *F, int x){
    if(F->fim == (MAX+MAX)){
        return 0;
    }else{
        F->item[F->fim] = x;
        F->fim++;
        return 1;
    }
}

int remover2(FilaOrdenada *F, int *x){
    if(F->inicio == F->fim){
        return 0;
    }else{
        *x = F->item[F->inicio];
        for(int i = 0; i<MAX-1; i++){
            F->item[i] = F->item[i+i];
        }
        F->fim--;
        return 1;
    }
}

int main(){
    Fila fila1;
    Fila fila2;
    FilaOrdenada fila3;
    int retorno,valor1, valor2, retorno1, retorno2;
    inicia(&fila1);
    inicia(&fila2);
    inicia2(&fila3);

    for(int i = 0; i<MAX; i++){
        int valor;
        printf("Digite um numero inteiro para F1: \n");
        scanf("%d", &valor);
        retorno = insere(&fila1, valor);
        if(retorno == 1){
            printf("tudo certo \n");
        }else{
            printf("tudo errado\n");
        }
    }


    for(int i = 0; i<MAX; i++){
        int valor;
        printf("Digite um numero inteiro para F2: \n");
        scanf("%d", &valor);
        retorno = insere(&fila2, valor);
        if(retorno == 1){
            printf("tudo certo \n");
        }else{
            printf("tudo errado\n");
        }
    }


    retorno1 = Remove(&fila1, &valor1);
    retorno2 = Remove(&fila2, &valor2); //Tinha um erro aqui, a variavel que vc tinha colocado era valor1


    while(retorno1 != 0 || retorno2 != 0){
        if(retorno1 > retorno2){
            insere2(&fila3, valor1);
            retorno1 = Remove(&fila1,&valor1);

        }else if (retorno2 > retorno1){
            insere2(&fila3, valor2);
            retorno2 = Remove(&fila2, &valor2);
        }else if (retorno1 == 1 && retorno2 == 1){
            if(valor1 < valor2){
                insere2(&fila3, valor1);
                retorno1 = Remove(&fila1,&valor1);

            }else if (valor2 < valor1){
                insere2(&fila3, valor2);
                retorno2 = Remove(&fila2, &valor2);

            }else{
                insere2(&fila3, valor1);
                retorno1 = Remove(&fila1, &valor1);
            }
        }
    }

    printf("\n\n F3:");
    for(int i = 0; i < fila3.fim; i++){
        printf("%d ", fila3.item[i]);
    }


    return 0;
}