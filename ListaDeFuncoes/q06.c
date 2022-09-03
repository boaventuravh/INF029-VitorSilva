/*6) Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário e retornar as três letras. A função main deve imprimir essas três letras*/

#include <stdio.h>
#define QTDE 3

void ler3letras(char letras[]);

int main(){
  int i;
  char letrasMain[QTDE];

  ler3letras(letrasMain);

  for(i=0;i<QTDE;i++)
    printf("\n%dª letra digitada: %c", i+1, letrasMain[i]);

  return 0;
}

void ler3letras(char letras[])
{
  int count;
  for(count=0;count<QTDE;count++)
    {
      printf("\nDigite a %dª letra: ", count+1);
      scanf("%c", &letras[count]);
      getchar();
    }
}