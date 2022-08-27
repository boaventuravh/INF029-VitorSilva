// 10. Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.

#include <stdio.h>
#include <string.h>
#define MAX_CHAR 256
#define QTDE_PESSOAS 2

int main(){

  struct ficha_das_pessoas
  {
  char nome[MAX_CHAR], cpf[12], sexo;
  int idade;
  }ficha[QTDE_PESSOAS];

  int i, j, invalidez_cpf = 0;

  for(i=0;i<QTDE_PESSOAS;i++)
    {
      fflush(stdin);  // COMO FUNCIONA ESSE fflush?
      printf("\nDigite o nome da %dª pessoa (maximo de %d caracteres): ", i+1, MAX_CHAR);
      fgets(ficha[i].nome, MAX_CHAR, stdin);
      ficha[i].nome[strlen(ficha[i].nome) - 1] = '\0';
      printf("\nDigite a idade dessa pessoa: ");
      scanf("%d", &ficha[i].idade);
      getchar();
      printf("\nDigite o sexo da %dª pessoa (F para feminino/M para masculino): ", i+1);
      ficha[i].sexo = getchar(); // TEM ALGUM PROBLEMA NESSA ENTRADA!!
      getchar();
      while(ficha[i].sexo != 'F' && ficha[i].sexo != 'M' && ficha[i].sexo != 'f' && ficha[i].sexo != 'm')
      {
        printf("\nDado invalido! Tente novamente:");
        ficha[i].sexo = getchar();
        getchar();
      }
      printf("\nDigite o cpf da %dª (11 digitos, apenas numeros): ", i+1);
      scanf("%s", ficha[i].cpf);
      getchar();
      for (j=0; ficha[i].cpf[j] != '\0'; j++)
        if(ficha[i].cpf[j] < '0' || ficha[i].cpf[j] > '9')
          invalidez_cpf++;
      while (strlen(ficha[i].cpf) < 11 || strlen(ficha[i].cpf) > 11 || invalidez_cpf > 0)
      {
          invalidez_cpf = 0;
          printf("\nInvalido! Tente novamente:\nDigite o cpf (11 digitos, apenas numeros): ");
          scanf("%s", ficha[i].cpf);
          getchar();
          for (j=0; ficha[i].cpf[j] != '\0'; j++)
            if(ficha[i].cpf[j] < '0' || ficha[i].cpf[j] > '9')
              invalidez_cpf++;
      }
    }
    
    printf("\nEis a ficha das %d pessoas cadastradas: ", QTDE_PESSOAS);
    
    for(i=0;i<QTDE_PESSOAS;i++)
    {
        printf("\n\n---------Pessoa %d---------\n\n", i+1);
        printf("\nNome da %dª pessoa: %s", i+1, ficha[i].nome);
        printf("\nIdade da %dª pessoa: %d", i+1, ficha[i].idade);
        printf("\nSexo da %dª pessoa: ", i+1);
        switch(ficha[i].sexo)
        {
            case 'M': printf("Masculino"); break;
            case 'm': printf("Masculino"); break;
            case 'F': printf("Feminino"); break;
            case 'f': printf("Feminino"); break;
        }
        printf("\nCPF da %dª pessoa: %s", i+1, ficha[i].cpf);
    }

  return 0;
}