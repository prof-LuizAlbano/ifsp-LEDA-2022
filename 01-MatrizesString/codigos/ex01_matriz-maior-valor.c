/**
 * @file ex01_matriz-maior-valor.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Matriz: maior valor
 * 
 * Escreva um programa que leia números para uma matriz 5x5. Em seguida,
 * imprima os valores contidos na matriz e retorne a localização (linha e 
 * coluna) do maior valor.
 * 
 * @version 1.0
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define TAM 5

int main(void)
{
    int numeros[TAM][TAM];
    int maior = 0, maior_linha, maior_coluna;

    //Leitura dos números
    for( int i=0 ; i < TAM ; i++ )
    {
        for( int j = 0 ; j < TAM ; j++ )
        {
            printf("Digite um numero para [%d][%d]", i, j);
            scanf("%d", &numeros[i][j]);
        }
    }

    //Imprime e Localiza maior valor
    for( int i=0 ; i < TAM ; i++ )
    {
        for( int j = 0 ; j < TAM ; j++ )
        {
            printf(" %d ", numeros[i][j]);
            if( numeros[i][j] > maior )
            {
                maior = numeros[i][j];
                maior_linha = i;
                maior_coluna = j;
            }
        }
        printf("\n");
    }

    printf("Maior valor: %d\n", maior);
    printf("Posicao (linha - coluna): [%d][%d]\n", maior_linha, maior_coluna);

    return 0;
}
