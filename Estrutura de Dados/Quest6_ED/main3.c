#include <stdio.h>
#include <stdlib.h>

int fatDuplo(int x)
{
    int num = 1;
    int res;

    if(x == 1){
        return 1;
    }
    else{
        if(x > 0){
            return x * (fatDuplo(x - 2));
        }
    }
}

int main()
{
    int num, fatD;

    do{
        printf("\nNumero (impar maior que zero) que deseja ver o fatorial duplo: ");
        scanf("%d", &num);
    } while(num < 0 || num % 2 == 0);

    fatD = fatDuplo(num);

    printf("\nO fatorial duplo de %d e: %d", num, fatD);
    return 0;
}