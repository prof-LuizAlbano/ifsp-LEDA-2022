/**
 * @file ex02.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Faça um programa que simule a memória de um computador: o usuário irá
 * especificar o tamanho da memória, ou seja, quantos bytes serão alocados do
 * tipo inteiro. Para tanto, a memória solicitada deve ser um valor múltiplo do
 * tamanho do tipo inteiro. Em seguida, o usuário terá 2 opções: inserir um valor em
 * uma determinada posição ou consultar o valor contido em uma determinada
 * posição. A memória deve iniciar com todos os dados zerados.
 * 
 * @version 1.0
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
    int *num;
    int mem_size=0, op, pos, value;

    do {
        printf("Informe o tamanho de memoria desejado: ");
        scanf("%d", &mem_size);

        if( mem_size % 4 != 0) {
            printf("Tamanho invalido, informe um multiplo de 4.\n");
        }

    } while( mem_size % 4 != 0);

    //Alocação da memória
    num = (int *)calloc(mem_size, sizeof(int));	

    do {
        printf("=== Opcoes ===\n");
        printf("1 - Inserir valor\n");
        printf("2 - Consultar valor\n");
        printf("3 - Sair\n");
        printf("> ");
        scanf("%d", &op);

        switch( op ) {
            case 1:
                printf("Valor a ser inserido: ");
                scanf("%d", &value);
                printf("Posicao: ");
                scanf("%d", &pos);

                if(pos < mem_size) {
                    num[pos] = value;
                }
                else {
                    printf("Posicao invalida.\n");
                }
                break;

            case 2:
                printf("Posicao: ");
                scanf("%d", &pos);

                if(pos < mem_size) {
                    printf("Valor: %d\n\n", num[pos]);
                }
                break;
        }

    } while( op != 3 );


    return 0;
}