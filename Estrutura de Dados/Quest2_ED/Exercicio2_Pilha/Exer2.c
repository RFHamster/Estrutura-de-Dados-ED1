#include <stdio.h>

typedef struct{
    char dados[10];
    int topo;
}stack;

void empilha(stack *pilha, char valor){
    if(pilha->topo == 9){
        printf("stack overflow\n");
    }else{
        pilha->dados[++pilha->topo] = valor;
    }
}

char desempilha(stack *pilha){
    if(pilha->topo == -1){
        printf("stack underflow\n");
        return 'c';
    }else{
        return pilha->dados[pilha->topo--];
    }
}

void copiaPilha(stack *p1, stack *p2){
    char aux;
    stack p3;
    p3.topo = -1;
    while(p1->topo > -1){
        aux = desempilha(p1);
        empilha(p2, aux);
        empilha(&p3, aux);
    }
    while(p3.topo > -1){
        aux = desempilha(&p3);
        empilha(p1, aux);
    }
}

int main (){
    stack p1;
    stack p2;
    p1.topo = -1;
    p2.topo = -1;
    char N;
    printf("Digite os valores da Pilha (Ate 10 letras)\nDigite as letras todas juntas e quando quiser parar digite um enter:\n");
    setbuf(NULL, stdin);
    while(p1.topo <=8 && N != '\n'){
        scanf("%c",&N);
        if(N != '\n'){
            empilha(&p1, N);
        }
        
    }

    copiaPilha(&p1, &p2);

    int palindromo = 1;
    if(p1.topo % 2 == 0){
        int limite = p1.topo/2;
        char aux1, aux2;
        for(int i = 0; i < limite; i++){
            aux1 = desempilha(&p1);
            aux2 = desempilha(&p2);
            if(aux1 != aux2){
                palindromo = 0;
            }
        }
    }else{
        int limite = p1.topo/2;
        limite += 1;
        char aux1, aux2;
        for(int i = 0; i < limite; i++){
            aux1 = desempilha(&p1);
            aux2 = desempilha(&p2);
            if(aux1 != aux2){
                palindromo = 0;
            }
        }
    }

    if(palindromo == 0){
        printf("Nao eh palindromo");
    }else{
        printf("Eh palindomo");
    }

    return 0;
}