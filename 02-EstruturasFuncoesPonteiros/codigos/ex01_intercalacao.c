/**
 * @file ex01_intercalacao.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Intercalação de strings
 * 
 * Escreva uma função que receba duas strings e retorne a intercalação letra
 * a letra da primeira com a segunda string. Considere a seguinte assinatura:
 * 
 * void intercala_strings(char *v1, char *v2, char *v3)
 * 
 * @version 1.0
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define PALAVRA 10

void intercala( char *v1, char *v2, char *v3 )
{
    for( int i=0 ; i < PALAVRA ; i++ )
    {
        v3[i*2] = v1[i];
        v3[i*2+1] = v2[i];
    }
}

int main( void )
{
    char v1[PALAVRA], v2[PALAVRA], v3[PALAVRA*2];

    printf("Digite uma palavra: ");
    fgets( v1, PALAVRA, stdin );

    printf("Digite outra palavra: ");
    fgets( v2, PALAVRA, stdin );

    intercala( v1, v2, v3 );

    printf("Intercalacao: %s", v3);

    return 0;
}