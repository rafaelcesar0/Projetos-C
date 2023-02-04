#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    system("cls");
    float c[21],t = -100, f[21];
    printf("-----------------");
    for (int i = 0; i < 21; i++)
    {
        c[i] = t;
        f[i] = c[i] * 1.8 + 32;
        t += 10;
        printf("\n|%5.fC = %.fF\t|\n-----------------",c[i],f[i]);
    }
    printf("\n\n");
    system("pause");
    system("cls");
    return 0;
}