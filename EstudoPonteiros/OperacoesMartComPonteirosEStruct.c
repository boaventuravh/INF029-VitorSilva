#include <stdlib.h>
#include <stdio.h>

typedef struct test{
    int primeiro;
    int segundo;
    int terceiro;
}Teste;

int main()
{
    Teste variavel;
    Teste *ponteiro;
    ponteiro = &variavel;
    
    int referencia = 5;
    
    variavel.primeiro = 1;
    variavel.segundo = 2;
    variavel.terceiro = 3;
    
    Teste outraVariavel;
    
    printf("\nPrimeiro: %d\nSegundo: %d\nTerceiro: %d\n", variavel.primeiro, variavel.segundo, variavel.terceiro);
    
    outraVariavel.primeiro = referencia + ponteiro->primeiro;
    outraVariavel.segundo = referencia + ponteiro->segundo;
    outraVariavel.terceiro = referencia + ponteiro->terceiro;
    
    printf("\nOUTRA\n\nPrimeiro: %d\nSegundo: %d\nTerceiro: %d", outraVariavel.primeiro, outraVariavel.segundo, outraVariavel.terceiro);

    return 0;
}
