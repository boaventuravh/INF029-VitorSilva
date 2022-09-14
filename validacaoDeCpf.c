#include <stdio.h>
#include <string.h>

int validaCpf(char cpf[]);

int main()
{
    char cpf[20];
    int validade; //sobre a validade:  se a função retornar -1 o CPF é inválido, se retornar 1, é válido
    printf("\nCPF (apenas numeros): ");
	fgets(cpf, 20, stdin);
	cpf[strcspn(cpf, "\n")] = 0;
	validade = validaCpf(cpf);
	
	while(validade == -1)
	{
	    fflush(stdin);
	    printf("\nCPF invalido! Tente novamente: ");
	    fgets(cpf, 20, stdin);
	    cpf[strcspn(cpf, "\n")] = 0;
	    validade = validaCpf(cpf);
	}

    return 0;
}

int validaCpf(char cpf[])
{
    int cpfNum[12];
    int i, j, digiVeri=0;
    
    if(strlen(cpf) != 11)
        return -1;
    
    for(i=0;cpf[i]!='\0';i++)
    {
      if (cpf[i] < '0' || cpf[i]> '9')  // essa condicional garante que o só entram números no cpf
        return -1;
      cpfNum[i] = cpf[i]-48;            // aqui, convertemos o cpf em int pra ficar mais fácil de trabalhar na validação
    }
    for(i=0,j=10;i<9;i++,j--)
    {
        digiVeri += j*(cpfNum[i]);
    }
    digiVeri%=11;
    if (digiVeri == 1 || digiVeri == 0)
        digiVeri = 0;
    else
        digiVeri = 11 - digiVeri;
    
    if (digiVeri != cpfNum[9])
        return -1;
    else
    {
        digiVeri = 0;
        for(i=0,j=11;i<10;i++,j--)
        {
            digiVeri += j*(cpfNum[i]);
        }
        digiVeri%=11;
        if (digiVeri == 1 || digiVeri == 0)
            digiVeri = 0;
        else
            digiVeri = 11 - digiVeri;
        if (digiVeri != cpfNum[10])
            return -1;
        else
            return 1;
    }
}
