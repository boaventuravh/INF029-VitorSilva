/*• Faça um programa que tenha uma função que troca o valor de
duas variáveis.*/

#include <stdio.h>

void troca(int *pV1, int *pV2, int v1, int v2);

int main()
{
    
    int val1 = 5;
    int val2 = -3;
    
    printf("\nval1: %d\nval2: %d", val1, val2);
    
    troca(&val1, &val2, val1, val2);
    
    printf("\nval1: %d\nval2: %d", val1, val2);

    return 0;
}

void troca(int *pV1, int *pV2, int v1, int v2)
{
    int aux;
    aux = v1;
    *pV1 = v2;
    *pV2 = aux;
}