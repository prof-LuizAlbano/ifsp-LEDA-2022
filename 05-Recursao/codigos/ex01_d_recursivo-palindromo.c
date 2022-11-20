/**
 * @file ex01_d_recursivo-palindromo.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Palíndromo
 * 
 * Verifique se uma palavra é palíndromo (Exemplo: aba, abcba, ovo, reviver, arara, mirim, …)
 * 
 * @version 1.0
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

#define TAM 100

int testaPalindromo( char frase[], int inicio, int fim )
{
    printf("inicio: %d, fim: %d\n", inicio, fim);
    if( inicio >= fim )
        return 1;

    if ( frase[inicio] != frase[fim] )
        return 0;

    return testaPalindromo( frase, inicio+1, fim-1 );
}

int main( void )
{
    char frase[TAM];
    int tamanho;

    printf("Digite uma palavra ou frase: ");
    fgets(frase, TAM, stdin);
    tamanho = strlen( frase ) - 2;

    if( testaPalindromo( frase, 0, tamanho ) == 1 )
        printf("%s eh um palindromo\n", frase);
    else 
        printf("%s nao eh um palindromo\n", frase);
}