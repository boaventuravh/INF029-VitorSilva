#include <stdlib.h>
#include <stdio.h>


struct cel{
    int conteudo;
    struct cel *prox;
};

typedef struct cel Celula;

int main()
{
    
    int tamanhoDaLista;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanhoDaLista);
    
    Celula *listaEncadeada = (Celula *)malloc(tamanhoDaLista * sizeof(Celula));
    
    for(int i = 0; i<tamanhoDaLista; i++){
        printf("\nDigite o %do valor: ", i+1);
        scanf("%d", &listaEncadeada[i].conteudo);
        listaEncadeada[i].prox = &listaEncadeada[i+1];
    }
    
    listaEncadeada[tamanhoDaLista - 1].prox = NULL;
    
    Celula *gancho = listaEncadeada;
    
    
    printf("\nPercorrendo a lista: ");
    while(gancho){
        printf("\n%d", gancho -> conteudo);
        gancho = gancho -> prox;
    }
    


    return 0;
}
