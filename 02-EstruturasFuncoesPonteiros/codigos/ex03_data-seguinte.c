/**
 * @file ex03_data-seguinte.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Data seguinte
 * 
 * Escreva uma função que receba um ponteiro para uma struct do tipo data
 * (dia, mês e ano) e retorne um ponteiro para a data do dia seguinte.
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


/**
 * Funções auxiliares para sucessão da data
 */
int ehAnoBissexto(int ano)
{
    if( ano % 400 == 0) {
        return 1;
    }
    else {
        if( ano % 100 == 0) {
            return 0;
        }
        else {
            return (ano % 4 == 0 ) ? 1 : 0;
        }
    }
}

int maximoDiaMes(int mes, int ano)
{
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes== 8 || mes==10 || mes==12 ) {
        return 31;
    }
    else if( mes == 2) {
        return ehAnoBissexto(ano) == 1 ? 29 : 28; 
    }
    else {
        return 30;
    }
}


dma* diaSucessor(dma *data)
{
    dma *diaSeguinte = (dma*) malloc(sizeof(dma));

    if( data->dia < maximoDiaMes(data->mes, data->ano) ) {
        diaSeguinte->dia = data->dia + 1;
        diaSeguinte->mes = data->mes;
        diaSeguinte->ano = data->ano;
    }
    else if( data->dia == maximoDiaMes(data->mes, data->ano) ) {
        diaSeguinte->dia = 1;

        if( data->mes == 12 ) {
            diaSeguinte->mes = 1;
            diaSeguinte->ano = data->ano + 1;
        }
        else {
            diaSeguinte->mes = data->mes + 1;
            diaSeguinte->ano = data->ano;
        }
    }

    return diaSeguinte;
}

int main( void )
{
    dma d1, *d2;

    printf("Informe uma data no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &d1.dia, &d1.mes, &d1.ano);

    d2 = diaSucessor(&d1);

    printf("Data informada: %02d/%02d/%04d\n", d1.dia, d1.mes, d1.ano);
    printf("Data sucessora: %02d/%02d/%04d", d2->dia, d2->mes, d2->ano);

    return 0;
}