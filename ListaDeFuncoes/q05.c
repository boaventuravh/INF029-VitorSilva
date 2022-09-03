/*5. Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.*/

#include <stdio.h>
#define QTDE 4

typedef struct num
{
  int n1, n2, n3, n4;
}Numbers;

Numbers ler4numeros(Numbers func);

int main (){
  Numbers principal;
 
  principal = ler4numeros(principal);

  printf("\nEis os numeros digitados: \n%d\n%d\n%d\n%d", principal.n1,principal.n2,principal.n3,principal.n4);
  return 0;
}

Numbers ler4numeros(Numbers func)
{
  printf("\nDigite o primeiro numero: ");
  scanf("%d", &func.n1);
  printf("\nDigite o segundo numero: ");
  scanf("%d", &func.n2);
  printf("\nDigite o terceiro numero: ");
  scanf("%d", &func.n3);
  printf("\nDigite o quarto numero: ");
  scanf("%d", &func.n4);

  return func;
}