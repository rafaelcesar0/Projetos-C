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
#include <ctype.h>
#include <windows.h>
#include <time.h>

int dd, mm, aa;

int anoAtual()
{
    int anoAtual;
    time_t data_ano;
    time(&data_ano);

    struct tm *data = localtime(&data_ano);

    anoAtual = (data->tm_year + 1900);

    return anoAtual;
}

void opcaoInvalida()
{
    for (int i = 0; i < 2; i++)
    {
        system("cls");
        printf("Opção invalida");
        Sleep(190);
        for (int j = 0; j < 3; j++)
        {
            printf(".");
            Sleep(190);
        }
    }
}

void digitarAniversario()
{
    do
    {
        system("cls");
        printf("Dia do seu aniversário: ");
        scanf("%d", &dd);
        fflush(stdin);
        if (dd < 1 || dd > 31)
        {
            opcaoInvalida();
        }
    } while (dd < 1 || dd > 31);

    do
    {
        system("cls");
        printf("Mês do seu aniversário: ");
        scanf("%d", &mm);
        fflush(stdin);
        if (mm < 1 || mm > 12)
        {
            opcaoInvalida();
        }
    } while (mm < 1 || mm > 12);

    do
    {
        system("cls");
        printf("Ano do seu aniversário: ");
        scanf("%d", &aa);
        fflush(stdin);
        if (aa < 1900 || aa > anoAtual())
        {
            opcaoInvalida();
        }
    } while (aa < 1900 || aa > anoAtual());
    system("cls");
    printf("Data de nascimento: %.2d/%.2d/%d", dd, mm, aa);
}

void calculo()
{
    int r, valor, div1, div2, x, x2;
    char dia[3], mes[3], concatenar[5];
    sprintf(dia, "%.2d", dd);
    sprintf(mes, "%.2d", mm); //Copia um valor int para uma String
    strcpy(concatenar, dia);  //Atribui um String a outro
    strcat(concatenar, mes);  //Acrecente um String a outro
    valor = atoi(concatenar); // atoi() converte um String para um Int
    x = valor + aa;
    sprintf(concatenar, "%d", x);
    char cont1[] = {concatenar[0], concatenar[1], '\0'}, cont2[] = {concatenar[2], concatenar[3], '\0'};
    div1 = atoi(cont1);
    div2 = atoi(cont2);
    x2 = div1 + div2;
    r = x2 % 5;

    printf("\n[1] %d + %d = %d\n", valor, aa, x);
    printf("[2] %.2d + %.2d = %d\n", div1, div2, x2);
    printf("[3] %d / 5 Resto = %d\n", x2, r);
    system("pause");

    system("cls");
    printf("[R] Perfil\n"
           "---------------\n"
           "[0] Tímido\n"
           "[1] Sonhador\n"
           "[2] Paquerador\n"
           "[3] Atraente\n"
           "[4] Irresistível\n");
    printf("\nRESPOSTA: %d\n", r);

    switch (r)
    {
    case 0:
        printf("Você é: Tímido!\n");
        break;

    case 1:
        printf("Você é: Sonhador!\n");
        break;

    case 2:
        printf("Você é: Paquerador!\n");
        break;

    case 3:
        printf("Você é: Atraente!\n");
        break;

    case 4:
        printf("Você é: Irresistível!\n");
        break;
    }
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char op;
    do
    {
        digitarAniversario();
        calculo();

        do
        {
            system("cls");
            printf("Continue? [s/n]\n-> ");
            scanf("%c", &op);
            fflush(stdin);
            op = tolower(op);
            if (op != 'n' && op != 's')
            {
                for (int i = 0; i < 2; i++)
                {
                    system("cls");
                    printf("Opção invalida");
                    Sleep(190);
                    for (int j = 0; j < 3; j++)
                    {
                        printf(".");
                        Sleep(190);
                    }
                }
            }
        } while (op != 'n' && op != 's');

    } while (op == 's');
    return 0;
}
