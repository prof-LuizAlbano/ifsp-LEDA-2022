/**
 * @file ex04_transfere-contas.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Transferência entre contas
 * 
 * Considere uma estrutura de conta corrente contendo o nome do titular, o
 * CPF e o valor na conta. Escreva uma função que receba dois ponteiros e
 * realize uma transferência entre as duas contas.
 * 
 * @version 1.0
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define TAM_NOME 50
#define TAM_CPF 11

struct Conta {
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    double saldo;
};

//Typedef "renomeia" uma estrutura de dados.
//Necessária a utilização se criarmos código para a linguagem C.
typedef struct Conta Conta;

void transfereSaldo(Conta *conta1, Conta *conta2, double valorTransferencia)
{
    if(conta1->saldo >= valorTransferencia) {
        conta1->saldo -= valorTransferencia;
        conta2->saldo += valorTransferencia;
    }
    else {
        printf("Saldo insuficiente.");
    }
}

int main( void )
{
    Conta conta1, conta2;
    double valorTransferir;

    printf("*** Dados da conta 1: ***\n");
    printf("Nome .: ");
    fgets(conta1.nome, TAM_NOME, stdin);
    printf("CPF ..: ");
    fgets(conta1.cpf, TAM_NOME, stdin);
    printf("Saldo : R$ ");
    scanf("%lf", &conta1.saldo);
    fflush(stdin);

    printf("\n*** Dados da conta 2: ***\n");
    printf("Nome .: ");
    fgets(conta2.nome, TAM_NOME, stdin);
    printf("CPF ..: ");
    fgets(conta2.cpf, TAM_NOME, stdin);
    printf("Saldo : R$ ");
    scanf("%lf", &conta2.saldo);

    printf("\n\nQuanto deseja transferir da Conta 1 para Conta 2?\nR$ ");
    scanf("%lf", &valorTransferir);

    transfereSaldo(&conta1, &conta2, valorTransferir);

    printf("\n\n*** Resultados apos transferencia ***\n");
    printf("*** Conta 01:\n");
    printf(" - Cliente: %s", conta1.nome);
    printf(" - CPF ...: %s", conta1.cpf);
    printf(" - Saldo .: R$ %.02lf\n", conta1.saldo);

    printf("\n*** Conta 02:\n");
    printf(" - Cliente: %s", conta2.nome);
    printf(" - CPF ...: %s", conta2.cpf);
    printf(" - Saldo .: R$ %.02lf\n", conta2.saldo);

    return 0;
}