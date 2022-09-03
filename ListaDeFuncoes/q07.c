/*7) Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do usuário e retornar as três palavras. A função main deve imprimir essas três palavras*/

#include <stdio.h>
#include <string.h>
#define QTDE_PALAVRAS 3
#define MAX_DIG 256

void ler3palavras (char words[][MAX_DIG]);

int main(){
  char palavras[QTDE_PALAVRAS][MAX_DIG];
  int i;

  ler3palavras(palavras);

  for(i=0;i<QTDE_PALAVRAS;i++)
    printf("\n%dª palavra digitada: %s", i+1, palavras[i]);

  return 0;
}

void ler3palavras (char words[][MAX_DIG])
{
  int count;
  for(count=0;count<QTDE_PALAVRAS;count++)
    {
      fflush(stdin);
      printf("\nDigite a %dª palavra: ", count+1);
      fgets(words[count], MAX_DIG, stdin);
      words[count][strlen(words[count]) - 1] = '\0';
    }
}