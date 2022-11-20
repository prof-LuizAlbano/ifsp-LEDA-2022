/**
 * @file ex06_troca-vetor1.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Troca em Vetor I
 * 
 * Faça um programa que leia um vetor N[20]. Troque a seguir, o primeiro 
 * elemento com o último, o segundo elemento com o penúltimo, etc., até 
 * trocar o 10º com o 11º. Mostre o vetor modificado.
 * 
 * Entrada
 * 
 * A entrada contém 20 valores inteiros, positivos ou negativos.
 * 
 * Saída
 * 
 * Para cada posição do vetor N, escreva "N[i] = Y", onde i é a posição 
 * do vetor e Y é o valor armazenado naquela posição.
 * 
 * Link do exercício:
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1175
 * 
 * @version 1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define SIZE 20

int main() {
 
    int v[SIZE], aux;

    //Leitura dos números
    for( int i = 0 ; i < SIZE ; i++ )
    {
        scanf("%d", &v[i]);
    }
    
    //Troca dos números
    for(int i=0 ; i < SIZE/2 ; i++ )
    {
        aux = v[i];
        v[i] = v[SIZE-i-1]; 
        v[SIZE-i-1] = aux;
    }

    //Impressão do resultado final
    for( int i = 0 ; i < SIZE ; i++ )
    {
        printf("N[%d] = %d\n", i, v[i]);
    }

    return 0;
}