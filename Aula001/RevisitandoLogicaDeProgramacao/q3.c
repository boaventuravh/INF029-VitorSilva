/*3. Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas */

#include <stdio.h>
#define QTDE 3

int main ()
{
  int valores[QTDE], i;

  for (i=0; i < QTDE - 1; i++)
    {
      printf("\nDigite o %dº valor: ", i+1);
      scanf("%d", &valores[i]);
    }
  valores[2] = valores[0];
  valores[0] = valores[1];
  valores[1] = valores[2];
  printf("\nApos a inversao: ");
  for(i=0; i < QTDE - 1; i++)
    printf("\nO %dº valor eh: %d", i+1, valores[i]);

  return 0;
}