// 4. Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar

#include <stdio.h>

int main () {

  int var1, var2;
  
  printf("Digite o valor da primeira variavel: ");
  scanf("%d", &var1);
  printf("\nDigite o valor da segunda variavel: ");
  scanf("%d", &var2);

  var1 += var2;
  var2 = var1 - var2;
  var1 -= var2;

  printf("\nApos a inversao:\nA primeira variavel eh: %d\nA segunda variavel eh: %d", var1, var2);
  
  return 0;
}