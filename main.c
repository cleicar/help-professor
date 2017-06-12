#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* estrutura com informações necessárias para cadastrar um aluno. */
struct Aluno
{
    char nome[30];
    char matricula[10];
    float p1, p2, p3, p4, substituta, media;
};

/* Cadastra um novo aluno informando nome e matricula.*/
void CadastrarAluno(struct Aluno *alunos, int posicao){
	fflush(stdin);
	
	printf("\n\n");
	printf("|=================================|\n");
	printf("| Voce escolheu cadastrar alunos: |\n");
	printf("|=================================|\n");
		
	printf("| 1. Informe a matricula do aluno %d: ", posicao+1);
	gets(alunos[posicao].matricula);
	fflush(stdin);
	
	printf("| 2. Informe o nome do aluno %d: ", posicao+1);
	gets(alunos[posicao].nome);
	fflush(stdin);
}

/* Exibe uma lista com nome de todos os alunos, permite selecionar um e cadastrar todas as notas. */
void CadastrarNota(struct Aluno *alunos, int qtdAlunos){
	fflush(stdin);
	int count, opcao = 0;
	
	printf("\n\n");
	printf("|=================================|\n");
	printf("| Voce escolheu cadastrar notas:  |\n");
	printf("|=================================|\n");
	printf("|---------------------------------|\n");
	printf("| Selecione o aluno:              |\n");
	printf("|---------------------------------|\n");
	
	for(count = 0 ; count < qtdAlunos ; count++)
    {
		printf("| %d - %s - matricula: %s\n", count+1, alunos[count].nome, alunos[count].matricula);
	}
	
	printf("\nSua opcao: ");
	scanf("%d", &opcao);
		
	printf("\n| Informe as notas do Aluno: %s", alunos[opcao-1].nome);
	
	printf("\n| Nota P1: ");
	scanf("%f", &alunos[opcao-1].p1);
	
	printf("| Nota P2: ");
	scanf("%f", &alunos[opcao-1].p2);
	
	printf("| Nota P3: ");
	scanf("%f", &alunos[opcao-1].p3);
	
	printf("| Nota P4: ");
	scanf("%f", &alunos[opcao-1].p4);
		
	printf("| Nota prova substituta (informe 0 caso nao tenha nota): ");
	scanf("%f", &alunos[opcao-1].substituta);
}

/* Calcula e exibe a media ponderada das notas de todos os alunos cadastrados */
void CalcularMedias(struct Aluno *alunos, int qtdAlunos){
	float media, auxiliar = 0.0;
	int posicao, i, j = 0;
	
	printf("\n\n");
	printf("|==========================================|\n");
	printf("| Voce escolheu calcular media dos alunos: |\n");
	printf("|==========================================|\n\n");
	
	for(posicao=0 ; posicao < qtdAlunos ; posicao++)
    {
    	float notas[4] = {alunos[posicao].p1, alunos[posicao].p2, alunos[posicao].p3, 
			alunos[posicao].p4};
    	
		auxiliar = notas[i];
		for(i=1; i<4; i++){
			if(notas[i] < auxiliar){
				auxiliar = notas[i];
				j = i;
			}
		}
		
		notas[j] = alunos[posicao].substituta;	
	    
    	media = ((notas[0]*1) + (notas[1]*2)+ (notas[2]*3) + (notas[3]*4))/10;
		printf("| %d - %s \t Media: %.2f\n", posicao+1, alunos[posicao].nome, media);
		
		alunos[posicao].media = media;
	}
	
	system("pause");
}

/* Exibe um relatório de desempenho com nome de todos os alunos, suas notas, médias e resultado final 
   (aprovado ou reprovado). Exibe também a média geral da sala (todos os alunos). */  
void ExibirResultados(struct Aluno *alunos, int qtdAlunos){
	int posicao = 0;
	float mediaSala = 0.0;
	char situacao[10] = "APROVADO";
	
	system("cls");
	printf("|==========================================|\n");
	printf("| Resultado Final dos Alunos:              |\n");
	printf("|==========================================|\n");
		
	if(alunos[posicao].media < 5.0)
		situacao[10] = "REPROVADO";
	
	for(posicao=0 ; posicao < qtdAlunos ; posicao++)
    {
    	printf("\n |----------------------------------------------\n");
    	printf("\n | Matricula: %d", alunos[posicao].matricula);
		printf("\n | Nome: %s", alunos[posicao].nome);
		printf("\n | Notas: %.2f - %.2f - %.2f - %.2f ", alunos[posicao].p1, alunos[posicao].p2, 
			alunos[posicao].p3, alunos[posicao].p4);
		printf("\n | Media: %.2f", alunos[posicao].media);
		printf("\n | Situacao: %s \n", situacao); 
		printf("\n |----------------------------------------------\n");
		
		mediaSala += alunos[posicao].media;
	}
	
	printf("\n |----------------------------------------------\n");
	printf("\n | MEDIA DA SALA: %.2f", mediaSala/qtdAlunos);
	
	system("pause");
}

/* O HelpProfessor é um programa que Cadastra e Gerencia as notas dos alunos e calcula suas médias. 
   Exibe também um relatório com as notas, médias e a média da sala. */
int main(void)
{
    struct Aluno alunos[100];
    int posicao, count = 0;
	int opcao, qtdAlunos, i = 0;
	
	while(opcao != 5){	
		system("cls");
		printf("|==================================|\n");
		printf("| Bem vindo(a) ao HelpProfessor	   |\n");
		printf("|==================================|\n");
		printf("|----------------------------------|\n");
		printf("| Escolha a opcao desejada:        |\n");
		printf("|----------------------------------|\n");
		printf("|                                  |\n");
		printf("| 1. Cadastrar alunos              |\n");
		printf("| 2. Cadastrar notas               |\n");
		printf("| 3. Calcular medias               |\n");
		printf("| 4. Resultado final               |\n");
		printf("| 5. Sair                          |\n");
		printf("|                                  |\n");
		printf("|----------------------------------|\n");		
		printf("| Sua opcao: ");
		
		scanf("%d", &opcao);
		system("cls");
		
		switch (opcao){
			case 1:
				CadastrarAluno(alunos, qtdAlunos); //Cadastra um aluno informando nome e matricula.
				qtdAlunos += 1;
				break;
			case 2:
				CadastrarNota(alunos, qtdAlunos); //Cadastra as notas de um aluno
				break;
			case 3:
				CalcularMedias(alunos, qtdAlunos); //Calcula e exibe a média de todos os alunos
				break;
			case 4:
				ExibirResultados(alunos, qtdAlunos); //Exibe um relatório com notas, medias e situação de todos os alunos.
			case 5: 
				exit(0);
            default: puts("TENTE NOVAMENTE");
		}
	}
}	
