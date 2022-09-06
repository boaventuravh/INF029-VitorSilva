/*8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente.*/

#include <stdio.h>
#include <string.h>


typedef struct cadastro_de_cliente{
char nome[257];
char dataNascimento[11];
char cpf[12];
char sexo;
}Cadastro;

Cadastro cadastrarCliente(Cadastro fCad);

int main(){
  Cadastro mainCad;
  
  mainCad = cadastrarCliente(mainCad);

  printf("\nEis os dados do cliente:\n");
  printf("\nNome: %s", mainCad.nome);
  printf("\nData de nascimento: %s", mainCad.dataNascimento);
  printf("\nCPF: %s", mainCad.cpf);
  printf("\nSexo: %c", mainCad.sexo);
  
  return 0;
}

Cadastro cadastrarCliente(Cadastro fCad)
{
  fflush(stdin);
  printf("\nDigite o nome: ");
  fgets(fCad.nome, 257, stdin);
  fCad.nome[strlen(fCad.nome) - 1] = '\0';
  printf("\nDigite a data de nascimento no formato dia/mes/ano: ");
  fgets(fCad.dataNascimento, 11, stdin);
  getchar();
  fCad.dataNascimento[strlen(fCad.dataNascimento) - 1] = '\0';
  printf("\nDigite o CPF: ");
  fgets(fCad.cpf, 12, stdin);
  getchar();
  fCad.cpf[strlen(fCad.cpf) - 1] = '\0';
  printf("\nDigite o sexo (M para masculino, F para feminino): ");
  scanf("%c", &fCad.sexo);
  return fCad;
}