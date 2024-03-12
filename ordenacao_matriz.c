#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define LINHA 3
#define COLUNA 3

void num_int(int num[LINHA][COLUNA]);
void num_int(int num[LINHA][COLUNA]);
void ordena_matriz(int num[LINHA][COLUNA]);
void ordemdecres(int num[LINHA][COLUNA]);

void main()
{
	int num[LINHA][COLUNA];
	
	//escrever os numeros inteiros
	printf("Prencher matriz de numeros inteiros\n");
	num_int(num);
	
	//Mostrar os numeros inteiroa
	printf("Matriz de numeros inteiros\n");
	mostrar_num(num);
	
	//Ordenar por ordem crescente
	printf("\nA matriz por ordem crescente\n");	
	ordena_matriz(num);
	mostrar_num(num);
		
	//ordenar por ordem decrescente
	printf("\nA matriz por ordem decrescente\n");	
	ordemdecres(num);
	mostrar_num(num);
	printf("\n");
	
}
void num_int(int num[LINHA][COLUNA])
{
    int i, j;
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("Linha %zu coluna %zu ", i + 1, j + 1);
            scanf("%d", &num[i][j]);
            
        }
    }
}

void mostrar_num(int num[LINHA][COLUNA])
{
    int i, j;
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
}

void ordena_matriz(int num[LINHA][COLUNA]) 
{
	int atu;
    int i, j, k=0;
    int arraynum[9];
    
    //copiar os valores da matriz para o array
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            arraynum[k] = num[i][j];
            k++;
        }
    }
    
    //ordenar o array
    for ( i = 0; i < 9; i++)
	{
        for ( j = i + 1; j < 9; j++) 
		{
            if (arraynum[i] > arraynum[j]) 
			{
                atu = arraynum[i];
                arraynum[i] = arraynum[j];
                arraynum[j] = atu;
            }
        }
    }
    
    //mandar os nuemros da rray para a matriz ja ordenados
    k = 0;
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            num[i][j] = arraynum[k];
            k++;
        }
    }
}

void ordemdecres(int num[LINHA][COLUNA])
{
	int atu;
    int i, j, k=0;
    int arraynum[9];
    
    //copiar os valores da matriz para o array
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            arraynum[k] = num[i][j];
            k++;
        }
    }
    
    //ordenar o arrray 
    for ( i = 0; i < 9; i++)
	{
        for ( j = i + 1; j < 9; j++) 
		{
            if (arraynum[i] < arraynum[j]) 
			{
                atu = arraynum[i];
                arraynum[i] = arraynum[j];
                arraynum[j] = atu;
            }
        }
    }
    
    //mandar os nuemros da rray para a matriz ja ordenados
    k = 0;
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            num[i][j] = arraynum[k];
            k++;
        }
    }
}

