#include <stdio.h>

int somaSerie(int i, int j, int k){
    int Soma = 0;
    if(k == 0){
        return i;
    }
    if(i <= j){
        Soma = i;
        i = i+k;
        return Soma + somaSerie(i,j,k);
    }else{
        return 0;
    }
}

int main(){
    
    int i,j,k;
    printf("Digite o primeiro valor: \n");
    scanf("%d", &i);
    printf("Digite o segundo valor: \n");
    scanf("%d", &j);
    printf("Digite o incremento: \n");
    scanf("%d", &k);
    int Soma = somaSerie(i,j,k);
    printf("Soma: %d", Soma);
}