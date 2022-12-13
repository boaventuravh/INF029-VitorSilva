#include <stdio.h>
#include <stdlib.h>


void testeVariavel(int x);
void testePonteiro(int *pX);

int main()
{
    int teste = 1;
    int *pTeste = &teste;
    
    
    testeVariavel(teste);
    printf("\nTeste: %d", teste);
    
    
    testePonteiro(pTeste);
    printf("\nTeste: %d", teste);
    
    return 0;
}

void testeVariavel(int x){
    x++;
    printf("\nTeste dentro da funcao: %d", x);
}

void testePonteiro(int *pX){
    ++*pX;
}