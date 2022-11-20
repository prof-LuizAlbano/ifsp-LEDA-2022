/**
 * @file ex02_ordenacao-struct.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * 
 * Ordenação de estruturas
 * 
 * Elabore uma estrutura que armazene dados de 30 funcionários de uma 
 * empresa. Deverão ser considerados os campos: código funcional 
 * (valor numérico/inteiro), nome (string), salário (valor 
 * numérico/real) e data de admissão.
 * 
 * - Preencha a estrutura com dados fornecidos pelo usuário;
 * - Ordene os campos pelo código funcional (utilizar o algoritmo de 
 *   seleção [selection sort] ou inserção [insertion sort]);
 * - Crie uma rotina para encontrar dados de um funcionário pelo seu 
 *   código funcional.
 * 
 * @version 1.0
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

#define TAM 3

struct Funcionario {
    int codigo_funcional;
    char nome[30];
    double salario;
    char data_admissao[10];
};

typedef struct Funcionario Funcionario;

void imprimeDados(Funcionario *f)
{
    printf("Cod. Funcional .: %d\n", f->codigo_funcional);
    printf("Nome ...........: %s", f->nome);
    printf("Salario ........: %.2lf\n", f->salario);
    printf("Data Admissao ..: %s", f->data_admissao);
}

void imprimeFuncionarios(Funcionario funcionarios[])
{
    for( int i=0 ; i < TAM ; i++ )
    {
        printf("\n=> Funcionario %d\n", i+1);
        imprimeDados(&funcionarios[i]);
    }
}

void preencheDados(Funcionario funcionarios[])
{
    for( int i=0 ; i < TAM ; i++ )
    {
        printf("Cod. Funcional .: ");
        scanf("%d", &funcionarios[i].codigo_funcional );
        fflush(stdin);  // __fpurge( stdin );

        printf("Nome ...........: ");
        fgets( funcionarios[i].nome, 30, stdin);
        fflush(stdin);  // __fpurge( stdin );

        printf("Salario ........: ");
        scanf("%lf", &funcionarios[i].salario );
        fflush(stdin);  // __fpurge( stdin );

        printf("Data Admissao ..: ");
        fgets( funcionarios[i].data_admissao, 20, stdin);
        fflush(stdin);  // __fpurge( stdin );
    }
}

Funcionario* localizaFuncionario(Funcionario funcionarios[], int codigoFuncional)
{
    for (int i = 0; i < TAM; i++)
    {
        if( funcionarios[i].codigo_funcional == codigoFuncional ) {
            return &funcionarios[i];
        }
    }
    
    return NULL;
}

void insertionSort(Funcionario funcionarios[]){
   int i, j=0;
   Funcionario f;

   for ( i=1 ; i<TAM ; i++) {
     f = funcionarios[i];
     j = i - 1;
     while (j >= 0 && f.codigo_funcional < funcionarios[j].codigo_funcional) {
        funcionarios[j+1] = funcionarios[j];
        j = j - 1;
     }

     funcionarios[j+1] = f;
   }
}


int main( void )
{
    Funcionario funcionarios[TAM], *f = NULL;
    int op = -1, codigoBusca;

    do {
        printf("===  Cadastro Funcionários  ===\n");
        printf("= 1 - Cadastrar Funcionarios  =\n");
        printf("= 2 - Localizar Funcionario   =\n");
        printf("= 3 - Imprimir Funcionarios   =\n");
        printf("= 0 - Sair                    =\n");
        printf("= Opcao > ");
        scanf("%d", &op);
        fflush(stdin);  // __fpurge( stdin );

        switch( op ) {
            case 1: 
                preencheDados(funcionarios);
                insertionSort(funcionarios);
                break;

            case 2: 
                printf("\nCodigo Funcional: ");
                scanf("%d", &codigoBusca);
                fflush(stdin);  // __fpurge( stdin );
                f = localizaFuncionario(funcionarios, codigoBusca);

                if( f != NULL ) {
                    imprimeDados(f);
                }
                else {
                    printf("\nFuncionário não localizado.\n");
                }
                break;

            case 3: 
                imprimeFuncionarios(funcionarios); 
                break;
        }

    } while( op != 0);
    
    return 0;
}