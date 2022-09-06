/*9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada
validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado
com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNacimento: recebe o data digitada, e valida é uma data válida*/

#include <stdio.h>
#include <string.h>


typedef struct cadastro_de_cliente{
char nome[257];
char dataNascimento[11];
char cpf[12];
char sexo;
int vNome;
int vData;
int vCpf;
int vSexo;
}Cadastro;


/*Os inteiros da estrutura acima serão utilizados na validação dos dados. -1 = erro, 1 = sucesso*/

Cadastro cadastrarCliente(Cadastro fCad);
int valNome(char valiNome[]);
int valData(char valiData[]);

int valSexo(char valiSexo);

int main(){
  Cadastro mainCad;
  
  mainCad = cadastrarCliente(mainCad);

  printf("\nEis os dados do cliente:\n");
  printf("\nNome: %s", mainCad.nome);
  printf("\nData de nascimento: %s, Validade: %d", mainCad.dataNascimento, mainCad.vData);
  printf("\nCPF: %s", mainCad.cpf);
  printf("\nSexo: %c, Validade: %d", mainCad.sexo, mainCad.vSexo);
  
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

  //validação dos dados abaixo
  
  fCad.vNome = valNome(fCad.nome);
  fCad.vData = valData(fCad.dataNascimento);

  fCad.vSexo = valSexo(fCad.sexo);
  
  return fCad;
}

int valNome(char valiNome[])
{
  if (strlen(valiNome) > 20 || strlen(valiNome) < 0)
    return -1;
  else
    return 1;
}

int valData(char valiData[])
{
  if((valiData[0]-48)*10+(valiData[1]-48) > 31 || (valiData[0]-48)*10+(valiData[1]-48) <= 0)
    return -1;
  else
    return 1;
}

int valSexo(char valiSexo)
{
  if(valiSexo != 'F' && valiSexo != 'f' && valiSexo != 'M' && valiSexo != 'm' && valiSexo != 'O' && valiSexo != 'o')
    return -1;
  else
    return 1;
}
