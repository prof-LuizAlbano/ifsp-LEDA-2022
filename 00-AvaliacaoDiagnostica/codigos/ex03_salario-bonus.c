/**
 * @file ex03_salario-bonus.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * Salário com Bônus
 * Faça um programa que leia o nome de um vendedor, o seu salário fixo e o 
 * total de vendas efetuadas por ele no mês (em dinheiro). Sabendo que este 
 * vendedor ganha 15% de comissão sobre suas vendas efetuadas, informar o 
 * total a receber no final do mês, com duas casas decimais.
 * 
 * Entrada
 * O arquivo de entrada contém um texto (primeiro nome do vendedor) e 2 
 * valores de dupla precisão (double) com duas casas decimais, representando 
 * o salário fixo do vendedor e montante total das vendas efetuadas por 
 * este vendedor, respectivamente.
 * 
 * Saída
 * Imprima o total que o funcionário deverá receber, conforme exemplo 
 * fornecido.
 * 
 * Link do exercício:
 * https://www.beecrowd.com.br/judge/pt/problems/view/1009
 * 
 * @version 1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define TAX_COMMISSION 0.15

int main() {
 
    char name[30];
    double fixed_salary, sales, salary;

    scanf("%s", name);
    scanf("%lf", &fixed_salary);
    scanf("%lf", &sales);

    salary = fixed_salary + sales * TAX_COMMISSION;
    printf("TOTAL = R$ %.2lf\n", salary);

    return 0;
}