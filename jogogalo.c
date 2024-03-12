#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define PLAY 2
#define TAM_MAX 10

int checkWinner(char jogo[][TAM_MAX], int tam);
void main()
{
    system("cls");
    int tam;
    printf("Insira o tamanho do jogo: ");
    scanf("%d", &tam);

    int i, j, linha, coluna, jogada = 0;
    char jogo[TAM_MAX][TAM_MAX];
    char nome[PLAY][20];
    char simb[PLAY][2];

    for (i = 0; i < PLAY; i++)
    {
        printf("Nome do jogador %d: ", i + 1);
        scanf("%s", nome[i]);
        printf("Introduza o seu símbolo: ");
        scanf(" %c", &simb[i][0]);
    }

    system("pause");
    system("cls");

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            jogo[i][j] = ' ';
        }
    }

    while (jogada < tam * tam && !checkWinner(jogo, tam))
    {
        for (i = 0; i < tam; i++)
        {
            for (j = 0; j < tam; j++)
            {
                printf("%c", jogo[i][j]);
                if (j != tam - 1)
                    printf(" | ");
            }
            printf("\n");

            if (i != tam - 1)
            {
                for (j = 0; j < tam; j++)
                {
                    if (j != tam - 1)
                        printf("_____");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }

        i = jogada % PLAY;
        printf("%s, sua vez de jogar\n", nome[i]);
        printf("Digite o número da linha: ");
        scanf("%d", &linha);
        printf("Digite o número da coluna: ");
        scanf("%d", &coluna);

        if (linha >= 1 && linha <= tam && coluna >= 1 && coluna <= tam && jogo[linha - 1][coluna - 1] == ' ')
        {
            jogo[linha - 1][coluna - 1] = simb[i][0];
            jogada++;
        }
        else
        {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        system("cls");
    }

    if (checkWinner(jogo, tam))
    {
        printf("%s venceu!\n", nome[i]);
    }
    else
    {
        printf("Ninguém venceu. O jogo terminou em empate.\n");
	}	
}

int checkWinner(char jogo[][TAM_MAX], int tam)
{
    int i, j;

    // Verificar linhas
    for (i = 0; i < tam; i++)
    {
        int linha_vencedora = 1;
        for (j = 1; j < tam; j++)
        {
            if (jogo[i][j] != jogo[i][0] || jogo[i][j] == ' ')
            {
                linha_vencedora = 0;
                break;
            }
        }
        if (linha_vencedora == 1)
            return 1;
    }

    // Verificar colunas
    for (j = 0; j < tam; j++)
    {
        int coluna_vencedora = 1;
        for (i = 1; i < tam; i++)
        {
            if (jogo[i][j] != jogo[0][j] || jogo[i][j] == ' ')
            {
                coluna_vencedora = 0;
                break;
            }
        }
        if (coluna_vencedora == 1)
            return 1;
    }

    // Verificar diagonal principal
    int diagonal_principal_vencedora = 1;
    for (i = 1; i < tam; i++)
    {
        if (jogo[i][i] != jogo[0][0] || jogo[i][i] == ' ')
        {
            diagonal_principal_vencedora = 0;
            break;
        }
    }
    if (diagonal_principal_vencedora == 1)
        return 1;

    // Verificar diagonal secundária
    int diagonal_secundaria_vencedora = 1;
    for (i = 1; i < tam; i++)
    {
        if (jogo[i][tam - 1 - i] != jogo[0][tam - 1] || jogo[i][tam - 1 - i] == ' ')
        {
            diagonal_secundaria_vencedora = 0;
            break;
        }
    }
    if (diagonal_secundaria_vencedora == 1)
        return 1;

	//ninbguem ganhou = empate
    return 0;  
}



