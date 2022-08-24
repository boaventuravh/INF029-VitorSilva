#include <stdio.h>
#include <string.h>
#define QTDE 5
#define QTDE_CHAR 256

int main() {
  int idades[QTDE], media = 0, i, super = 0;
  char nomes[QTDE][QTDE_CHAR];
  
  for (i=0; i<QTDE; i++)
  {
    printf("\nDigite o nome da %dª pessoa(maximo de %d caracteres): ", i+1, QTDE_CHAR);
    fgets(nomes[i], QTDE_CHAR, stdin);
    nomes[i][strlen(nomes[i]) - 1] = '\0';
    printf("\nDigite a idade da %dª pessoa : ", i+1);
    scanf("%d", &idades[i]);
    getchar();   // esse getchar evita que o "\n" seja lido pelo fgets do próximo ciclo no loop
  }
  
  for (i=0; i<QTDE; i++)
    media += idades[i];

  media/=QTDE;

  printf ("\nAs pessoas com idades superiores a media entre os valores fornecidos sao: ");

  for(i=0;i<QTDE;i++)
  if (idades[i] > media)
  {
    printf ("\n%s, com %d anos", nomes[i], idades[i]);
    super += 1;
  }

  if (super == 0)
    printf("\nNao ha pessoas com idade superior a media!");
  return 0;
}