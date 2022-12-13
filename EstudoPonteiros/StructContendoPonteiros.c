#include <stdlib.h>
#include <stdio.h>

typedef struct horario{
    int *pHora;
    int *pMinuto;
    int *pSegundo;
}Horario;

int main()
{
    Horario variavel;
    
    int hora = 20;
    int min = 45;
    int seg = 59;
    
    variavel.pHora = &hora;
    variavel.pMinuto = &min;
    variavel.pSegundo = &seg;
    
 
    printf("\nHorario: %d:%d:%d", *variavel.pHora, *variavel.pMinuto, *variavel.pSegundo);
    

    return 0;
}
