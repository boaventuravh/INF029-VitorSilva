#include <stdio.h>
#define QTDE 5


int main() {
  int idades[QTDE], media = 0, i, super = 0;
  
  for (i=0; i<QTDE; i++)
  {
    printf("\nDigite a idade da %dª pessoa : ", i+1);
    scanf("%d", &idades[i]);
  }
  
  for (i=0; i<QTDE; i++)
    media += idades[i];

  media/=QTDE;

  printf ("\nAs idades superiores a media entre os valores fornecidos sao: ");

  for(i=0;i<QTDE;i++)
  if (idades[i] > media)
  {
    printf ("\n%d anos", idades[i]);
    super += 1;
  }

  if (super == 0)
    printf("\nNao ha idade superiores a media!");
  return 0;
}