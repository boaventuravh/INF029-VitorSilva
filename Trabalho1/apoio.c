//funções auxiliares na resolução das questões

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            if(ano%4 != 0 && dia > 28)
            {
                validade = 0;
                return validade;
            }

            else if (ano%4 == 0 && dia > 29)
            {
                validade = 0;
                return validade;
            }
        }
        
        return validade;
    }
}