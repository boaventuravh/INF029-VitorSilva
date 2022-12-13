#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct lista{
        int valor;
        struct lista *proximo;
    };

    typedef struct lista ListaConcatenada;
    
    ListaConcatenada membro1, membro2, membro3;
    ListaConcatenada *gancho = &membro1;
    
    membro1.valor = 1;
    membro2.valor = 2;
    membro3.valor = 3;
    
    membro1.proximo = &membro2;
    membro2.proximo = &membro3;
    membro3.proximo = (ListaConcatenada *)0;
    
    while(gancho != (ListaConcatenada *)0)
    {
        printf("%d\n", gancho->valor);
        gancho = gancho->proximo;
    }
    
    return 0;
}

