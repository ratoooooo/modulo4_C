#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100

//int
void num_int(int num[MAX], int tam );
void mostar_num(int num[MAX], int tam );
void ordemcres(int num[MAX], int tam);
void ordemdecres(int num[MAX], int tam);
//char
void pre_char(char caracter[MAX], int tam );
void mostar_char(char caracter[MAX], int tam );
void creschar(char caracter[MAX], int tam );
void decreschar(char caracter[MAX], int tam );
void main()
{
	int num[MAX];
	int tam;
	char caracter[MAX];
	
	printf("Insira o tamanho da array de inteiros: \n");
	scanf("%d", &tam);
	
	//escrever os numeros inteiros
	num_int(num, tam );
	
	//Mostrar os numeros inteiroa
	printf("Array de numeros inteiros\n");
	mostar_num(num, tam );
	
	//Ordenar por ordem crescente
	printf("\nA array por ordem crescente\n");	
	ordemcres(num, tam);
	mostar_num(num, tam );
		
	//ordenar por ordem decrescente
	printf("\nA array por ordem decrescente\n");	
	ordemdecres(num, tam);
	mostar_num(num, tam );
	printf("\n");
	
	system("pause");
	system("cls");
	
	printf("Insira o tamanho da array de caracteres: \n");
	scanf("%d", &tam);
	
	//prencher array de caracteres
	pre_char(caracter, tam);
	
	//Mostrar array de caracteres
	printf("Array de caracteres\n");
	mostar_char(caracter, tam);
	

	//Ordenar por ordem crescente
	printf("\nA array por ordem crescente\n");	
	creschar(caracter, tam);
	mostar_char(caracter, tam);
	
		
	//ordenar por ordem decrescente
	printf("\nA array por ordem decrescente\n");	
	decreschar(caracter, tam);
	mostar_char(caracter, tam);

}
void num_int(int num[MAX], int tam )
{
	int i;
	printf("Inisra os %d numeros inteiros: \n", tam);
	for (i = 0; i < tam; i++)
	{
		scanf("%d", &num[i]);
	}
}

void mostar_num(int num[MAX], int tam )
{
	int i;
	for( i= 0; i<tam; i++)
	{
		printf(" %d", num[i]);
	}
}

void ordemcres(int num[MAX], int tam)
{
    int atu;
    int i, j;
    for ( i = 0; i < tam; i++)
	{
        for ( j = i + 1; j < tam; j++) 
		{
            if (num[i] > num[j]) 
			{
                atu = num[i];
                num[i] = num[j];
                num[j] = atu;
            }
        }
    }
}

void ordemdecres(int num[MAX], int tam)
{
    int atu;
    int i, j;
    for ( i = 0; i < tam; i++)
    {
        for ( j = i + 1; j < tam; j++) 
        {
            if (num[i] < num[j]) 
            {
                atu = num[i];
                num[i] = num[j];
                num[j] = atu;
            }
        }
    }
}

void pre_char(char caracter[MAX], int tam )
{
	int i;
	printf("Inisra os %d caracteres: \n", tam);
	for (i = 0; i < tam; i++)
	{
		scanf(" %c", &caracter[i]);
	}
}

void mostar_char(char caracter[MAX], int tam )
{
	int i;
	for( i= 0; i<tam; i++)
	{
		printf(" %c", caracter[i]);
	}
}

void creschar(char caracter[MAX], int tam )
{
    char atu;
    int i, j;
    for ( i = 0; i < tam; i++)
	{
        for ( j = i + 1; j < tam; j++) 
		{
            if (caracter[i] > caracter[j]) 
			{
                atu = caracter[i];
                caracter[i] = caracter[j];
                caracter[j] = atu;
            }
        }
    }
}

void decreschar(char caracter[MAX], int tam )
{
    char atu;
    int i, j;
    for ( i = 0; i < tam; i++)
    {
        for ( j = i + 1; j < tam; j++) 
        {
            if (caracter[i] < caracter[j]) 
            {
                atu = caracter[i];
                caracter[i] = caracter[j];
                caracter[j] = atu;
            }
        }
    }
}
