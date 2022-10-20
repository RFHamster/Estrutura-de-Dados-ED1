#include <stdio.h>
#include <conio.h>

typedef struct {
    int codPac;
    char nome[35];
    char telefone[15];
}paciente;

typedef struct {
    int hora;
    int minutos;
    int segundos;
}horario;

typedef struct {
    int dia;
    int mes;
    int ano;
}data;

typedef struct {
    int codConsulta;
    int codPac;
    horario horario;
    data data;
}consulta;

int menuPrincipal();
void cadastrarPaciente(paciente *paciente, int numIndice);
void pacientesCadastrados(paciente *paciente, int numIndice);
void consultaCadastrada(consulta *consulta, int numConsulta, int numPaciente);
void dataValida(consulta *consulta);
void horaValida(consulta *consulta);

int main(){
    int numIndice = -1;
    int numeroEscolha = 0;  
    paciente paciente[100];
    consulta consulta[300];
    int numConsulta = -1;
    int leitura = 0;
    int cancela = 0;

    while(1){
        numeroEscolha = 0;
        numeroEscolha = menuPrincipal();
        
        if(numeroEscolha == 5){
            system("cls");
            printf("Desligando o Sistema");
            break;
        }
        
        else if(numeroEscolha == 1){
            //Cadastrar
            system("cls");
            leitura = 0;
            printf("Digite 1 para cadastrar um novo paciente ou -1 para voltar ao menu\n");
            scanf("%d", &leitura);
            if(leitura == 1){
                numIndice++;
                cadastrarPaciente(&paciente[numIndice], numIndice);  
                printf("\nPaciente Cadastrado, pressione ENTER para voltar ao MENU\n");
                getch();
            }
        }
        
        else if(numeroEscolha == 2){
            //Nova Cosulta
            system("cls");
            printf("----------------ABRIR NOVA CONSULTA-----------------\n");

            pacientesCadastrados(paciente, numIndice);
            
            while(1){
                printf("Digite o Codigo do Paciente ou -1 para sair\n");
                int numPaciente = 0;
                scanf("%d", &numPaciente);
                if(numPaciente == -1){
                    break;
                }
                else if(numPaciente >= 0 && numPaciente <= numIndice){
                    printf("\nCriando Nova Consulta para o Paciente %d - %s", paciente[numPaciente].codPac, paciente[numPaciente].nome);
                    numConsulta++;
                    consulta[numConsulta].codConsulta = numConsulta;
                    consulta[numConsulta].codPac = paciente[numPaciente].codPac;

                    while(1){
                        printf("Digite a Data da Consulta (DD MM AAAA)\n");
                        scanf("%d", &consulta[numConsulta].data.dia);
                        scanf("%d", &consulta[numConsulta].data.mes);
                        scanf("%d", &consulta[numConsulta].data.ano);
                        dataValida(&consulta[numConsulta]);

                        cancela = 0;
                        for(int i = 0; i<numConsulta; i++){
                            if(numPaciente == consulta[i].codPac){
                                if(consulta[i].data.dia == consulta[numConsulta].data.dia && consulta[i].data.mes == consulta[numConsulta].data.mes && consulta[i].data.ano == consulta[numConsulta].data.ano){
                                    printf("ERRO!!!\nPACIENTE JA POSSUI CONSULTA NESSE DIA\n");
                                    printf("Se quiser mudar a data digite 1, se quiser voltar ao menu digite 2\n");
                                    leitura = 0;
                                    scanf("%d", &leitura);
                                    if(leitura == 1){
                                        cancela = 1;
                                    }else{
                                        cancela = 2;
                                        break;
                                    }
                                }
                            }
                        }
                        if(cancela != 1){
                            break;
                        }                            
                    }

                    if(cancela == 2){
                        numConsulta--;
                    }else{
                        printf("Digite o Horario da Consulta (HH MM SS)\n");
                        scanf("%d", &consulta[numConsulta].horario.hora);
                        scanf("%d", &consulta[numConsulta].horario.minutos);
                        scanf("%d", &consulta[numConsulta].horario.segundos);
                        horaValida(&consulta[numConsulta]);
                    }
                    break;
                }
                else{
                    printf("PACIENTE NAO EXISTE!\n");
                    printf("Digite 1 para criar um novo cadastro ou 2 para digitar outro codigo do paciente\n");
                    scanf("%d", &numPaciente);
                    if(numPaciente==1){
                        printf("\n");
                        numIndice++;
                        cadastrarPaciente(&paciente[numIndice], numIndice);
                        break;
                    }           
                }
            }        
        }
        
        else if(numeroEscolha == 3){
            //Cosultar atendimentos
            system("cls");
            pacientesCadastrados(paciente, numIndice);
            leitura = 0;
            printf("Digite o numero do paciente que deseja consultar os agendamentos\n");
            scanf("%d", &leitura);
            consultaCadastrada(consulta, numConsulta, leitura);
            printf("\nPressione ENTER para sair\n");
            getch();
            
        }
        
        else if(numeroEscolha == 4){
            //Alterar o horario de uma consulta
            system("cls");
            pacientesCadastrados(paciente, numIndice);
            leitura = 0;
            printf("Digite o numero do paciente que deseja alterar os agendamentos\n");
            scanf("%d", &leitura);
            consultaCadastrada(consulta, numConsulta, leitura);
            printf("Digite o numero da consulta a ser alterada\n");
            scanf("%d", &leitura);
            printf("Consulta %d - %d/%d/%d - %d:%d:%d sendo alterada\n", consulta[leitura].codConsulta, consulta[leitura].data.dia, consulta[leitura].data.mes, consulta[leitura].data.ano, consulta[leitura].horario.hora, consulta[leitura].horario.minutos, consulta[leitura].horario.segundos);
                   
            printf("Digite o novo Horario da Consulta (HH MM SS)\n");
            scanf("%d", &consulta[leitura].horario.hora);
            scanf("%d", &consulta[leitura].horario.minutos);
            scanf("%d", &consulta[leitura].horario.segundos);
            horaValida(&consulta[leitura]);

            printf("Consulta Alterada Pressione ENTER para voltar ao menu\n");
            getch();

        }
    }

    return 0;
}

void consultaCadastrada(consulta *consulta, int numConsulta, int numPaciente){
    printf("Consultas Agendadas:\n");
    int achado = 0;
    for(int i = 0; i<=numConsulta; i++){
        if(consulta[i].codPac == numPaciente){
            printf("Consulta %d - %d/%d/%d - %d:%d:%d\n", consulta[i].codConsulta, consulta[i].data.dia, consulta[i].data.mes, consulta[i].data.ano, consulta[i].horario.hora, consulta[i].horario.minutos, consulta[i].horario.segundos);
            achado = 1;
        }
    }
    if(achado == 0){
        printf("Nenhuma Consulta foi achado nesse Paciente ou Paciente nao existente\n");
    }
}

void pacientesCadastrados(paciente *paciente, int numIndice){
    printf("Pacientes Cadastrados\n");
    if(numIndice >= 0){
        for(int i = 0; i<=numIndice; i++){
            printf("Cadastro %d - %s", paciente[i].codPac, paciente[i].nome);
        }
    }
}

int menuPrincipal(){
    int numeroEscolha;
    system("cls");
    printf("-------------------------MENU-------------------------\n");
    printf("DIGITE 1 CADASTRAR UM NOVO PACIENTE\n");
    printf("DIGITE 2 PARA ENTRAR COM UMA NOVA CONSULTA\n");
    printf("DIGITE 3 PARA CONSULTAR TODOS AGENDAMENTOS\n");
    printf("DIGITE 4 PARA ALTERAR OS DADOS DE UMA CONSULTA\n");
    printf("DIGITE 5 PARA DESLIGAR O SISTEMA\n");
    scanf("%d", &numeroEscolha);
    return numeroEscolha;
}

void cadastrarPaciente(paciente *paciente, int numIndice){
    paciente->codPac = numIndice;
    printf("----------------CADASTRO DE PACIENTE----------------\nCodigo do Paciente = %d\n\n", numIndice);
        
    printf("Digite o Nome do Paciente\n");
    setbuf(stdin, NULL);
    fgets(paciente->nome, 35, stdin);

    printf("Digite o Numero do Paciente (DDD) xxxxx-xxxx\n");
    setbuf(stdin, NULL);
    fgets(paciente->telefone, 15, stdin);
    printf("\n");
}

void dataValida(consulta *consulta){
    int d, m, a;
    int valida = 0;
    int day = 0, month = 0, year = 0;

    while(valida == 0){
        if(consulta->data.dia > 30 || consulta->data.dia < 1){
            printf("Dia Invalido! Digite Novamente\n");
            scanf("%d", &d);
            (*consulta).data.dia = d;
            if(consulta->data.dia > 30 || consulta->data.dia < 1){
                valida = 0;
            }else{
                valida = 1;
            }
        }else{
            day = 1;
        }
        if(consulta->data.mes > 12 || consulta->data.mes < 1){
            printf("Mes Invalido! Digite Novamente\n");
            scanf("%d", &m);
            (*consulta).data.mes = m;
            if(consulta->data.mes > 12 || consulta->data.mes < 1){
                valida = 0;            
            }else{
                valida = 1;
            }
        }else{
            month = 1;
        }
        if(consulta->data.ano < 2022){
            valida = 0;
            printf("Ano Invalido! Digite Novamente\n");
            scanf("%d", &a);
            (*consulta).data.ano = a;
            if(consulta->data.ano < 2022){
                valida = 0;
            }else{
                valida = 1;
            }
        }else{
            year = 1;
        }

        if(day == 1 && month == 1 && year == 1){
            valida = 1;
        }
    }
}

void horaValida(consulta *consulta){
    int h, m, s;
    int valida = 0;
    int seg = 0, min = 0, hour = 0;

    while(valida == 0){
        if(consulta->horario.segundos > 60 || consulta->data.dia < 1){
            printf("Segundos Invalido! Digite Novamente\n");
            scanf("%d", &s);
            (*consulta).horario.segundos = s;
            if(consulta->horario.segundos > 60 || consulta->data.dia < 1){
                valida = 0;
            }else{
                valida = 1;
            }
        }else{
            seg = 1;
        }
        if(consulta->horario.minutos > 60 || consulta->horario.minutos < 1){
            printf("Minuto Invalido! Digite Novamente\n");
            scanf("%d", &m);
            (*consulta).horario.minutos = m;
            if(consulta->horario.minutos > 60 || consulta->horario.minutos < 1){
                valida = 0;
            }else{
                valida = 1;
            }
        }else{
            min = 1;
        }
        if(consulta->horario.hora > 24 || consulta->horario.hora < 1){
            printf("Hora Invalida! Digite Novamente\n");
            scanf("%d", &h);
            (*consulta).horario.hora = h;
            if(consulta->horario.hora > 24 || consulta->horario.hora < 1){
                valida = 0;
            }else{
                valida = 1;
            }
        }else{
            hour = 1;
        }

        if(seg == 1 && min == 1 && hour == 1){
            valida = 1;
        }
    }
}
