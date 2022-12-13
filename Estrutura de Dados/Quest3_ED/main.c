#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

typedef struct no{
    char placa[8];
    char vaga[2];
    float horaEntrada;
    struct no *prox;
}Carro;

typedef struct no_des{
    char placa[8];
    float desconto;
    struct no_des *prox;
}Desconto;

float VALORHORA = 8;
float Pagamentos = 0;
float desconto = 2.0;

void linhas(){
    printf("\n------------------------------------");
}

int insere_listaDesconto(Desconto **lista, char placa[]){
    Desconto *novo = malloc(sizeof(Desconto));

    if(novo){
        linhas();
        printf("\n        Cadastrar Desconto");
        linhas();

        strcpy(novo->placa, placa);
        novo->desconto = desconto;
        desconto += 0.25;
        if(desconto > 8){
            desconto = 2.0;
        }
        novo->prox = NULL;

        if(*lista == NULL){
           novo->prox = NULL;
        }
        else{
            novo->prox = *lista;
        }
        *lista = novo;
        printf("\nDesconto cadastrado para placa %s de R$ %.2f\n", novo->placa, novo->desconto);
        return 1;
    }
    else{
        printf("\nNao foi possivel, memoria estourou");
        return 0;
    }
        
}

int insere_lista(Carro **lista){
    Carro *novo = malloc(sizeof(Carro));

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
           novo->prox = NULL;
        }
        else{
            novo->prox = *lista;
        }
        *lista = novo;
        return 1;
        
    }
    else{
        printf("\nNao foi possivel, memoria estourou");
        return 0;
    }
        
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

void lista_todosDesconto(Desconto *novo){
    printf("\nDesconto Aplicado:");
    printf("\n==============================================================");
    while(novo){
        printf("\nSaida (placa): %s com R$ %.2f de desconto", novo->placa, novo->desconto);

        novo = novo->prox;
    }
    printf("\n==============================================================\n");
}

void remove_lista(Carro **lista, char placa[]){
    Carro *p;
    Carro *q;
    p = (*lista)->prox;
    q = *lista;
    
    if(*lista == NULL){
        printf("Garagem sem Carros\n");
        return;
    }
    if(strcmp(placa, q->placa) == 0){
        *lista = (*lista)->prox;
        return;
    }else{
        int liberta = 1;
        while(liberta != 0){
            if(strcmp(placa, p->placa) == 0){
                q->prox = p->prox;
                free(p);
                liberta = 0;
            }else{
                p = p->prox;
                q = q->prox;
            }
        }
    }
}

float mostrarDesconto(Desconto *lista, char placa[]){
    Desconto *p;
    p = lista;
    while(p){
        if(strcmp(placa, p->placa) == 0){
            return p->desconto;
        }else{
            p = p->prox;
        }
    }
    return 0;
}

float mostrarHora(Carro *lista, char placa[]){
    Carro *p;
    p = lista;
    while(p){
        if(strcmp(placa, p->placa) == 0){    
            return p->horaEntrada;
        }else{
            p = p->prox;
        }
    }
    return 0;
}

void trocaString(char *str1, char *str2, size_t tamanho){
    static char aux[15];
    memcpy(aux, str1, tamanho);
    memcpy(str1, str2, tamanho);
    memcpy(str2, aux, tamanho);
}

void attLista(Carro *lista){
    Carro *p;
    p = lista;
    while(p){
        Carro *aux = p->prox;
        while(aux){
            if(p->horaEntrada < aux->horaEntrada){
                float hora_temp = p->horaEntrada;
                p->horaEntrada = aux->horaEntrada;
                aux->horaEntrada = hora_temp;
                trocaString(p->placa, aux->placa, 8);
                trocaString(p->vaga, aux->vaga, 2);
            }
            aux = aux->prox;
        }
        p = p->prox;
    }
}

void menu();

int main (){
    int op;
    int carrosGaragem = 0;
    int aux = 0;
    char placaCarro[8];
    Carro *garagem;
    Desconto *listaDesconto;
    listaDesconto = NULL;
    garagem = NULL;

    do{
        menu();
        printf("\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            aux = insere_lista(&garagem);
            if(aux == 1){
                carrosGaragem++;
            }
            break;

        case 2:
            system("cls");
            lista_todos(garagem);
            printf("Pressione ENTER para sair\n");
            getch();
            break;

        case 3:
            system("cls");
            int random = rand() % 2;
            Carro *auxiliar;
            auxiliar = garagem;
            listaDesconto = NULL;
            int i = 0;
            while(auxiliar != NULL){
                if((random % 2 == 0) & (i % 2 == 0)){
                    insere_listaDesconto(&listaDesconto, auxiliar->placa);
                }else if((random % 2 != 0) & (i % 2 != 0)){
                    insere_listaDesconto(&listaDesconto, auxiliar->placa);
                }
                i++;
                auxiliar = auxiliar->prox;
            }
            lista_todosDesconto(listaDesconto);
            printf("Digite ENTER para sair");
            getch();
            break;

        case 4:
            system("cls");
            printf("\nDigite a placa do veiculo a ser removido(7 caracteres): \n");
            setbuf(stdin, NULL);
            fgets(placaCarro, 8, stdin);
            float descontoCarro = mostrarDesconto(listaDesconto, placaCarro);
            printf("Digite a hora Atual: (HH MM)\n");
            float hora, minutos;
            scanf("%f", &hora);
            scanf("%f", &minutos);
            float horaAtual = hora + (minutos/60);
            float horaPassada = mostrarHora(garagem, placaCarro);
            if(truncf(horaPassada) != 0){
                if(horaAtual - horaPassada > 0){
                    Pagamentos += ((horaAtual - horaPassada) * VALORHORA) - descontoCarro;
                }else{
                    Pagamentos += ((horaAtual - horaPassada) * VALORHORA);
                }
                remove_lista(&garagem, placaCarro);
                printf("Pagamento Atualizado Total: R$ %.2f\n", Pagamentos);  
            }else{
                printf("Carro nao Cadastrado\n");
            }
            printf("Digite ENTER para sair");
            getch();
            break;

        case 5:
            attLista(garagem);
            printf("\nLista atualizada!!!\n");
            printf("Digite ENTER para sair");
            getch();
            break;

        default:
            if (op != 0){
                printf("\nValor invalido!\n");
            }
        }
        
    }while(op != 0);
    return 0;
}



void menu(){
    system("cls");
    linhas();
    printf("\n               MENU");
    linhas();
    printf("\nDigite uma opcao:\n1 - Cadastrar veiculo\n2 - Vizualizar veiculos cadastrados");
    printf("\n3 - Aplicar desconto (em metade dos veiculos)\n4 - Remover veiculo\n5 - Atualizar lista\n0 - Sair do programa");
}