#include <stdio.h>

int subtrai();

int main(){

  int val1, val2, val3, sub;
  
  printf("\nDigite o primeiro valor: ");
  scanf("%d", &val1);
  printf("\nDigite o segundo valor: ");
  scanf("%d", &val2);
  printf("\nDigite o terceiro valor: ");
  scanf("%d", &val3);

  sub = subtrai(val1, val2, val3);

  printf("\nA subtracao desses valores eh: %d", sub);

  return 0;
}

int subtrai(int a, int b, int c)
{
  return a-b-c;
}