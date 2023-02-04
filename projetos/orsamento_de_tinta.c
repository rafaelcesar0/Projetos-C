#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    system("cls");
    float raio, altura, area, preco_lata, lata, l;
        /*1L pinta 3m² | lata tem 5L e custa R$:20,00*/
    printf("--------------------INICIO DO PROGRAMA--------------------\n\n");
    printf("Vamos fazer um orcamento para descobrir quantas\nlatas precisaremos pra pintar um tanque de combustivel!\n\nDigite a altura do tanque em Metros:  ");
    scanf("%f",&altura);
    printf("\n\nDigite o raio do tanque em Metros: ");
    scanf("%f",&raio);

    area = 3.14*raio + 2*3.14*raio*altura;
    printf("Areia = %2.fm\n",area);

    l = area / 3;
    lata = l / 5;
    preco_lata = ceil(lata) * 20;
    printf("Sera nescessario %.0f latas\nCustando R$:%2.f\n", ceil(lata),preco_lata);
    printf("---------------------FIM DO PROGRAMA----------------------\n\n");

    system("pause");
    system("cls");
    return 0;
}
