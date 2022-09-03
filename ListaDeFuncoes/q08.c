/*8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente.*/

#include <stdio.h>
#include <string.h>

typedef struct cadastro_de_cliente{
char nome[];
char dataNascimento[];
char cpf[];
char sexo;
}Cadastro;

int main(){
  return 0;
}

Cadastro cadastrarCliente(Cadastro fCad)
{
  fflush(stdin);
  printf("\nDigite o nome: ");
  fgets(fCad.nome, , stdin);
  printf("\nDigite a data de nascimento no formato dia/mes/ano: ");
  fCad.nome[strlen(fCad.nome) - 1] = '\0';
  fgets(fCad, , stdin);
  return funCad;
}