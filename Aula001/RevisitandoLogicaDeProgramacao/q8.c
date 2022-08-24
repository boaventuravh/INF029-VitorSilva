// 8. Faça um programa que calcula o fatorial de um número

#include <stdio.h>

int main()
{
    int numero, fatorial = 1, i;
    
    printf("Digite um numero qualquer: ");
    scanf("%d", &numero);
    
    for (i=numero; i>1; i--)
        fatorial *= i;
    
    printf("\nO fatorial de %d eh igual a: %d", numero, fatorial);

    return 0;
}