/*04. Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno*/

#include <stdio.h>
#define QTDE 3

void ler3numeros(int num_func[QTDE]);

int main(){
  int i, num_main[QTDE];
  
  ler3numeros(num_main);
  

  for(i=0;i<QTDE;i++)
      printf("\n%dº numero: %d", i+1, num_main[i]);
  
  return 0;
}

void ler3numeros(int num_func[QTDE]) // não é necessário especificar o tamanho do vetor, poderia ser declarado como num_func[], o que serve como forma de manter o vetor genérico
{
  int i;
  for (i=0;i<QTDE;i++)
    {
      printf("\nDigite o %dº numero: ", i+1);
      scanf("%d", &num_func[i]);
    }
}