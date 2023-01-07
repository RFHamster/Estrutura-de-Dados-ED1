#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

typedef struct no{
    char nome[20];
    char placa[8];
    float horaEntrada;
    struct no *proximo;
    struct no *anterior;
}Carro;

float VALORHORA = 8;
float Pagamentos = 0;

    void insere_lista(Carro **inifunc, Carro *info){
        Carro *aux = *inifunc;
        float horas, minutos;
        printf("Digite o nome do condutor\n");
        setbuf(stdin, NULL);
        fgets(info->nome, 20, stdin);   
        printf("Digite a placa do carro\n");
        setbuf(stdin, NULL);
        fgets(info->placa, 8, stdin);
        setbuf(stdin, NULL);
        printf("Digite as horas e os minutos da entrada (HH MM)\n");
        scanf("%f", &horas);
        scanf("%f", &minutos);
        info->horaEntrada = horas + (minutos/60);
        info->anterior=NULL;

        if(*inifunc==NULL){
            info->proximo = NULL;
            *inifunc=info;
        }else{
            while(aux){
                if(strcmp(aux->nome,info->nome) > 0 || strcmp(aux->nome,info->nome) == 0){
                    info->proximo = aux;
                    info->anterior = aux->anterior;
                    if(aux->anterior == NULL){
                        aux->anterior = info;
                        *inifunc = info;
                    }else{
                        aux->anterior->proximo = info;
                        aux->anterior = info;
                    }
                    
                    return;
                }else{
                    if(aux->proximo == NULL){
                        info->anterior = aux;
                        aux->proximo = info;
                        info->proximo = NULL;
                        return;
                    }else{
                        aux = aux->proximo;
                    }
                }
            }
        }
    }

    void imprimeListaAZ(Carro *lista){
        if(lista==NULL){
            printf("\nLista Vazia!!!");
            return;
        }
        Carro *p;
        p = lista;
        float hora;
        float minutos;
        while(p){
            hora = truncf(p->horaEntrada);
            minutos  = (p->horaEntrada - hora) * 60;
            printf("\nSaida: O condutor(a) %s, com o carro de placa %s entrou as %.0f:%.0f\n", p->nome, p->placa, hora, minutos);
            p = p->proximo;
        }
        printf("\n");
    }

    void imprimeListaZA(Carro *lista){
        if(lista==NULL){
            printf("\nLista Vazia!!!");
            return;
        }
        Carro *p;
        p = lista;
        while(p->proximo != NULL){
            p = p->proximo;
        }
        float hora;
        float minutos;
        while(p){
            hora = truncf(p->horaEntrada);
            minutos  = (p->horaEntrada - hora) * 60;
            printf("\nSaida: O condutor(a) %s, com o carro de placa %s entrou as %.0f:%.0f", p->nome, p->placa, hora, minutos);
            p = p->anterior;
        }
        printf("\n");
    }

    void removeLista(Carro **lista, char placa[]){
        Carro *aux;
        aux = *lista;
        if(*lista == NULL){
            printf("GARAGEM VAZIA\n");
            return;
        }
        while(strcmp(aux->placa, placa) != 0){
            aux = aux->proximo;
            if(aux == NULL){
                printf("PLACA INEXISTENTE\n");
                return;
            }
        }
        if(aux->anterior == NULL && aux->proximo == NULL){
            *lista = NULL;
        }else{
            if(aux->anterior == NULL){
                *lista = aux->proximo;
                aux->proximo->anterior = NULL;
            }else if(aux->proximo == NULL){
                aux->anterior->proximo = NULL;
            }else{
                aux->anterior->proximo = aux->proximo;
                aux->proximo->anterior = aux->anterior;
            }
        }
        printf("Digite a hora de saida HH MM\n");
        float hora;
        float minutos;
        scanf("%f", &hora);
        scanf("%f", &minutos);
        float HoraTotal = hora + (minutos/60);
        HoraTotal = HoraTotal - aux->horaEntrada;
        Pagamentos = Pagamentos + (VALORHORA * HoraTotal);
        printf("Pagamento de %.2f reais efetuado\n", (VALORHORA * HoraTotal));
        printf("Pagamentos do dia = %.2f\n", Pagamentos);
        printf("Condutor %s da placa %s removido\n", aux->nome, aux->placa);
        free(aux);
    }

void menu();

int main(){
    Carro *garagem;
    garagem = NULL;
    int recebe = 1;
    Carro *info;
    int escolha = 1;
    while(escolha != 0){
        menu();
        scanf("%d", &escolha);
        switch (escolha){
        case 1:
            system("cls");
            recebe = 1;
            while(recebe != 0){
                printf("Digite 0 para parar de ler");
                scanf("%d", &recebe);
                if(recebe != 0){
                    info=(struct no *) malloc(sizeof(Carro));
                    if(!info){
                        printf("\nSem Memoria!!!");
                    }else{
                        insere_lista(&garagem, info);
                    }   
                }
                
            }
        break;
        case 2:
            system("cls");
            imprimeListaAZ(garagem);
            printf("Pressione ENTER para sair");
            getch();
        break;
        case 3:
            system("cls");
            imprimeListaZA(garagem);
            printf("Pressione ENTER para sair");
            getch();
        break;
        case 4:
            system("cls");
            printf("Digite a placa a ser removida\n");
            char placa[8];
            setbuf(stdin,NULL);
            fgets(placa,8,stdin);
            removeLista(&garagem, placa);
            printf("Pressione ENTER para sair");
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
    printf("\nDigite uma opcao:\n1 - Cadastrar todos veiculos\n2 - Vizualizar veiculos cadastrados (A-Z)");
    printf("\n3 - Vizualizar veiculos cadastrados (Z-A)\n4 - Remover veiculo\n0 - Sair do programa\n");
}