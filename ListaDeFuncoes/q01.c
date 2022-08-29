#include <stdio.h>

int soma();

int main(){
  
  int val1, val2, resultado;

  printf("Digite o primeiro valor: ");
  scanf("%d", &val1);
  printf("\nDigite o segundo valor: ");
  scanf("%d", &val2);
  
  resultado = soma(val1, val2);
  
  printf("\nA soma dos valores fornecidos eh: %d", resultado);

  return 0;
}

int soma(int a, int b)
{
  return a+b;
}