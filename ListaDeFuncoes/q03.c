/*03. Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.*/

#include <stdio.h>

int fatorial(int fat);

int main (){
  int num, fat_main;

  printf("Digite um numero: ");
  scanf("%d", &num);

  fat_main = num;

  fat_main = fatorial(fat_main);

  if(fat_main == -1)
    printf("\nNao eh possivel calcular o fatorial de %d", num);
  else
    printf("\nO fatorial de %d eh: %d", num, fat_main);

  return 0;
}

int fatorial(int fat){
  int i;
  if (fat == 0 || fat == 1)
    return 1;
  else if (fat < 0)
    fat = -1;
  else
    for(i=fat-1;i>1;i--)
      fat*=i;
  return fat;
}