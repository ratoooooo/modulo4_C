#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

void menu(int num[MAX], int numatu);

void ordenar(int num[MAX], int tam);
void main()
{
	setlocale(LC_ALL, "Portuguese");
    system("cls");
    
	char op;
	int num[MAX];
	int numatu = 0, nume;
	
	do
	{
		system("cls");
		menu(num, numatu);
		scanf(" %c", &op);
		switch(toupper(op))
		{
			case 'I':
				printf("Elemento a inserir: ");
				scanf("%d", &num[numatu]);
				numatu++;
				ordenar(num, numatu);
				break;
			case 'R':
			    printf("Remova um número: ");
               	scanf("%d", &num[numatu]);
                
                if ( num[numatu] == num[0])
				{
					printf("O array esta vazio");
				}
				
				if (num[numatu] > num[5] )
				{
					printf("O array esta cheio");
				}
				num[numatu]--;
				break;
			case 'S':
				printf("Obrigado por usar o programa");
				break;
				
			default:
            	printf("Operação invalida\n");
		}
	}while ( op != 'S');
}

void menu(int num[MAX], int numatu)
{
	int i;
	
	printf("Array [");
	for (i=0; i < numatu; i++)
	{
		printf("%d ", num[i]);	
	} 
	printf("] \n");

	
    printf(".______________.\n");
    printf("|____ Menu ____|\n");
    printf("|              |\n");
    printf("| i - Inserir  |\n");
    printf("| r - Remover  |\n");
    printf("| s - Sair     |\n");
    printf("|______________|\n");
    printf("-> ");
    
}


void ordenar(int num[MAX], int tam)
{
	int temp;
    int i, j;
    int atu = MAX;
		
	//ordenar
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

