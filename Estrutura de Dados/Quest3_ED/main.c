struct no{
    char placa[8];
    char vaga[2];
    float horaEntrada;
    struct no *prox;
}Carro;

struct no{
    char placa[8];
    char vaga[2];
    float desconto;
    struct no *prox;
}Desconto;

int Pagamentos = 0;