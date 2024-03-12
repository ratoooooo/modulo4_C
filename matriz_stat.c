#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define NOME 5
#define NOTA 3

void estatistica(char nomes[NOME][50]);
void notas(float notas[NOME][NOTA]);
void per_posneg(float nota[NOME][NOTA]);
void medias(float nota[NOME][NOTA], char nome[NOME][50]);
void main()
{
	setlocale(LC_ALL, "Portuguese");
    system("cls");
    
    char nome[NOME][50];
    float nota[NOME][NOTA];
    
    estatistica(nome);
    notas(nota);
    
    system("pause");
    system("cls");
    
    per_posneg(nota);
    
    system("pause");
    system("cls");
    
    medias(nota, nome);
}

void estatistica(char nomes[NOME][50])
{
    int i;
    puts("****************** Informação ******************\n");
    for (i = 0; i < NOME; i++)
    {
        printf("Insira o nome do aluno %d\n", i + 1);
        scanf(" %s", nomes[i]);
        //vai ler o nome do aluno, na posição q se encontra  primeiro no 0 depois 1
    }
}

void notas(float notas[NOME][NOTA])
{
	int i, j;
	
	for (i=0; i < NOME; i++)
	{
		for (j=0; j < NOTA; j++)
		{
			printf("Insira a nota do aluno %d no %d teste\n", i+1, j+1);
			scanf("%f", &notas[i][j]);
		}
			printf("-------------------------------------------------\n");
	}
}

void per_posneg(float nota[NOME][NOTA])
{
    int i, j, num_pos = 0, num_neg = 0;
    float perc_neg, perc_posi;

    puts("****************** Estatisticas ******************\n");
    for (i = 0; i < NOME; i++)
    {
    	int media = 0;
        for (j = 0; j < NOTA; j++)
        {
            media += nota[i][j];
        }
        
        media /= NOTA;
        
        if (media >= 10)
        {
            num_pos++;
        }
        else
        {
            num_neg++;
        }
    }
    perc_posi = (100 * num_pos) / NOME; 
    perc_neg = (100 * num_neg) / NOME;

    printf("Percentagem de positivas: %.1f %%\n", perc_posi);
    printf("Percentagem de negativas: %.1f %%\n", perc_neg);
    puts("-------------------------------------------------\n");
    printf("Número de positivas: %d\n", num_pos);
    printf("Número de negativas: %d\n", num_neg);
    puts("-------------------------------------------------\n");
}

void medias(float nota[NOME][NOTA], char nome[NOME][50])
{
    float media, min = 20, max = 0;
    int i, melhor_alu = 0, pior_alu = 0, j;

    puts("****************** MÉDIAS ******************\n");

    for (i = 0; i < NOME; i++)
    {
        media = 0; 
        for (j = 0; j < NOTA; j++)
        {
            media += nota[i][j];
        }
        media /= NOTA;

        printf("A media do aluno nº%d, %s é %.2f\n", i + 1, nome[i], media);

        if (media > max)
        {
            max = media;
            melhor_alu = i + 1;
        }
        if (media < min)
        {
            min = media;
            pior_alu = i + 1;
        }
    }

    printf("-------------------------------------------\n");
    printf("A melhor média foi de %.2f do aluno %d.\n", max, melhor_alu);
    printf("A pior média foi de %.2f do aluno %d.\n", min, pior_alu);
}



