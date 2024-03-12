#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void main()
{
	setlocale(LC_ALL, "Portuguese");
    system("cls");
    
	char nome1[10];
	char nome2 [10];
	char ju[7] = "Joana";
	char frase [60] = "O rato roeu a rolha do Rei da Rússia";
	char palvra [10];
	char *res;

	int tamanho, ord;
	
	printf("Escreva o nome de um aluno da turma: \n");
	scanf("%s", &nome1);
	
	printf("Escreva o nome de outro aluno da turma: \n");
	scanf("%s", &nome2);
	
	printf("\n");
	 
	//strlen 
	tamanho = strlen(nome1);
    printf("O nome '%s' tem %d caracteres\n", nome1, tamanho); 
    
    tamanho = strlen(nome2);
    printf("O nome '%s' tem %d caracteres\n", nome2, tamanho); 
    
    printf("\n");
    //strcmp
	ord = strcmp(nome1, nome2);
	if (ord < 0)
	{
		printf("----ORDENAÇÃO DOS NOMES----\n");
		printf("1-%s \n", nome1);
		printf("2-%s\n", nome2);
		printf("---------------------------\n");
	}
    else if (ord > 0)
    {
    	printf("----ORDENAÇÃO DOS NOMES----\n");
		printf("1-%s \n", nome2);
		printf("2-%s \n", nome1);
		printf("---------------------------\n");
    }	
    else
    {
    	printf("----ORDENAÇÃO DOS NOMES----\n");
		printf("Os alunos tem o mesmo nome \n");
		printf("---------------------------\n");	
    }
	
	 printf("\n");
	
	//strcat
	strcat(nome1, nome2);
	printf("Se concatenasse os dois nomes, ficaria assim %s \n", nome1);
	
	printf("\n");
	
	//strcmp
	printf("Alterei o primeiro nome para 'Joana' e a nova ordenação é a seguinte: \n");
	ord = strcmp(ju, nome2);
	
	if (ord < 0)
	{
		printf("----ORDENAÇÃO DOS NOMES----\n");
		printf("1-%s \n", ju);
		printf("2-%s\n", nome2);
		printf("---------------------------\n");
	}
    else if (ord > 0)
    {
    	printf("----ORDENAÇÃO DOS NOMES----\n");
		printf("1-%s \n", nome2);
		printf("2-%s \n", ju);
		printf("---------------------------\n");
    }	
    else 
    {
    	printf("----ORDENAÇÃO DOS NOMES----\n");
		printf("Os alunos tem o mesmo nome \n");
		printf("---------------------------\n");	
    }
    
    system("pause");
    system("cls");

    //strstr
    printf("Digite uma palavra ver se esta na frase\n");
    printf("O rato roeu a rolha do Rei da Rússia\n");
    scanf("%s", &palvra);
    
	res = strstr(frase, palvra);
	if (res)
    {
    	printf("Encontrou a palavra ''%s' na frase 'O rato roeu a rolha do Rei da Rússia'\n", palvra);
    }
    else
    {
    	printf("Não encontrou a palavra '%s' na frase 'O rato roeu a rolha do Rei da Rússia'\n", palvra);
    }
    
}
