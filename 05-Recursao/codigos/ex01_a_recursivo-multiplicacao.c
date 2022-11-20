/**
 * @file ex01_a_recursivo-multiplicacao.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Multiplicação recursiva por soma
 * 
 * Multiplicação de dois números naturais, através de somas sucessivas 
 * Exemplo: 6 * 4 = 4 + 4 + 4 + 4 + 4 + 4
 * 
 * @version 1.0
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int multiplicaRecursivo(int n1, int n2)
{
    int resultado = 0;

    if( n1 == 1 )
        return n2;

    resultado = n2 + multiplicaRecursivo(n1-1, n2);
}

int main( void )
{
    int num1, num2, res;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    res = multiplicaRecursivo(num1, num2);

    printf("Resultado: %d\n", res);
}