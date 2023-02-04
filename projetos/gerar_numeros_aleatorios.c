#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    int opcao, i, v[10];
    system("cls");
    do{
        printf("\nDigite 1 para começar: ");
        scanf("%d",&opcao);
        system("cls");
        if (opcao==1){
            srand(time(NULL));

            printf("\nForam gerandos 10 vetores aleatorios:\n\n");
            for (i = 0; i < 10; i++)
            {
                v[i]= rand()%100;
                printf("%d  ",v[i]);
            }
        }else{
            printf("\nOpção invalida.\nPorfavor siga as instruções.\n");
        } 
    }while(opcao!=1);
    printf("\n\n------------------------------- MENU -------------------------------\nDigite 2 - Para mostrar o elemento de maior valor dos vetores.\nDigite 3 - Para contabilizar quantos elementos sao pares.\nDigite 4 - Para mostra a soma de todos os elementos dos vetores.\nDigite 5 - Para mostras os vetores na ordem invertida.\nDigite 6 - Para mostras os vetores na ordem crescente.\nDigite 7 - SAIR\n--------------------------------------------------------------------\n\n");
    while(opcao!=7){
        do
        {
            printf("\nEscolha: ");
            scanf("%d", &opcao);
            if (opcao<=1 || opcao>=8)
            {
                printf("\nOpção invalida. Porfavor digite um número valido.\n");
            }
        } while (opcao<=1 || opcao>=8);


        switch (opcao){
            int maior, par, soma, inverso[10], crescer, j;
        case 2:
            maior=v[0];
            for (i = 1; i < 10; i++)
            {
                if (v[i]>maior)
                {
                    maior=v[i];
                }
            }
            printf("O elemento de maior valor é: %d\n",maior);
            break;
        
        case 3:
            par=0;
            for (i = 0; i < 10; i++)
            {
                if (v[i]%2==0)
                {
                    par++;
                }
            }
            printf("%d são pares.\n",par);
            break;
        case 4:
            soma=0;
            for (i = 0; i < 10; i++)
            {
                soma+=v[i];
            }
            printf("A soma dos vetores é: %d\n",soma);
            break;
        
        case 5:
            printf("Vetores invertidos: ");
            for (i = 0, j = 9 ; i < 10, j >=0 ; i++, j--)
            {
                inverso[j] = v[i];
            }
            for (i = 0; i < 10; i++)
            {
                printf("%d ",inverso[i]);
            }
            printf("\n");
            break;
        
        case 6:
            printf("Vetores em ordem crescente: ");
            for (i = 0; i < 10; i++)
            {
                for (j = i; j < 10; j++)
                {
                    if (v[i]>v[j])
                    {
                        crescer=v[i];
                        v[i]=v[j];
                        v[j]=crescer;
                    }
                    
                }
                
            }
            for (i = 0; i < 10; i++)
            {
                printf("%d ",v[i]);
            }
            printf("\n");
            break;

        case 7:
            printf("Fim do programa. Bye Bye!\n");
            printf("\n------------------------- PROGRAMA INCERADO -------------------------\n");
            break;
        }
    }
    system("PAUSE");
    return 0;
}