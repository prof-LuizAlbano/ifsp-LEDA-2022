/**
 * @file ex02_diferenca-datas.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Diferença entre Datas
 * 
 * Escreva um programa que receba dois structs do tipo dma, cada um
 * representando uma data válida, e calcule o número de dias que
 * decorreram entre as duas datas.
 * 
 * @version 1.0
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

struct dma {
    int dia;
    int mes;
    int ano;
};

//Typedef "renomeia" uma estrutura de dados.
//Necessária a utilização se criarmos código para a linguagem C.
typedef struct dma dma;

int calculaDiferenca( dma d1, dma d2 )
{
    int diff, days1, days2;

    //Converte as datas para dias
    days1 = d1.dia + ( d1.mes * 30 ) + (d1.ano * 365 );
    days2 = d2.dia + ( d2.mes * 30 ) + (d2.ano * 365 );

    return ( days1 > days2 )
        ? days1 - days2
        : days2 - days1;
}

int main( void )
{
    dma d1, d2;
    int diff;

    printf("Informe uma data no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &d1.dia, &d1.mes, &d1.ano);

    printf("Informe outra data no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &d2.dia, &d2.mes, &d2.ano);

    diff = calculaDiferenca(d1, d2);

    printf("A diferenca de dias entre as datas e igual a: %d dias", diff);

    return 0;
}