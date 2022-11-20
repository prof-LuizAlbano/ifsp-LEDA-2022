/**
 * @file ex04_string-iniciais.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * String: iniciais das palavras
 * 
 * Escreva um programa que gere um código de acesso para cada pessoa. O
 * código deve ser composto pelas iniciais de cada nome da pessoa. Exemplo:
 * Vanessa Andrade Lima => VAL.
 * 
 * @version 1.0
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define TAM 50

int main(void)
{
    char nome[TAM];
    char codigo[TAM/2];
    int posicao_codigo;

    printf("Digite o nome completo: ");
    gets(nome);

    if( nome[0] != '\0' )
    {
        codigo[0] = nome[0];
        posicao_codigo = 1;

        for( int i=1 ; nome[i] != '\0' ; i++ )
        {
            if( nome[i-1] == ' ' )
            {
                codigo[posicao_codigo] = nome[i];
                posicao_codigo++;
            }
        }

        codigo[posicao_codigo] = '\0';
    }

    printf("Codigo: %s", codigo);

    return 0;
}
