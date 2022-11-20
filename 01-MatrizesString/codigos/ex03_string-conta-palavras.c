/**
 * @file ex03_string-conta-palavras.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * String: conta palavras
 * 
 * Elabore um programa em C que recebe pelo teclado uma cadeia de 
 * caracteres até 255 posições e exibe na tela um número inteiro 
 * correspondente à quantidade de palavras existentes na cadeia. Admita que 
 * as palavras podem ter um ou mais caracteres e que a separação entre elas é
 * sempre um caractere de espaço em branco.
 * 
 * @version 1.0
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define TAM 255

int main(void)
{
    char frase[TAM];
    int palavras=0;

    printf("Digite uma frase: ");
    fgets(frase, TAM, stdin);
    
    for( int i=0 ; i < TAM ||  frase[i] != '\0' ; i++) {
        if( frase[i] == ' ' )
            palavras++;
    }

    printf("Palavras: %d", palavras);

    return 0;
}
