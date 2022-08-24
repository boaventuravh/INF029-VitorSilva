/*6. Faça um programa que leia a idade de uma pessoa e informe se ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada*/

#include <stdio.h>
#define MAIORIDADE 18
#define LIMITE_INFERIOR 0

int main(){
  int idade = LIMITE_INFERIOR;
  while (idade >= LIMITE_INFERIOR)
   {
    printf("\nDigite sua idade: ");
    scanf("%d", &idade);
    if(idade >= MAIORIDADE)
      printf("\nMaior de idade!");
    else if (idade < MAIORIDADE && idade >= LIMITE_INFERIOR)
      printf("\nMenor de idade!");
    else
      printf("\nFinalizando o programa!");
   }  
  return 0;
}