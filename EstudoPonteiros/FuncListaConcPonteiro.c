/*Esse programa cria uma lista concatenada e busca um
valor fornecido pelo usuário dentro dessa lista*/

#include <stdio.h>
#include <stdlib.h>

struct lista{
        int valorNaLista;
        struct lista *proximoValorNaLista;
        };

typedef struct lista ListaConcatenada;

ListaConcatenada *procurarValor(ListaConcatenada *pLista, int valorProcurado);


int main()
{
    ListaConcatenada elemento1, elemento2, elemento3;
    ListaConcatenada *resultado, *gancho = &elemento1; 

    elemento1.valorNaLista = 4;
    elemento2.valorNaLista = 7;
    elemento3.valorNaLista = 9;

    elemento1.proximoValorNaLista = &elemento2;
    elemento2.proximoValorNaLista = &elemento3;
    elemento3.proximoValorNaLista = 0;

    int valorInformado;
    printf("\nDigite o valor procurado: ");
    scanf("%d", &valorInformado);

    resultado = procurarValor(gancho, valorInformado);

    if(resultado){
        printf("\nValor %d encontrado!", (*resultado).valorNaLista);
    }
    else{
        printf("\nNao encontrado!");
    }

    
    return 0;
}

ListaConcatenada *procurarValor(ListaConcatenada *pLista, int valorProcurado){

    while(pLista != (ListaConcatenada *)0){
        if(pLista->valorNaLista == valorProcurado){
            return(pLista);
        }
        else{
            pLista = pLista->proximoValorNaLista;
        }
    }

    return (ListaConcatenada *)0; 
    // equivale a return NULL;
    
}