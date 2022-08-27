// 9. Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.

#include <stdio.h>
#define QTDE 10

int main()
{
  int numeros[QTDE], primos[QTDE], i, j, k = 0, divisores, somaPrimos = 0;

  for (i=0; i<QTDE; i++)
  {
    printf("\nDigite o %dº numero: ", i+1);
    scanf("%d", &numeros[i]);
  }

  for (i=0; i<QTDE; i++)
  {
    divisores = 0;
    for (j=2; (j <= numeros[i]/2) && (divisores == 0); j++)
      if (numeros[i]%j == 0)
        divisores++;
  
    if (divisores == 0 && numeros[i] != 1)
    {
      primos[k] = numeros[i];
      somaPrimos += primos[k];
      k++;
    }
  }
  // ao final do laço acima, a variavel k tera o valor da quantidade de primos.

  printf("\nDentre os valores informados, esses sao os primos: ");

  for (i=0; i<k ;i++)
    printf("\n%d", primos[i]);

  printf("\nE a soma deles eh igual a: %d", somaPrimos);

  return 0;
  
}