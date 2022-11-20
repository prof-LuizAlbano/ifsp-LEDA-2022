/**
 * @file ex01_b_recursivo-inverte-string.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Inversão de string
 * 
 * Inversão de uma string através de um método recursivo.
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

void inverteString( char frase[], int inicio, int fim )
{
    char temp;

    if( inicio >= fim )
        return;

    temp = frase[fim];
    frase[fim] = frase[inicio];
    frase[inicio] = temp;

    inverteString( frase, inicio+1, fim-1);
}

int main( void )
{
    char frase[TAM];
    int tamanho;

    printf("Digite uma palavra ou frase: ");
    fgets(frase, TAM, stdin);
    tamanho = strlen( frase ) - 2;

    inverteString( frase, 0, tamanho );

    printf("Resultado apos inversao:\n%s", frase);
}