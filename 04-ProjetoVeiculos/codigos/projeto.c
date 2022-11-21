/**
 * @file ex01.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Projeto - Cadastro de Veiculos
 * 
 * Escreva um programa em C/C++ para realizar um pequeno controle de uma 
 * agência de veículos. O sistema deverá ser responsável por realizar as 
 * seguintes operações, armazenando os dados em memória: cadastrar um novo 
 * veículo, listar os veículos cadastrados e localizar um veículo. Planeje 
 * seu projeto para a utilização correta de funções, visando uma boa 
 * organização do código, reaproveitamento de código e boa leitura.
 * 
 * @version 1.0
 * @date 2022-10-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEMS 5
#define PLACA_SIZE 9
#define SIZE 10

typedef struct ListaVeiculos ListaVeiculos;
typedef struct Veiculo Veiculo;

struct ListaVeiculos {
    Veiculo *lista;
    int qtde;
};

struct Veiculo {
    char placa[PLACA_SIZE];
    int anoFabricacao;
    char marca[SIZE];
    char modelo[SIZE];
    char cor[SIZE];
    double valorVenda;
};

ListaVeiculos* init()
{
    ListaVeiculos *lista = (ListaVeiculos*) calloc(1, sizeof(ListaVeiculos));

    lista->lista = NULL;
    lista->qtde = 0;

    return lista;
}


int menu()
{
    int op;

    printf("**************************************************\n");
    printf("**               Sistema Veiculos               **\n");
    printf("**************************************************\n");
    printf("** 1 - Cadastrar novo Veículo                   **\n");
    printf("** 2 - Listar Veículos                          **\n");
    printf("** 3 - Buscar Veículo por Placa                 **\n");
    printf("** 4 - Buscar Veículo por Ano de Fabricação     **\n");
    printf("** 5 - Sair                                     **\n");
    printf("**************************************************\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    return op;
}

Veiculo lerDados()
{
    Veiculo novo;

    fflush(stdin);
    printf("Placa..: ");
    fgets(novo.placa, PLACA_SIZE, stdin);
    fflush(stdin);

    printf("Ano....: ");
    scanf("%d", &novo.anoFabricacao);
    fflush(stdin);

    printf("Marca..: ");
    fgets(novo.marca, SIZE, stdin);
    novo.marca[strlen(novo.marca)-1] = '\0';
    fflush(stdin);

    printf("Modelo.: ");
    fgets(novo.modelo, SIZE, stdin);
    novo.modelo[strlen(novo.modelo)-1] = '\0';
    fflush(stdin);

    printf("Cor....: ");
    fgets(novo.cor, SIZE, stdin);
    novo.cor[strlen(novo.cor)-1] = '\0';
    fflush(stdin);

    printf("Valor..: ");
    scanf("%lf", &novo.valorVenda);
    fflush(stdin);

    return novo;
}

void inserirNovo(ListaVeiculos *veiculos)
{
    Veiculo novo = lerDados();

    if(veiculos->lista == NULL) {
        veiculos->lista = (Veiculo*) calloc(1, sizeof(Veiculo));
        veiculos->lista[0] = novo;
        veiculos->qtde = 1;
    }
    else {
        veiculos->qtde++;
        veiculos->lista = (Veiculo*) realloc(veiculos->lista, (int)veiculos->qtde * sizeof(Veiculo));
        veiculos->lista[veiculos->qtde-1] = novo;
    }
}

void listarVeiculos(ListaVeiculos *veiculos) {
    printf("=== Lista de Veiculos ===\n");
    printf("%-8s | %-4s | %-10s | %-10s | %-10s | %-10s \n", "Placa", "Ano", "Modelo", "Marca", "Cor", "Valor");

    for(int i=0 ; i < veiculos->qtde ; i++ ) {
        printf("%-8s | %04d | %-10s | %-10s | %-10s | %10.2lf \n", 
            veiculos->lista[i].placa,
            veiculos->lista[i].anoFabricacao,
            veiculos->lista[i].modelo,
            veiculos->lista[i].marca,
            veiculos->lista[i].cor,
            veiculos->lista[i].valorVenda
        );
    }

    printf("\n");
}


void buscarPorPlaca(ListaVeiculos *veiculos) {
    char placa[PLACA_SIZE];

    fflush(stdin);
    printf("=== Busca por placa ===\n");
    printf("Placa.: ");
    fgets(placa, PLACA_SIZE, stdin);
    fflush(stdin);

    for(int i=0 ; i < veiculos->qtde ; i++ ) {
        if( strcmp( veiculos->lista[i].placa, placa) == 0 ) {
            printf("\n%-8s | %-4s | %-10s | %-10s | %-10s | %-10s \n", "Placa", "Ano", "Modelo", "Marca", "Cor", "Valor");
            printf("%-8s | %04d | %-10s | %-10s | %-10s | %10.2lf \n", 
                veiculos->lista[i].placa,
                veiculos->lista[i].anoFabricacao,
                veiculos->lista[i].modelo,
                veiculos->lista[i].marca,
                veiculos->lista[i].cor,
                veiculos->lista[i].valorVenda
            );

            return;
        }
    }

    printf("Veiculo nao localizado.\n");
}

void buscarPorAno(ListaVeiculos *veiculos) {
    int anoInicio, anoFim, encontrou=0;

    fflush(stdin);
    printf("=== Busca por Ano de Fabricacao ===\n");
    printf("Ano Inicio.: ");
    scanf("%d", &anoInicio);
    printf("Ano Final..: ");
    scanf("%d", &anoFim);
    fflush(stdin);

    printf("\n%-8s | %-4s | %-10s | %-10s | %-10s | %-10s \n", "Placa", "Ano", "Modelo", "Marca", "Cor", "Valor");

    for(int i=0 ; i < veiculos->qtde ; i++ ) {
        if( veiculos->lista[i].anoFabricacao >= anoInicio && veiculos->lista[i].anoFabricacao <= anoFim )
        {
            printf("%-8s | %04d | %-10s | %-10s | %-10s | %10.2lf \n", 
                veiculos->lista[i].placa,
                veiculos->lista[i].anoFabricacao,
                veiculos->lista[i].modelo,
                veiculos->lista[i].marca,
                veiculos->lista[i].cor,
                veiculos->lista[i].valorVenda
            );

            encontrou = 1;
        }
    }

    if( encontrou == 0 )
        printf("Veiculo nao localizado.\n");
}



int main() {
    ListaVeiculos *veiculos = init();
    int op;

    do {
        op = menu();

        switch( op ) {
            case 1: //Cadastrar novo veículo
                inserirNovo(veiculos);
                break;

            case 2: //Listar veiculos
                listarVeiculos(veiculos);
                break;

            case 3: //Busca por placa
                buscarPorPlaca(veiculos);
                break;

            case 4: //Busca por ano de fabricação
                buscarPorAno(veiculos);
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while( op != 5 );

    return 0;
}