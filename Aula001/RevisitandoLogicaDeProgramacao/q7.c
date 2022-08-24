// 07. Faça um programa que verifique se um número é primo

#include <stdio.h>

int main (){
  int numero, count, divisores = 0;
  /*Se um numero tiver mais de dois divisores, ele deixa de ser primo. Vamos ignorar os divisores elementares, que são o 1 e o próprio número. Por isso a variável divisores será inicializada com 0. Se essa variável for incrementada uma vez, já sabemos que o número não é primo*/
  printf("Digite um numero para verificarmos se eh primo: ");
  scanf("%d", &numero);
  for (count=2; (count <= numero/2) && (divisores == 0); count++)
    if (numero%count == 0)
      divisores++;
  
  if (divisores == 0 && numero != 1)
    printf("\nO numero eh primo!");
  else
    printf("\nO numero nao eh primo!");
  
  return 0;
}