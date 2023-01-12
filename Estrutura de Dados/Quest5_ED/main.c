#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct elemento{
    int codigo;
    float valor;
    int quantidade;
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

int insereNo(Fila *fi, Elem *novo){
    if(fi == NULL){
        return 0;
    }
    novo->prox = NULL;

    if(fi->inicio == NULL){
        fi->inicio = novo;
    }else{
        fi->fim->prox = novo;
    }

    fi->fim = novo;
    return 1;
}

int insere_fila(Fila *fi){
    Elem *novo;
    if(fi == NULL){
        return 0;
    }
    novo = (Elem *) malloc (sizeof(Elem));
    if(novo == NULL){
        return 0;
    }

    int leitura;
    float valor;

    printf("Digite o codigo do produto\n");
    scanf("%d", &leitura);
    novo->codigo = leitura;
    printf("Digite o valor do produto\n");
    scanf("%f", &valor);
    novo->valor = valor;
    printf("Digite a quantidade do produto\n");
    scanf("%d", &leitura);
    novo->quantidade = leitura;

    insereNo(fi, novo);
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
        printf("Codigo: %d, %.2f reais com %d de quantidade\n", p->codigo, p->valor, p->quantidade);
        p = p->prox;
    }
}

Elem * removeFila(Fila *fi){
    Elem *no;

    if(fi->fim == NULL){
        return NULL;
    }

    no = fi->inicio;
    fi->inicio = fi->inicio->prox;

    if(fi->inicio == NULL){
        fi->fim = NULL;
    }
    return no;
}

int removeNulo(Fila *fi){
    if(fi->fim == NULL){
        return 0;
    }

    Elem *inicio;
    inicio = removeFila(fi);
    while(inicio != NULL && inicio->quantidade == 0){
        inicio = removeFila(fi);
    }
    if(inicio == NULL){
        return 1;
    }
    insereNo(fi, inicio);
    Elem *atual;
    atual = removeFila(fi);
    if(atual == inicio){
        insereNo(fi,inicio);
        return 1;
    }else if (atual->prox == inicio){
        if(atual->quantidade > 0){
            insereNo(fi, atual);
        }
        return 1;
    }
    do{
        if(atual->quantidade > 0){
            insereNo(fi, atual);
        }
        atual = removeFila(fi);
    }while(atual->prox != inicio);

    if(atual->quantidade > 0){
        insereNo(fi, atual);
    }
    return 1;
}

int alteraProduto(Fila *fi, int codigo){
    int retorno = 2;
    if(fi->fim == NULL){
        return 0;
    }
    if(fi->inicio->codigo == codigo){
        printf("Digite o novo valor\n");
        scanf("%f", &fi->inicio->valor);
        printf("Digite a nova quantidade\n");
        scanf("%d", &fi->inicio->quantidade);
        return 1;
    }
    Elem *inicio;
    inicio = removeFila(fi);
    insereNo(fi, inicio);
    Elem *atual;
    atual = removeFila(fi);
    do{
        if(atual->codigo == codigo){
            printf("Digite o novo valor\n");
            scanf("%f", &atual->valor);
            printf("Digite a nova quantidade\n");
            scanf("%d", &atual->quantidade);
            retorno = 1;
        }
        insereNo(fi, atual);
        atual = removeFila(fi);
    }while(atual->prox != inicio);
    if(atual->codigo == codigo){
        printf("Digite o novo valor\n");
        scanf("%f", &atual->valor);
        printf("Digite a nova quantidade\n");
        scanf("%d", &atual->quantidade);
        retorno = 1;
    }
    insereNo(fi, atual);
    return retorno;
}


void menu();

int main(){
    Fila *produtos;
    int saida;
    produtos = cria_fila();
    int escolha = 1;
    printf("limpa cls");
    while(escolha != 0){
        menu();
        scanf("%d", &escolha);
        switch(escolha){
        case 1:
            system("cls");
            saida = 0;
            printf("Digite um numero diferente de 0 para criar um novo produto\n");
            scanf("%d", &saida);
            while(saida != 0){
                insere_fila(produtos);
                printf("Digite um numero diferente de 0 para criar um novo produto\n");
                scanf("%d", &saida);
            }
        break;
        case 2:
            system("cls");
            imprimeFila(produtos);
            printf("Pressione ENTER para sair\n");
            getch();
        break;
        case 3:
            system("cls");
            saida = removeNulo(produtos);
            if(saida == 0){
                printf("Lista Vazia!\n");
            }else
                printf("Todos os produtos sem estoque removidos\n");
            printf("Pressione ENTER para sair\n");
            getch();
        break;
        case 4:
            system("cls");
            imprimeFila(produtos);
            printf("\n");
            printf("Digite o codigo do produto a ser alterado\n");
            int codigo;
            scanf("%d", &codigo);
            saida = alteraProduto(produtos, codigo);
            if(saida == 0){
                printf("Lista Vazia!\n");
            }else if (saida == 1){
                printf("Produtos atualizado\n");
            }else{
                printf("Produto inexistente\n");
            }
            printf("Pressione ENTER para sair\n");
            getch();
        break;
        default:
            escolha = 0;
        break;
        }
    }
    return 0;
}

void menu(){
    system("cls");
    printf("\n               MENU");
    printf("\nDigite uma opcao:\n1 - Cadastrar todos itens\n2 - Vizualizar itens cadastrados");
    printf("\n3 - Remover itens acabados\n4 - Alterar um item\n0 - Sair do programa\n");
}