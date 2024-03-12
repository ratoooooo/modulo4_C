#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define LINHA 3
#define COLUNA 3
#define ARRAY 9

void menu(int num[LINHA][COLUNA]);
void ordena_matriz(int num[LINHA][COLUNA]);
int remover_elem(int num[][COLUNA], int remove, int numatu);

void main()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    char op;
    int num[LINHA][COLUNA] = {{0}};
    int element = 0, rem_ele, encontrou, j, i;

    do
    {
        system("cls");
        menu(num);
        scanf(" %c", &op);
        switch (toupper(op))
        {
            case 'I':
                if (element < LINHA*COLUNA)
                {
                    printf("Insira um elemento: ");
                    scanf("%d", &num[element][element]);
                    ordena_matriz(num);
                    element++;
                }
                else
                    printf("A matriz está cheia.\n");
                break;
                
            case 'R':
			    if (element > 0)
			    {
			        printf("Insira o elemento que deseja remover: ");
			        scanf("%d ", &rem_ele);
			        encontrou = remover_elem(num, rem_ele, element);
			        if (encontrou)
			        {
			            printf("Elemento removido com sucesso.\n");
			            element--;
			        }
			        else
			        {
			            printf("Elemento não encontrado.\n");
			        }
			    }
			    
			    else
			    {
			        printf("A matriz está vazia.\n");
			    }
			    break;

            case 'S':
                printf("Obrigado por usar o programa.\n");
                break;

            default:
                printf("Operação inválida.\n");
        }
    } while (op != 'S');

}

void menu(int num[LINHA][COLUNA])
{
	int i, j;
	for (i=0; i<LINHA; i++)
	{
		for (j=0; j <COLUNA; j++)
		{
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
	
    printf(".______________.\n");
    printf("|____ Menu ____|\n");
    printf("|              |\n");
    printf("| i - Inserir  |\n");
    printf("| r - Remover  |\n");
    printf("| s - Sair     |\n");
    printf("|______________|\n");
    printf("-> ");
    
}

void ordena_matriz(int num[LINHA][COLUNA]) 
{
	int atu;
    int i, j, k=0;
    int arraynum[ARRAY];
    
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
    for ( i = 0; i < ARRAY; i++)
	{
        for ( j = i + 1; j < ARRAY; j++) 
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

int remover_elem(int num[][COLUNA], int remove, int numatu)
{
    int i, j, encontrou_elem = 0;

    for (i = 0; i < numatu; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            if (remove == num[i][j] || encontrou_elem == 1)
            {
                num[i][j] = num[i][j + 1];
                encontrou_elem = 1;
            }
        }
        
        if (encontrou_elem)
        {
            num[i][COLUNA - 1] = 0; 
            break;
        }
    }

    return encontrou_elem;
}

