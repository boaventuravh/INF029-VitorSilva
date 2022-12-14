// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Vitor Hugo Boaventura da Silva
//  email: boaventurads.vitorhugo@gmail.com
//  Matrícula: 20221160031
//  Semestre: 2022.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016
// Compilação: gcc apoio.c VitorSilva20221160031.c corretor.c -o test

// #################################################

#include <stdio.h>
#include "VitorSilva20221160031.h"
#include <stdlib.h>
#include <string.h>
#include "apoio.h"


DataQuebrada quebraData(char data[]){
    DataQuebrada dq;
    char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}
    else {
		dq.valido = 0;
        return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno); 

    dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */



int q1(char data[])
{
    DataQuebrada brokenDate;
    brokenDate = quebraData(data);
    if(brokenDate.valido == 0)
        return 0;
    else
        return validarData(brokenDate.iDia , brokenDate.iMes , brokenDate.iAno);
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
*/
 DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    
    DataQuebrada dataQuebrInicial, dataQuebrFinal;
    
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }
    
	else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }
    
	else{
        dataQuebrInicial = quebraData(datainicial);
        dataQuebrFinal = quebraData(datafinal);

        if (dataQuebrFinal.iAno < dataQuebrInicial.iAno){
            dma.retorno = 4;
            return dma;
        }

        else if (dataQuebrFinal.iAno == dataQuebrInicial.iAno && dataQuebrFinal.iMes < dataQuebrInicial.iMes){
            dma.retorno = 4;
            return dma;
        }

        else if (dataQuebrFinal.iAno == dataQuebrInicial.iAno && dataQuebrFinal.iMes == dataQuebrInicial.iMes && dataQuebrFinal.iDia < dataQuebrInicial.iDia){
            dma.retorno = 4;
            return dma;
        }
        
      
        //calcule a distancia entre as datas
                //anos
        dma.qtdAnos = dataQuebrFinal.iAno - dataQuebrInicial.iAno;
        
        if (dataQuebrFinal.iMes < dataQuebrInicial.iMes || (dataQuebrFinal.iMes == dataQuebrInicial.iMes && dataQuebrFinal.iDia < dataQuebrInicial.iDia)){
            dma.qtdAnos--;
        }
        
        //meses
        if(dataQuebrFinal.iMes < dataQuebrInicial.iMes){
            dma.qtdMeses = 12 - dataQuebrFinal.iMes;            
        }

        else{
            dma.qtdMeses = dataQuebrFinal.iMes - dataQuebrInicial.iMes;
        }

        //dias
        //meses com 30 dias
        if(dataQuebrFinal.iMes == 4 || dataQuebrFinal.iMes == 6 || dataQuebrFinal.iMes == 9 || dataQuebrFinal.iMes == 11){
            if(dataQuebrFinal.iDia == 30 || dataQuebrFinal.iDia == dataQuebrInicial.iDia){
                dma.qtdDias = 0;
            }
            else{
                if(dataQuebrFinal.iDia > dataQuebrInicial.iDia)
                    dma.qtdDias = dataQuebrFinal.iDia - dataQuebrInicial.iDia;
                else
                    dma.qtdDias = dataQuebrFinal.iDia;
            }
        }
        //meses com 31 dias
        else if(dataQuebrFinal.iMes == 1 || dataQuebrFinal.iMes == 3 || dataQuebrFinal.iMes == 5 || dataQuebrFinal.iMes == 7 || dataQuebrFinal.iMes == 8 || dataQuebrFinal.iMes == 10 || dataQuebrFinal.iMes == 12){
            
            if(dataQuebrFinal.iDia == 31 || dataQuebrFinal.iDia == dataQuebrInicial.iDia){
                dma.qtdDias = 0;
            }
            else{
                if(dataQuebrFinal.iDia > dataQuebrInicial.iDia)
                    dma.qtdDias = dataQuebrFinal.iDia - dataQuebrInicial.iDia;
                else
                    dma.qtdDias = dataQuebrFinal.iDia;
            }
        }
        // fevereiro(28 ou 29 dias)
        else{
            if((verificarBissexto(dataQuebrFinal.iAno) == 1 && dataQuebrFinal.iDia == 29) || dataQuebrFinal.iDia == dataQuebrInicial.iDia){
                dma.qtdDias = 0;
            }
            else if((verificarBissexto(dataQuebrFinal.iAno) == 0 && dataQuebrFinal.iDia == 28) || dataQuebrFinal.iDia == dataQuebrInicial.iDia){
                dma.qtdDias = 0;
            }
            else{
                if(dataQuebrFinal.iDia > dataQuebrInicial.iDia)
                    dma.qtdDias = dataQuebrFinal.iDia - dataQuebrInicial.iDia;
                else
                    dma.qtdDias = dataQuebrFinal.iDia;
            }
        }
        


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
*/
 int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    switch(isCaseSensitive){
        case 1:
            for(int i = 0; texto[i] != '\0';i++)
            {
                if (texto[i] == c)
                    qtdOcorrencias++;
            }
            break;
        default:
            for(int i = 0; texto[i] != '\0';i++)
            {
                if (texto[i] == c || texto[i]+32 == c || texto[i] - 32 == c)
                    qtdOcorrencias++;
            }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
*/
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int contador = 0;

    for(int i=0; strTexto[i + strlen(strBusca) - 1] != '\0'; i++)
    {
        int diferentes = 0;
        int i2;
        for(int j = 0, i2 = i; strBusca[j] != '\0'; j++, i2++)
        {
            if(strBusca[j] != strTexto[i2])
                diferentes++;
        }
        if(diferentes == 0)
        {
            qtdOcorrencias++;
            posicoes[contador] = i+1;
            posicoes[contador + 1] = i + strlen(strBusca);
            contador += 2;
            i+=strlen(strBusca) - 1;
        }
    }

    return qtdOcorrencias;
}
 

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
*/
 int q5(int num)
{
    num = inverterInteiro(num);
    
    return num;
}


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int numeroDecomposto[50];
    int numeroDecompostoMaior[50];
    int numeroDecompostoMenor[50];
    int contador = 0;
    int divisor;
    int quociente, quocienteMaior, quocienteMenor;
    
    // abaixo, identificamos a quantidade de dígitos do numerobusca
    quociente = numerobusca;
    while(quociente > 0)
    {
        quociente /= 10;
        contador++;
    }
    
    divisor = potenciacao(10, contador);
    contador = 0;
    
    // abaixo, subdividimos o numerobase em numeros com a mesma quantidade
    // de dígitos do numerobusca
    quociente = numerobase;
    quocienteMaior = quociente*10;
    quocienteMenor = quociente/10;
    
    
    while(quocienteMaior >0)
    {
        numeroDecompostoMaior[contador] = quocienteMaior % divisor;
        quocienteMaior /= divisor;
        contador++;
    }
    contador = 0;
    
    while(quocienteMenor >0)
    {
        numeroDecompostoMenor[contador] = quocienteMenor % divisor;
        quocienteMenor /= divisor;
        contador++;
    }
    contador = 0;
    
    while(quociente > 0)
    {
        numeroDecomposto[contador] = quociente % divisor;
        quociente /= divisor;
        contador++;
    }
    
    // e finalmente buscamos a quantidade de ocorrencias
    for(int i=0 ; i<contador; i++)
    {
        if(numerobusca == numeroDecomposto[i])
            qtdOcorrencias++;
    }
    
    if (qtdOcorrencias == 0)
    {
        contador++;
        for(int i=0 ; i<contador; i++)
        {
            if(numerobusca == numeroDecompostoMaior[i])
                qtdOcorrencias++;
        }
        
        if (qtdOcorrencias == 0)
        {
            contador -= 2;
            for(int i=0 ; i<contador; i++)
            {
                if(numerobusca == numeroDecompostoMenor[i])
                qtdOcorrencias++;
            }
            
        }
    }
    
        
    return qtdOcorrencias;
}
