/**
 * @file ex01_area-circulo.c
 * @author Luiz Albano (albano.luiz@ifsp.edu.br) / Thiago Donadon (thiagohomem@ifsp.edu.br)
 * @brief 
 * Área do Círculo
 * 
 * A fórmula para calcular a área de uma circunferência é: area = π . raio2. 
 * Considerando para este problema que π = 3.14159:
 * - Efetue o cálculo da área, elevando o valor de raio ao quadrado e 
 * multiplicando por π.
 * 
 * Entrada
 * A entrada contém um valor de ponto flutuante (dupla precisão), no caso, a 
 * variável raio.
 * 
 * Saída
 * Apresentar a mensagem "A=" seguido pelo valor da variável area, conforme 
 * exemplo abaixo, com 4 casas após o ponto decimal. Utilize variáveis de 
 * dupla precisão (double). Como todos os problemas, não esqueça de imprimir 
 * o fim de linha após o resultado, caso contrário, você receberá 
 * "Presentation Error".
 * 
 * Link do exercício:
 * https://www.beecrowd.com.br/judge/pt/problems/view/1002?origem=1
 * 
 * @version 1.0
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#define PI 3.14159
 
int main() {
 
    double radius, area;

    scanf("%lf", &radius);
    area = PI * ( radius * radius );
    printf("A =%.4lf\n", area);

    return 0;
}