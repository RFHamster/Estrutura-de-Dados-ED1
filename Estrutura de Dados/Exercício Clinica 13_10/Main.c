#include <stdio.h>

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

int main(){
    int numIndice = -1;
    int numeroEscolha = 0;
    paciente paciente[100];
    consulta consulta[300];
    int numConsulta = -1;

    while(1){
        numeroEscolha = 0;
        numeroEscolha = menuPrincipal();
        
        if(numeroEscolha == 5){
            break;
        }
        
        else if(numeroEscolha == 1){
            //Cadastrar
            printf("\n");
            numIndice++;
            cadastrarPaciente(&paciente[numIndice], numIndice);            
        }
        
        else if(numeroEscolha == 2){
            //Nova Cosulta
            printf("\n");
            printf("----------------ABRIR NOVA CONSULTA-----------------");

            printf("Pacientes Cadastrados\n");
            if(numIndice >= 0){
                for(int i = 0; i<=numIndice; i++){
                    printf("Cadastro %d - %s", paciente[i].codPac, paciente[i].nome);
                }
            }
            
            while(1){
                printf("Digite o Codigo do Paciente ou -1 para sair\n");
                int numPaciente = 0;
                scanf("%d", &numPaciente);
                if(numPaciente == -1){
                    break;
                }else if(numPaciente >= 0 && numPaciente <= numIndice){
                    printf("Criando Nova Consulta para o Paciente %d - %s", paciente[numPaciente].codPac, paciente[numPaciente].nome);
                    numConsulta++;
                    consulta[numConsulta].codConsulta = numConsulta;
                    consulta[numConsulta].codPac = paciente[numPaciente].codPac;
                    printf("Digite a Data da Consulta (DD MM AAAA)");
                    scanf("%d", &consulta[numConsulta].data.dia);
                    scanf("%d", &consulta[numConsulta].data.mes);
                    scanf("%d", &consulta[numConsulta].data.ano);


                    int cancela = 0;
                    for(int i = 0; i<numConsulta; i++){
                        if(numPaciente == consulta[i].codPac){
                            if(consulta[i].data.dia == consulta[numConsulta].data.dia && consulta[i].data.mes == consulta[numConsulta].data.mes && consulta[i].data.ano == consulta[numConsulta].data.ano){
                                printf("Paciente já possui consulta marcada esse dia");
                                cancela = 1;
                            }
                        }
                    }

                    if(cancela == 1){
                        numConsulta--;
                        break;
                    }
                    
                    printf("Digite o Horario da Consulta (HH MM SS)");
                    scanf("%d", &consulta[numConsulta].horario.hora);
                    scanf("%d", &consulta[numConsulta].horario.minutos);
                    scanf("%d", &consulta[numConsulta].horario.segundos);
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
            printf("\n");
            //printf
        
        }
        
        else if(numeroEscolha == 4){
            //Alterar dados de uma consulta
            printf("\n");

        }



    }

    return 0;
}

int menuPrincipal(){
    int numeroEscolha;
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