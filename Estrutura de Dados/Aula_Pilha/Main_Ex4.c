#include <stdio.h>
typedef struct{
    int topo;
    char dados[10];
}stack;

void empilha(stack *pilha, char valor){
    if(pilha->topo == 9){
        printf("stack overflow");
    }else{
        pilha->dados[++pilha->topo] = valor;
    }
}

char desempilha(stack *pilha){
    if(pilha->topo == -1){
        printf("stack underflow");
    }else{
        return pilha->dados[pilha->topo--];
    }
}

int main(){
    stack pilha;
    pilha.topo = -1;
    char N = 'a';
    int contFechado = 0;
    int contAberto = 0;

    printf("Digite os valores da Pilha (Ate 10 letras)\nDigite as letras todas juntas e quando quiser parar digite um enter:\n");
    while(N != '\n' && pilha.topo <= 8){
        scanf("%c", &N);
        if(N != '\n'){
            empilha(&pilha, N);
        }
    }
    
    while(pilha.topo >=0){
        N = desempilha(&pilha);
        if(N == ')'){
            contFechado++;
        }
        if(N == '('){
            contAberto++;
            if(contFechado > 0){
                contAberto--;
                contFechado--;
            }
        }
    }

    if(contAberto == 0){
        printf("tudo certo");
    }else{
        printf("tudo errado");
    }

    return 0;
}