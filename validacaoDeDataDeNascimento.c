#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define anoAtual 2022

int validarNascimento(char dataNasc[]);

int main()
{
    char data[] = "03/11/1980";
    int validadeData;
    
    validadeData = validarNascimento(data);
    
    printf("\n\nValidade: %d", validadeData);

    return 0;
}

int validarNascimento(char dataNasc[]){
    
    char aux[12];
    int data;
    int dia, mes, ano;
    int i, j = 0;
    int erros = 0;
    
    if(dataNasc[2] != '/' || dataNasc[5] != '/')
        return -1;
    
    for(i=0;dataNasc[i]!='\0';i++)
        aux[i] = dataNasc[i];
    
    // Copiando apenas numeros para o vetor dataNasc
        for(i = 0; aux[i] != '\0'; i++){
            if(aux[i] >= 48 && aux[i] <= 57){
                dataNasc[j] = aux[i];
                j++;
            }
        }
        dataNasc[j] = '\0';
        
    if(j<8)
        return -1;
        
    // Transformando a data (string) em data (int)
    data = atoi(dataNasc);
    
    ano = data % 10000;
    mes = (data / 10000) % 100;
    dia = (data / 10000) / 100;
    
    if(dia > 31)
        erros = -1;
        // printf("\nDia invalido");
    if(mes > 12)
        erros = -1;
        // printf("\nMes invalido");
    if(ano > anoAtual)
        erros = -1;
        // printf("\nAno maior que o ano atual");
    
    int maxDias;
    if(mes == 2){
        if((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))) {
            // Ano Bissexto
            if(mes == 2)
                maxDias = 29;
        }
        else {
            // Ano não bissexto
            if(mes == 2)
                maxDias = 28;
        }
        if(mes == 2 && dia > maxDias)
            erros = -1;
            // printf("Erro. O mes %d teve %d dias neste ano.", mes, maxDias);
    }
    else{
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            maxDias = 30;
        else
            maxDias = 31;
            
        if(dia > maxDias)
            erros = -1;
            // printf("\nErro. O mes %d possui apenas %d dias", mes, maxDias);
    }

    return erros;
}
