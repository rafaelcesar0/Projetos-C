#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");
    system("cls");
    int n, i, r=1, q=3;
    printf("Digite o n�mero que ser� elevado ao quadrado: ");
    scanf("%d", &n);
    printf("%d� = 1",n);

    for (i = 1; i < n; i++)
    {
        printf(" + %d",q);
        r += q;
        q += 2;
    }
    printf("\n\n%d� = %d\n\n",n,r);
    system("pause");
    return 0;
}
