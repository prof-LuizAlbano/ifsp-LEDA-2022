/**
 * @file ex01_c_recursivo-soma-multiplicacao.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Soma e produto dos elementos de um vetor
 * 
 * A partir de um vetor de números inteiros, calcule a soma e o produto dos elementos do vetor.
 * 
 * @version 1.0
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

#define TAM 6

int somaRecursiva( int numeros[], int tam )
{
    if( tam == 0 )
        return numeros[tam];

    return numeros[tam] + somaRecursiva( numeros, tam-1 );
}

int multiplicacaoRecursiva( int numeros[], int tam )
{
    if( tam == 0 )
        return numeros[tam];

    return numeros[tam] * somaRecursiva( numeros, tam-1 );
}

int main( void )
{
    int num[TAM] = { 5, 6, 7, 2, 3, 4 };
    int resSoma, resMult;

    resSoma = somaRecursiva( num, 5 );
    resMult = multiplicacaoRecursiva( num, 5 );

    printf("Soma: %d\n", resSoma);
    printf("Multiplicacao: %d", resMult);

}