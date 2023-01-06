#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct elemento{
    int dados;
    struct elemento *prox;
}Elem;

typedef struct fila{
    struct elemento *inicio;
    struct elemento *fim;
}Fila;

Fila * cria_fila(){
    Fila *fi = (Fila *) malloc (sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

int insere_fila(Fila *fi, int valor){
    Elem *novo;
    if(fi == NULL){
        return 0;
    }
    novo = (Elem *) malloc (sizeof(Elem));
    if(novo == NULL){
        return 0;
    }

    novo->dados = valor;
    novo->prox = NULL;

    if(fi->inicio == NULL){
        fi->inicio = novo;
    }else{
        fi->fim->prox = novo;
    }

    fi->fim = novo;
    return 1;
}

void imprimeFila(Fila *fi){
    Elem *p = fi->inicio;
    printf("----------Fila----------\n");
    printf("Dados: \n");
    if(p == NULL){
        printf("Fila Vazia\n");
        return;
    }
    while(p){
        printf("%d\n", p->dados);
        p = p->prox;
    }
}

int removeFila(Fila *fi){
    Elem *no;
    int dado;

    if(fi->fim == NULL){
        return 0;
    }

    no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    dado = no->dados;

    if(fi->inicio == NULL){
        fi->fim = NULL;
    }
    free(no);
    return dado;
}
void menu();

int main (){
    Fila *f1;
    f1 = cria_fila();
    int aux, resp;
    
    if(f1 == NULL){ //!f1 tbm funciona
        printf("Erro na criacao");
        return 0;
    }
    int opcao = 0;
    do{
        menu();
        printf("\nDigite a opcao\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                system("cls");
                printf("\nDigite o novo valor para a fila F1\n");
                scanf("%d", &aux);
                resp = insere_fila(f1, aux);
                if(resp == 0){
                    printf("ERRO");
                }else{
                    printf("Inserido");
                }
                getch();
            break;
            case 2:
                system("cls");
                imprimeFila(f1);
                printf("Digite ENTER para sair\n");
                getch();
            break;
        }
    }while(opcao != 6);
    return 0;
}

void menu(){
    system("cls");
    printf("\n1 - Inserir elementos na Fila 1\n");
    printf("\n2 - Imprimir Fila 1\n");
    printf("\n6 - Finalizar\n");
}