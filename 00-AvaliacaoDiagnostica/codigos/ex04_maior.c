/**
 * @file ex04_maior.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * O Maior
 * 
 * Faça um programa que leia três valores e apresente o maior dos três valores 
 * lidos seguido da mensagem “eh o maior”. Utilize a fórmula:
 * 
 * MaiorAB = (a+b+abs(a-b)) / 2
 * 
 * Obs.: a fórmula apenas calcula o maior entre os dois primeiros (a e b). 
 * Um segundo passo, portanto é necessário para chegar no resultado esperado.
 * 
 * Entrada
 * 
 * O arquivo de entrada contém três valores inteiros.
 * 
 * Saída
 * 
 * Imprima o maior dos três valores seguido por um espaço e a mensagem "eh o maior".
 * 
 * Link do exercício:
 * https://www.beecrowd.com.br/judge/pt/problems/view/1013
 * 
 * @version 1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
 
    int n1, n2, n3, higher;

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    
    higher = ( n1 + n2 + abs(n1 - n2) ) / 2;
    higher = ( higher + n3 + abs(higher - n3) ) / 2;
    
    printf("%d eh o maior\n", higher);

    return 0;
}