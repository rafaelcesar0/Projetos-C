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
#include <stdbool.h>
#include <windows.h>

int a, b, cpf[11]; 

bool validarCPF()
{
    bool validar = true;
    int test = 0;
    
    for (int i = 0; i < 11; i++)
    {
        test += cpf[i];
    }
    
    if (test != 11 && test != 22 && test != 33 && test != 44 && test != 55 && test != 66 && test != 77 && test != 88 && test != 99)
    {
        validar = false;
    }
    
    return validar;
}

calcularCPF()
{
    int n = 10;
    a = 0;
    b = 0;

    for (int i = 0; i < 9; i++)
    {
        a += cpf[i] * n;
        n--;
    }
    a %= 11;
    if (a < 2)
    {
        a = 0;
    }else{
        a = 11 - a;
    }
    
    cpf[9] = a;  //Fim do calculo do primeiro digito.
    
    n = 11;
    for (int i = 0; i < 10; i++)
    {
        b += cpf[i] * n;
        n--;
    }
    b %= 11;
    if (b < 2)
    {
        b = 0;
    }else{
        b = 11 - b;
    }

    cpf[10] = b;
}

int main()
{setlocale(LC_ALL,"portuguese");
    char op;
    bool validar;

    do{
        for (int i = 0; i < 11; i++)
        {
            cpf[i] = 0;
        }

        for (int i = 0; i < 11; i++)
        {
            system("cls");

            if (i==0){
                printf("CPF: ___.___.___ - __\n");
            }else if (i==1){
                printf("CPF: %d__.___.___ - __\n",cpf[0]);
            }else if (i==2){
                printf("CPF: %d%d_.___.___ - __\n",cpf[0],cpf[1]);
            }else if (i==3){
                printf("CPF: %d%d%d.___.___ - __\n",cpf[0],cpf[1],cpf[2]);
            }else if (i==4){
                printf("CPF: %d%d%d.%d__.___ - __\n",cpf[0],cpf[1],cpf[2],cpf[3]);
            }else if (i==5){
                printf("CPF: %d%d%d.%d%d_.___ - __\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4]);
            }else if (i==6){
                printf("CPF: %d%d%d.%d%d%d.___ - __\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5]);
            }else if (i==7){
                printf("CPF: %d%d%d.%d%d%d.%d__ - __\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6]);
            }else if (i==8){
                printf("CPF: %d%d%d.%d%d%d.%d%d_ - __\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7]);
            }else if (i==9){
                printf("CPF: %d%d%d.%d%d%d.%d%d%d - __\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8]);
            }else if (i==10){
                printf("CPF: %d%d%d.%d%d%d.%d%d%d - %d_\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9]);
            }
            
            do{
                printf("\nDigite o %dº número do CPF: ",i+1);
                scanf("%d", &cpf[i]);
                fflush(stdin);
            }while (cpf[i] < 0 || cpf[i] > 11);
        }

        system("cls");
        printf("CPF: %d%d%d.%d%d%d.%d%d%d - %d%d\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10]);

        do{
            printf("\n[s/n] Confirmar CPF: ");
            scanf("%c", &op);
            fflush(stdin);
            op = tolower(op);
        }while (op != 'n' && op != 's');
    }while (op == 'n');
    
    validar = validarCPF();

    if (validar == true)
    {
        system("cls");
        printf("\n|---- CPF VALIDO ----|\n");
        printf("\nCPF: %d%d%d.%d%d%d.%d%d%d - %d%d\n\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10]);
    }
    else
    {
        system("cls");
        printf("\n|--- CPF INVALIDO ---|\n");
        printf("\nO CPF: %d%d%d.%d%d%d.%d%d%d - %d%d é INVALIDO!\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10]);
        printf("\nPrecione QUALQUER TECLA para calcular o CPF valido...");
        getch();
        fflush(stdin);
        for (int i = 0; i < 2; i++)
        {
            system("cls");
            printf("Calculando CPF valido");
            Sleep(250);
            for (int j = 0; j < 3; j++)
            {
                printf(".");
                Sleep(250);
            }
        }
        system("cls");
        printf("\n|--- CPF INVALIDO ---|\n");
        printf("\nCPF: %d%d%d.%d%d%d.%d%d%d - %d%d\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10]);
        
        printf("\n\n|---- CPF VALIDO ----|\n");
        calcularCPF();
        printf("\nCalculado o 1º dígito verificador : %d",cpf[9]);
        printf("\nCalculado o 2º dígito verificador : %d\n",cpf[10]);
        printf("\nCPF: %d%d%d.%d%d%d.%d%d%d - %d%d\n\n",cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],cpf[6],cpf[7],cpf[8],cpf[9],cpf[10]);

    }
    
    return 0;
}