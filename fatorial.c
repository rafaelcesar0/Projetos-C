// Digite um número para descobrir seu fatorial.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    do
    {
        system("cls");
        int n, r = 1, i;
        printf("\nEscolha um numero e vamos descobrir seu fatorial!\n");
        printf("Digite aqui: ");
        scanf("%d", &n);
        printf("\n\n%d! = 1", n);

        for (i = 2; i <= n; i++)
        {
            printf(" x %d", i);
            r *= i;
        }
        printf("\n\n%d! = %d\n\n", n, r);

        system("pause");
    } while (1);
    return 0;
}
