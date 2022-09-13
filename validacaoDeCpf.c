#include <stdio.h>
#include <string.h>

int validaCpf(char cpf[]);

int main()
{
    char cpf[]="00795718241";
    
   /* printf("CPF: ");
	fgets(cpf, 20, stdin);
	cpf[strcspn(cpf, "\n")] = 0;*/
	
	validaCpf(cpf);
	
    printf("\nEis o CPF digitado: %s", cpf);

    return 0;
}

int validaCpf(char cpf[])
{
    int cpfNum[12];
    int i, j, digiVeri=0;
    
    for(i=0;cpf[i]!='\0';i++)
      cpfNum[i] = cpf[i]-48;
    
    for(i=0,j=10;i<9;i++,j--)
    {
        digiVeri += j*(cpfNum[i]);
        printf("\nVerificador: %d", digiVeri);
    }
    digiVeri%=11;
    digiVeri = 11 - digiVeri;
    printf("\nVerificador fora do laco: %d", digiVeri);
}