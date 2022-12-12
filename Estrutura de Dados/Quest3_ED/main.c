#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct no{
    char placa[8];
    char vaga[2];
    float horaEntrada;
    struct no *prox;
}Carro;

Carro *inicio;

typedef struct no_des{
    char placa[8];
    char vaga[2];
    float desconto;
    struct no_des *prox;
}Desconto;

int Pagamentos = 0;

void insere_lista(Carro **lista){
    Carro *aux, *novo = malloc(sizeof(Carro));

    if(novo){
        linhas();
        printf("\n        Cadastrar veiculo");
        linhas();

        printf("\nDigite a placa (7 caracteres): ");
        setbuf(stdin, NULL);
        fgets(novo->placa, 8, stdin);           

        printf("\nDigite a vaga (Letra e Numero): ");
        setbuf(stdin, NULL);
        fgets(novo->vaga, 3, stdin);
            
        printf("\nDigite a hora de entrada (HH MM): ");
        float hora, minutos;
        scanf("%f", &hora);
        scanf("%f", &minutos);
        novo->horaEntrada = hora + (minutos/60);

        novo->prox = NULL;

        if(*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        
    }
    else
        printf("\nNao foi possivel, memoria estourou");
}

void lista_todos(Carro *novo)
{
    
    printf("\nNa garagem:");
    printf("\n==============================================================");
    float hora;
    float minutos;
    while(novo){
        hora = truncf(novo->horaEntrada);
        minutos  = (novo->horaEntrada - hora) * 60;
        printf("\nSaida (placa): %s na vaga %s ho horario %.0f %.0f", novo->placa, novo->vaga, hora, minutos);

        novo = novo->prox;
    }
    printf("\n==============================================================\n");
}

void remove_lista(Carro *p){

    if(inicio == NULL){
        return;
    }
    else{
        while(inicio != NULL){
            p = inicio;
            printf("\nCarro removido: %s", p->placa);
            inicio = p->prox;
            free(p);
        }
    }
}

void linhas();
void menu();

int main (){
    int op;

    Carro *garagem;
    garagem = NULL;

    do{
        menu();
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            insere_lista(&garagem);
            break;

        case 2:
            system("cls");
            lista_todos(garagem);
            printf("Pressione ENTER para sair\n");
            getch();
            break;
        case 3:
            printf("\nDesconto aplicado!!!\n");
        
        case 4:
            
            break;

        case 5:
            printf("\nLista atualizada!!!\n");
            break;
            
        default:
            if (op != 0){
                printf("\nValor invalido!\n");
            }
        }
        
    }while(op != 0);
    return 0;
}

void linhas(){
    printf("\n------------------------------------");
}

void menu(){
    system("cls");
    linhas();
    printf("\n               MENU");
    linhas();
    printf("\nDigite uma opcao:\n1 - Cadastrar veiculo\n2 - Vizualizar veiculos cadastrados");
    printf("\n3 - Aplicar desconto (em metade dos veiculos)\n4 - Remover veiculo\n5 - Atualizar lista\n0 - Sair do programa");
}