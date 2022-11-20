/**
 * @file ex02_matriz-busca-valor.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Matriz: busca valor
 * 
 * Escreva um programa que leia números para uma matriz 5x5 e na sequência
 * leia também um número que deverá ser procurado na matriz. Após as
 * leituras, o programa deverá fazer uma busca desse valor na matriz e, ao final,
 * escrever a localização (linha e coluna) ou uma mensagem de “não
 * encontrado”.
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
    int encontrado_linha = -1, encontrado_coluna = -1, valor_procurado;

    //Leitura dos números
    for( int i=0 ; i < TAM ; i++ )
    {
        for( int j = 0 ; j < TAM ; j++ )
        {
            printf("Digite um numero para [%d][%d]", i, j);
            scanf("%d", &numeros[i][j]);
        }
    }

    printf("Informe o numero a ser procurado: ");
    scanf("%d", &valor_procurado);

    //Imprime e Localiza maior valor
    for( int i=0 ; i < TAM ; i++ )
    {
        for( int j = 0 ; j < TAM ; j++ )
        {
            if( numeros[i][j] == valor_procurado )
            {
                encontrado_linha = i;
                encontrado_coluna = j;
            }
        }
    }

    if( encontrado_linha > -1 ) {
        printf("Valor encontrado na posicao [%d][%d]", encontrado_linha, encontrado_coluna);
    }
    else {
        printf("Nao encontrado");
    }

    return 0;
}
