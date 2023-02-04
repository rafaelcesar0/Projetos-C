/*
    Curso: ADS/Noite 

    Equipe:
    Rafael César Rocha Monteiro         | Matrícula: 2022010979
    Lucas Cavalcante de Morais Monteiro | Matrícula: 2022010934
    Natanael de Holanda e Oliveira      | Matrícula: 2022011256
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{setlocale(LC_ALL,"portuguese");

    float saldo, operacao, credito = 0, debito = 0, cpmf;
    system("cls");
    printf("Digite o saldo inicial: ");
    scanf("%f", &saldo);
    fflush(stdin);
    printf("Digite [0] para encerrar ás operações.\n\n");
    do
    {
        printf("Operação? ");
        scanf("%f", &operacao);
        fflush(stdin);
        saldo += (operacao);
        if (operacao > 0)
        {
            credito += operacao;
        }else if(operacao < 0)
        {
            debito += operacao;
        }
        
    } while (operacao != 0); 

    cpmf = debito * 0.0035; // Calculo do C.P.M.F
    saldo += cpmf;
    /*
        ? AVISO!
        Essa questão pede pra calcularmos o C.P.M.F à (0,35% do total de débito), 
        mas no exemplo dado o calculo foi de (0,2% do total de débito) e o valor
        débito: 520,00 era pra ser de 720,00.
    */

    printf("\nTotal de crédito ....: R$: %.2f",credito);
    printf("\nTotal de débito .....: R$: %.2f",-debito);
    printf("\nC.P.M.F. paga .......: R$: %.2f",-cpmf);
    printf("\nSaldo final .........: R$: %.2f",saldo);
    return 0;
}
