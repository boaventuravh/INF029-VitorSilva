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

Disciplinas cadastroDisciplina(Disciplinas cadastro[]);

int main()
{
    int i;
    Disciplinas disciCadastradas[10]; // depois PRECISAMOS alterar essa quantidade de disciplinas
    cadastroDisciplina(disciCadastradas);
    
    for(i=0;i<disciCadastradas[0].quant;i++)
    {
        printf("-----------------------------------------");
        printf("\nNome: %s", disciCadastradas[i].nome);
        printf("\nCodigo: %s", disciCadastradas[i].codigo);
        printf("\nSemestre: %s", disciCadastradas[i].semestre);
        printf("\nProfessor: %s", disciCadastradas[i].professor);
        printf("\n\n");
    }

    return 0;
}

Disciplinas cadastroDisciplina(Disciplinas cadastro[])
{
    int op = 1;
    int validadeNome;
    int validadeCodigo;
    int validadeSemestre;
    int validadeProfessor;
    int i=0;
    
    while(op == 1)
    {
        fflush(stdin);
    
        printf("\nNome: ");
        fgets(cadastro[i].nome, 101, stdin);
        cadastro[i].nome[strcspn(cadastro[i].nome, "\n")] = 0;
        
        //validação do nome
        
        printf("\nCodigo(3 letras maiusculas e 3 numeros): ");
        fgets(cadastro[i].codigo, 8, stdin);
        cadastro[i].codigo[strcspn(cadastro[i].codigo, "\n")] = 0;
        
        //validação do código
        
        printf("\nSemestre (formato ANO.SEMESTRE <AAAA.S>): ");
        fgets(cadastro[i].semestre, 8, stdin);
        cadastro[i].semestre[strcspn(cadastro[i].semestre, "\n")] = 0;
        
        //validação do semestre
        
        printf("\nProfessor: ");
        fgets(cadastro[i].professor, 101, stdin);
        cadastro[i].professor[strcspn(cadastro[i].professor, "\n")] = 0;
        
        //validação do professor
        printf("\nDeseja realizar outro cadastro?\n[1] Sim\n[0] Nao\n");
	    scanf("%d", &op);
	    getchar();
	
	    while (op != 1 && op != 0) 
	    {
        	printf("\nOpcao invalida! Tente novamente: ");
        	scanf("%d", &op);
        	getchar();
	    }
	    
	    if (op == 1) 
	    {
	    	i++;
	    }
    }
    
    
    i++;
  	cadastro[0].quant = i;
    
}
