/**
 * @file ex07_coluna-matriz.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Coluna na Matriz
 * 
 * Neste problema você deve ler um número que indica uma coluna de uma 
 * matriz na qual uma operação deve ser realizada, um caractere maiúsculo, 
 * indicando a operação que será realizada, e todos os elementos de uma 
 * matriz M[12][12]. Em seguida, calcule e mostre a soma ou a média dos 
 * elementos que estão na área verde da matriz, conforme for o caso. A 
 * imagem abaixo ilustra o caso da entrada do valor 5 para a coluna da 
 * matriz, demonstrando os elementos que deverão ser considerados na 
 * operação.
 * 
 * Entrada
 * 
 * A primeira linha de entrada contem um número C (0 ≤ C ≤ 11) indicando 
 * a coluna que será considerada para operação. A segunda linha de entrada 
 * contém um único caractere Maiúsculo T ('S' ou 'M'), indicando a operação 
 * (Soma ou Média) que deverá ser realizada com os elementos da matriz. 
 * Seguem os 144 valores de ponto flutuante que compõem a matriz.
 * 
 * Saída
 * 
 * Imprima o resultado solicitado (a soma ou média), com 1 casa após 
 * o ponto decimal.
 * 
 * Link do exercício:
 * https://www.beecrowd.com.br/judge/pt/problems/view/1182
 * 
 * @version 1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define SIZE 3

int main() {
 
    char op;
    double M[SIZE][SIZE], avg=0, sum=0;
    int col;
    int x=0, y=-1; //Auxiliares para preenchimento da matriz
    
    scanf("%d", &col);
    fflush(stdin);
    scanf("%c", &op);

    //Leitura dos números
    for( int i = 0 ; i < SIZE*SIZE ; i++ )
    {
        if( i % SIZE == 0 )
            y = y + 1;
        
        scanf("%lf", &M[y][i%SIZE]);

        //Soma os valores da coluna indicado
        if( col == i%SIZE ) 
        {
            sum += M[y][i%SIZE];
        }  
    }

    if( op == 'S' )
    {
        printf("%.1lf\n", sum);
    }
    else
    {
        avg = (double)sum / SIZE;
        printf("%.1lf\n", avg);
    }

    return 0;
}