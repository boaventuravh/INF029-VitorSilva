#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QTD_Alunos 5
#define QTD_Professores 3
#define anoAtual 2022

typedef struct Alunos {
	char nome[101];
	long int matricula;
	char cpf[20];
	char sexo[20];
	char data[12];
	int quant;
} Alunos;

typedef struct Disciplinas {
	char nome[101];
	char codigo[8]; //utilizaremos o padrão do IFBA: 3 letras maiúsculas e 3 números. Exemplo: INF029
	char semestre[8]; // formato AAAA.S, exemplo: 2022.1
	char professor[101];
	Alunos alunosMatriculados;
	int quant;
} Disciplinas;

Disciplinas cadastroDisciplina(Disciplinas cadastro/*[]*/);

int main()
{
    Disciplinas disciCadastradas/*[10]*/; // depois podemos alterar essa quantidade
    disciCadastradas = cadastroDisciplina(disciCadastradas/*[]*/);
    printf("\nNome: %s", disciCadastradas.nome);
    printf("\nCodigo: %s", disciCadastradas.codigo);
    printf("\nSemestre: %s", disciCadastradas.semestre);
    printf("\nProfessor: %s", disciCadastradas.professor);
    return 0;
}

Disciplinas cadastroDisciplina(Disciplinas cadastro/*[]*/)
{
    
    fflush(stdin);

    printf("\nNome: ");
    fgets(cadastro.nome, 101, stdin);
    cadastro.nome[strcspn(cadastro.nome, "\n")] = 0;
    
    //validação do nome
    
    printf("\nCodigo(3 letras maiusculas e 3 numeros): ");
    fgets(cadastro.codigo, 8, stdin);
    cadastro.codigo[strcspn(cadastro.codigo, "\n")] = 0;
    
    //validação do código
    
    printf("\nSemestre (formato ANO.SEMESTRE <AAAA.S>): ");
    fgets(cadastro.semestre, 8, stdin);
    cadastro.semestre[strcspn(cadastro.semestre, "\n")] = 0;
    
    //validação do semestre
    
    printf("\nProfessor: ");
    fgets(cadastro.professor, 101, stdin);
    cadastro.professor[strcspn(cadastro.professor, "\n")] = 0;
    
    //validação do professor
    
    return cadastro;
}

