/**
 * @file ex05_vetor1.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Preenchimento de Vetor I
 * 
 * Leia um valor e faça um programa que coloque o valor lido na primeira 
 * posição de um vetor N[10]. Em cada posição subsequente, coloque o dobro 
 * do valor da posição anterior. Por exemplo, se o valor lido for 1, os 
 * valores do vetor devem ser 1,2,4,8 e assim sucessivamente. Mostre o 
 * vetor em seguida.
 * 
 * Entrada
 * 
 * A entrada contém um valor inteiro (V<=50).
 * 
 * Saída
 * 
 * Para cada posição do vetor, escreva "N[i] = X", onde i é a posição do 
 * vetor e X é o valor armazenado na posição i. O primeiro número do vetor 
 * N (N[0]) irá receber o valor de V.
 * 
 * Link do exercício:
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1173
 * 
 * @version 1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define SIZE 10

int main() {
 
    int v[SIZE];

    scanf("%d", &v[0]);
    printf("N[0] = %d\n", v[0]);
    
    for(int i=1 ; i < SIZE ; i++ )
    {
        v[i] = v[i-1] * 2;
        printf("N[%d] = %d\n", i, v[i]);
    }

    return 0;
}