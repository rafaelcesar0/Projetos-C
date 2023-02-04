#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float altura, peso;
    char sexo;
    system("cls");
    printf("--------------INICIO DO PROGRAMA--------------\n");
    printf("Digite sua altura em Metros: ");
    scanf("%f",&altura);
    do
    {
        printf("\nDigite seu sexo.\n(M) para masculino ou (F) para feminino: ");
        scanf(" %c",&sexo);
    } while (sexo!='M' && sexo!='m' && sexo!='f' && sexo!='F');
    
    
    if ( sexo == 'M' || sexo == 'm' )
    {
        /*Peso Masculino*/
        peso=(72.7*altura)-58;

    }else{
        /*Peso Feminino*/
        peso=(62.1*altura)-44.7;
    }

    printf("\nSeu peso ideal e de %.1fKG.\n\n", peso);
    printf("---------------FIM DO PROGRAMA----------------\n\n");
    system("PAUSE");
    system("cls");
    return 0;
}
