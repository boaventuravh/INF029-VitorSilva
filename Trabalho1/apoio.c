//funções auxiliares na resolução das questões

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "VitorSilva20221160031.h"

int validarData(int dia, int mes, int ano){
    
    int validade = 1; // se validade = 0, a data é inválida

    // o if abaixo elimina casos absurdos
    if(dia<1 || dia > 31 || ano < 10 || ano > 9999 || mes < 1 || mes > 12)
    {
        validade = 0;
        return validade;
    }

    /* o else abaixo faz uma verificação mais minunciosa, considerando ano bissexto, meses
    com 30 e 31 dias, fevereiro com mais de 28 dias*/ 
    else
    {
        if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        {
            validade = 0;
            return validade;
        }

        else if(mes == 2)
        {
            /*se o ano não é divisível por 4, não pode ser bissexto*/
            if(ano%4 != 0 && dia > 28)
            {
                validade = 0;
                return validade;
            }

            else if(((ano%4 == 0 && ano%100 != 0)||(ano%4 == 0 && ano%100 == 0 && ano%400==0)) && dia > 29)
            {
                validade = 0;
                return validade;
            }
        }
        
        return validade;
    }
}

int verificarBissexto(int ano){
    int bissexto; // 0 se não for, 1 se for

    if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
        bissexto = 1;
        return bissexto;
    }

    else{
        bissexto = 0;
        return bissexto;
    }
}
//a função abaixo é para a questão 5. Ainda está incompleta
int inverterInteiro(int num){
    int restos[200];
    int quociente, contador, invertido;
    quociente = num;
    contador = 0;
    invertido = 0;
    
    
    while(quociente>0){
        restos[contador] = quociente % 10;
        quociente /= 10;
        printf("\nContador: %d", contador);
        contador++;
    }
    
    for(int count = contador; count > 0; count--)
    {
        invertido += restos[contador - count]*pow(10,count);
    }
    
    return invertido;
    
}