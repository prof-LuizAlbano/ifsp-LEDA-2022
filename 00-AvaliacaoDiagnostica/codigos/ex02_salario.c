/**
 * @file ex02_salario.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * Salário
 * Escreva um programa que leia o número de um funcionário, seu número de 
 * horas trabalhadas, o valor que recebe por hora e calcula o salário desse 
 * funcionário. A seguir, mostre o número e o salário do funcionário, com 
 * duas casas decimais.
 * 
 * Entrada
 * O arquivo de entrada contém 2 números inteiros e 1 número com duas casas 
 * decimais, representando o número, quantidade de horas trabalhadas e o valor 
 * que o funcionário recebe por hora trabalhada, respectivamente.
 * 
 * Saída
 * Imprima o número e o salário do funcionário, conforme exemplo fornecido, 
 * com um espaço em branco antes e depois da igualdade. No caso do salário, 
 * também deve haver um espaço em branco após o $.
 * 
 * Link do exercício:
 * https://www.beecrowd.com.br/judge/pt/problems/view/1008
 * 
 * @version 1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
 
    int number, hours;
    double hour_salary, salary;

    scanf("%d", &number);
    scanf("%d", &hours);
    scanf("%lf", &hour_salary);

    salary = (double) hours * hour_salary;
 
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2lf\n", salary);
    return 0;
}