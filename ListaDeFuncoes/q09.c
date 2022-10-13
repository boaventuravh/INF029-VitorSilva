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

char cpf[12];
char sexo;
int vNome;
int vData;
int vCpf;
int vSexo;
struct dataNascimento{
int dia, mes, ano;
}Data;
}Cadastro;


/*Os inteiros da estrutura acima serão utilizados na validação dos dados. -1 = erro, 1 = sucesso*/

Cadastro cadastrarCliente(Cadastro fCad);
int valNome(char valiNome[]);
int valData(int d, int m, int a);
int valCpf(char valiCpf[]);
int valSexo(char valiSexo);

int main(){
  Cadastro mainCad;
  
  mainCad = cadastrarCliente(mainCad);

  printf("\nEis os dados do cliente:\n");
  printf("\nNome: %s", mainCad.nome);
  printf("\nData de nascimento: %d/%d/%d, validade: %d", mainCad.Data.dia, mainCad.Data.mes, mainCad.Data.ano, mainCad.vData);
  printf("\nCPF: %s, validade: %d", mainCad.cpf, mainCad.vCpf);
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
  scanf("%d/%d/%d", &fCad.Data.dia, &fCad.Data.mes, &fCad.Data.ano);
  getchar();
  printf("\nDigite o CPF: ");
  fgets(fCad.cpf, 12, stdin);
  getchar();
  fCad.cpf[strlen(fCad.cpf)] = '\0';
  printf("\nDigite o sexo (M para masculino, F para feminino): ");
  scanf("%c", &fCad.sexo);

  //validação dos dados abaixo
  
  fCad.vNome = valNome(fCad.nome);
  fCad.vData = valData(fCad.Data.dia, fCad.Data.mes, fCad.Data.ano);
  fCad.vCpf = valCpf(fCad.cpf);
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

int valData(int d, int m, int a)
{
  if(d<=0 || d>31)
    return -1;
  else
  {
    if(m<=0 || m>12)
      return -1;
    else
    {
      if(a<=0)
        return -1;
      else
        return 1;
    }
  }
}

int valCpf(char valiCpf[])
{
  int i, j, digVeri = 0;
  for(i=0, j=10;i<9;i++, j--){
    digVeri+=j*(valiCpf[i]-48);
    printf("\n%d", digVeri);
  }

  digVeri = digVeri%11;

  printf("\nVerificador: %d", digVeri);
    
  if(digVeri < 2)
    digVeri = 0;
  else
    digVeri = 11-digVeri;

  printf("\nVerificador: %d", digVeri);
  
  if(digVeri != valiCpf[9]-48)
    return -1;
  else
  {
    digVeri = 0;
    for(i=0, j=11;i<10;i++, j--){
      digVeri+=j*(valiCpf[i]-48);
    printf("\n%d", digVeri);
      
  }
    if(digVeri%11 < 2)
      digVeri = 0;
    else
      digVeri = 11 - digVeri%11;

    if(digVeri != valiCpf[10])
      return -1;
    else
      return 1;
  }
}

int valSexo(char valiSexo)
{
  if(valiSexo != 'F' && valiSexo != 'f' && valiSexo != 'M' && valiSexo != 'm' && valiSexo != 'O' && valiSexo != 'o')
    return -1;
  else
    return 1;
}
