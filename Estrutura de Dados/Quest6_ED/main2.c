#include <stdio.h>

void inverteVetor(int Vet[], int tamanho, int base){
    if(base>tamanho){
        return;
    }
    if(base != tamanho){
        int aux;
        aux = Vet[tamanho];
        Vet[tamanho] = Vet[base];
        Vet[base] = aux;
        base = base + 1;
        tamanho = tamanho - 1;
        inverteVetor(Vet, tamanho, base);
    }else{
        return;
    }
}


int main(){
    int tamanho = 0;
    int BASE = 0;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);

    int Vect[tamanho];
    for(int i = 0; i < tamanho; i++){
        printf("Digite o %d numero do vetor\n", i+1);
        scanf("%d", &Vect[i]);
    }
    inverteVetor(Vect, (tamanho-1), BASE);
    for(int i = 0; i < tamanho; i++){
        printf("O %d numero do vetor: %d\n", i+1, Vect[i]);
    }

}