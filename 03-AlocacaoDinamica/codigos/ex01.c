/**
 * @file ex01.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Alocação de memória
 * 
 * Faça um programa para armazenar em memória um vetor de dados contendo 
 * 1500 valores do tipo int, usando a função de alocação dinâmica de memória
 * CALLOC:
 * 
 * a) Faça um loop e verifique se o vetor contém realmente os 1500 valores
 *    inicializados com zero (conte os 1500 zeros do vetor).
 * b) Atribua para cada elemento do vetor um valor randômico (utilize a função
 *    rand).
 * c) Exibir na tela os 10 primeiros e os 10 últimos elementos do vetor.
 * 
 * @version 1.0
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define TAM 1500

int main() {
    int *num;
    int qtdeZeros=0;

    // Alocação de memória
    num = (int *)calloc(TAM ,sizeof(int));	

    // Item a: verifica se todos as posições contém 0s
    for(int i=0 ; i < TAM ; i++) {
        if(num[i] == 0)
            qtdeZeros++;
    }

    printf("Posicoes com o valor 0: %d\n", qtdeZeros);

    // Item b: preenche com valores randomicos
    for(int i=0 ; i < TAM ; i++) {
        num[i] = rand() % 1500;
    }

    // Item c: exibe os 10 primeiros e os 10 últimos
    printf("\n10 primeiros elementos: ");
    for(int i=0 ; i < 10 ; i++)
        printf("%d ", num[i]);

    printf("\n10 último elementos: ");
    for(int i=TAM-10 ; i < TAM ; i++)
        printf("%d ", num[i]);

    return 0;
}