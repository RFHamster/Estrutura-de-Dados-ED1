#include <stdio.h>
#include <conio.h>

#define maxAlunosCurso 30

typedef struct
{
    int numIns[maxAlunosCurso];
    int idade[maxAlunosCurso];
    float ponto[maxAlunosCurso];
    int codCurso[maxAlunosCurso];
} dados;


void addCurso(int codCurso, int numIns, int idade, float nota, dados *dados, int *alunos);
int menuPrincipal();
void classificadosCurso(dados dados, int alunos);

int main()
{
    dados matematica;
    dados geografia;
    dados fisica;
    dados letras;

    int alunosMatematica = maxAlunosCurso - 1;
    int alunosGeografia = maxAlunosCurso - 1;
    int alunosFisica = maxAlunosCurso - 1;
    int alunosLetras = maxAlunosCurso - 1;

    //tirando os lixos de memoria
    for(int i = 0; i < maxAlunosCurso; i++){
        matematica.idade[i] = 0;
        matematica.ponto[i] = 0;
        matematica.numIns[i] = 0;

        geografia.idade[i] = 0;
        geografia.ponto[i] = 0;
        geografia.numIns[i] = 0;

        fisica.idade[i] = 0;
        fisica.ponto[i] = 0;
        fisica.numIns[i] = 0;

        letras.numIns[i] = 0;
        letras.idade[i] = 0;
        letras.ponto[i] = 0;
    }

    

    int desliga = 2;
    while (desliga > 1)
    {
        int menuEscolha = menuPrincipal();
        int numIns = 1;
        switch (menuEscolha)
        {
        case 1: // Cadastrar os alunos
            system("cls");
            while (numIns >= 0)
            {
                printf("Digite o codigo de inscricao (-1 para cacelar)\n");
                scanf("%d", &numIns);
                if (numIns >= 0)
                {
                    printf("Digite o codigo de curso\n1 - Matematica\n2 - Geografia\n3 - Fisica\n4 - Letras\n");
                    int codCurso;
                    scanf("%d", &codCurso);
                    printf("Digite a Idade do Aluno\n");
                    int idade;
                    scanf("%d", &idade);
                    printf("Digite a Nota do Aluno\n");
                    float nota;
                    scanf("%f", &nota);
                    switch (codCurso)
                    {
                    case 1: // Matematica
                        addCurso(codCurso, numIns, idade, nota, &matematica, &alunosMatematica);
                        break;

                    case 2: // Geografia
                        addCurso(codCurso, numIns, idade, nota, &geografia, &alunosGeografia);
                        break;

                    case 3: // Fisica
                        addCurso(codCurso, numIns, idade, nota, &fisica, &alunosFisica);
                        break;

                    case 4: // Letras
                        addCurso(codCurso, numIns, idade, nota, &letras, &alunosLetras);
                        break;

                    default:
                        printf("Curso Inexistente\nPressione ENTER para sair...\n");
                        getch();
                        break;
                    }
                }
                else
                {
                    printf("Desligando o Cadastro...\nPressione ENTER para sair...\n");
                    getch();
                }
                system("cls");
            }
            break;

        case 2: // Relação candidato x vaga
            system("cls");
            printf("Digite o codigo de curso\n1 - Matematica\n2 - Geografia\n3 - Fisica\n4 - Letras\n");
            int codCurso;
            scanf("%d", &codCurso);
            switch (codCurso)
            {
            case 1: // Matemtica
                system("cls");
                printf("----------Classificados Matematica----------\n");
                classificadosCurso(matematica, alunosMatematica);
                break;

            case 2: // Geografia
                system("cls");
                printf("----------Classificados Geografia----------\n");
                classificadosCurso(geografia, alunosGeografia);
                break;

            case 3: // Fisica
                system("cls");
                printf("----------Classificados Fisica----------\n");
                classificadosCurso(fisica, alunosFisica);
                break;

            case 4: // Letras
                system("cls");
                printf("----------Classificados Letras----------\n");
                classificadosCurso(letras, alunosLetras);
                break;

            default:
                break;
            }
        break;

        default:
            printf("DESLIGANDO O SISTEMA...\n");
            desliga = 0;
        break;
        }
    }

    return 0;
}

int menuPrincipal()
{
    int numeroEscolha;
    system("cls");
    printf("-------------------------MENU-------------------------\n");
    printf("DIGITE 1 PARA CADASTRAR OS ALUNOS\n");
    printf("DIGITE 2 PARA CONSULTAR A RELACAO ALUNOSxCURSO\n");
    printf("DIGITE OUTRO NUMERO PARA DESLIGAR O SISTEMA\n");
    scanf("%d", &numeroEscolha);
    return numeroEscolha;
}

void classificadosCurso(dados dados, int alunos){
    int cont = 1;
    for (int i = maxAlunosCurso - 1; i >= alunos; i--)
    {
        printf("%d Lugar - id %d com a pontuacao de %.2f\n", cont, dados.numIns[i], dados.ponto[i]);
        cont++;
    }
    printf("\nPressione ENTER para sair...");
    getch();
}

void addCurso(int codCurso, int numIns, int idade, float nota, dados *dados, int *alunos)
{
    int aux = 0;
    float auxNota = 0.0;
    for (int i = maxAlunosCurso - 1; i >= *alunos; i--)
    {
        if (nota > dados->ponto[i])
        {
            dados->codCurso[i] = codCurso;

            aux = dados->numIns[i];
            dados->numIns[i] = numIns;
            numIns = aux;

            auxNota = dados->ponto[i];
            dados->ponto[i] = nota;
            nota = auxNota;

            aux = dados->idade[i];
            dados->idade[i] = idade;
            idade = aux;
        }
        else if (truncf(nota*100) == truncf(dados->ponto[i]*100) && idade > dados->idade[i])
        {
            dados->codCurso[i] = codCurso;

            aux = dados->numIns[i];
            dados->numIns[i] = numIns;
            numIns = aux;

            auxNota = dados->ponto[i];
            dados->ponto[i] = nota;
            nota = auxNota;
            
            aux = dados->idade[i];
            dados->idade[i] = idade;
            idade = aux;
        }
    }
    if (*alunos > 0)
    {
        *alunos = *alunos - 1;
    }
}