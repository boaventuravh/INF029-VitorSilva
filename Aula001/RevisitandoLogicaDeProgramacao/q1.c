//1. Faça um programa que imprima o seu nome, sua matrícula, e o seu semestre de ingresso no curso. Cada informação em uma linha.

#include <stdio.h>

int main(){
  char nome[] = "Vitor Hugo Boaventura da Silva", matricula[] = "20221160031", semestre_ingresso[] = "2022.1";
  
  printf("Nome: %s\nMatricula: %s\nSemestre de ingresso: %s", nome, matricula, semestre_ingresso);
  
  return 0;
}