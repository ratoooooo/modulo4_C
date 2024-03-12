#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#define DIM 5

void estatistica(float notas[DIM][3]);
void pos_nrg(float notas[DIM][3]);
void medias(float notas[DIM][3]);
void main()
{
	setlocale(LC_ALL, "Portuguese");
    system("cls");
    
	float notas[DIM][3];
	
	estatistica(notas);
	
	system("pause");
    system("cls");

	pos_nrg(notas);
	
	system("pause");
    system("cls");
    
	medias(notas);
}

void estatistica(float notas[DIM][3])
{
	int i;
	
	printf("****************** Informação ******************\n");
	for (i=0; i<DIM; i++)
	{
		printf("Digite a nota do aluno nº %d no primeiro teste: ", i+1);
		scanf("%f", &notas[i][0]);
		printf("Digite a nota do aluno nº %d no segundo teste: ", i+1);
		scanf("%f", &notas[i][1]);
		printf("Digite a nota do aluno nº %d no terceiro teste: ", i+1);
		scanf("%f", &notas[i][2]);
		printf("-------------------------------------------------\n");
	}
}

void pos_nrg(float notas[DIM][3])
{
	int i, num_pos=0, num_neg=0;
	float perc_neg, perc_posi;
	
	printf("****************** Estatisticas ******************\n");
	for (i=0; i<DIM; i++)
	{
		if ((notas[i][0] + notas[i][1] + notas[i][2])/3 >= 10)
		{
			num_pos++;
		}
		else
		{
			num_neg++;
		}
	}

	// percentagem de positivas e negativas
	perc_posi = (100 * num_pos) / DIM;
	perc_neg = (100 * num_neg) / DIM;
	
	printf("Percentagem de positivas: %.1f %%\n", perc_posi);
	printf("Percentagem de negativas: %.1f %%\n", perc_neg);
	printf("-------------------------------------------------\n");
	printf("Número de positivas: %d\n", num_pos);
	printf("Número de negativas: %d\n", num_neg);
	printf("-------------------------------------------------\n");
}

void medias(float notas[DIM][3])
{
	float soma=0, media, min=20, max=0;
	int i, melhor_alu=0, pior_alu=0;;
	
	printf("****************** MÉDIAS ******************\n");
	//mediaa
	for (i=0; i<DIM; i++)
	{
		soma = notas[i][0] + notas[i][1] + notas[i][2];
		media = soma / 3;
		printf("A media do aluno nº%d é %.2f\n", i+1, media);
	}
	
	// máximo e mínimo
	for (i=0; i<DIM; i++)
	{
		media = soma / 3;
    	if (media > max) 
    	{
        	max = media;
        	melhor_alu = i+1;
    	}
    
    	if (media < min) 
    	{
        	min = media;
        	pior_alu = i+1;
    	}
	}		

	printf("A melhor média foi de %.2f do aluno %d.\n", max,melhor_alu);
	printf("A pior média foi de %.2f do aluno %d.\n", min, pior_alu );
}
