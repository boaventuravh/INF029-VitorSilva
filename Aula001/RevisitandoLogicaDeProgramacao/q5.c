// 5. Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor

#include <stdio.h>
#define MAIORIDADE 18

int main (){
  
  int idade;

  printf("\nDigite sua idade (em anos): ");
  scanf("%d", &idade);
  while(idade < 0)
  {
    printf("\nIdade invalida! Tente novamente: ");      
    scanf("%d", &idade);
  }
  
  if(idade >= MAIORIDADE)
    printf("\nVoce eh maior de idade!");
  else
    printf("\nVoce eh menor de idade!");

  return 0;
}