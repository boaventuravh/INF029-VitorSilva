/*02. Faça um programa que leia a idade de duas pessoas e imprima a soma das idades*/

#include <stdio.h>
#define QTDE_PESSOAS 2

int main (){

  int idades[QTDE_PESSOAS], i, soma=0;

  for (i=0;i<QTDE_PESSOAS;i++)
    {
      printf("\nDigite a idade da %dª pessoa: ", i+1);
      scanf("%d", &idades[i]);
      soma += idades[i];
    }
  
  printf("\nA soma das idades dessas pessoas eh igual a: %d anos", soma);
  return 0;
  }