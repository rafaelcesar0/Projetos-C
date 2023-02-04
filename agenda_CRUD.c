#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define limit 10

struct tb_cadastro
    {
        char nome[51];
        char phone[16];
        char empresa[51];
    }cadastro[limit];

int counter=0;

void contactCreate(){
    if (counter>=limit)
    {
        printf("AGENDA CHEIA!!!");
    }else if(counter<limit){
    printf("\n-----NOVO CADASTRO-----\n\n");

    printf("Nome: ");
    fgets(cadastro[counter].nome, 50, stdin);
    fflush(stdin);

    printf("Phone: ");
    fgets(cadastro[counter].phone, 15, stdin);
    fflush(stdin);

    printf("Empresa: ");
    fgets(cadastro[counter].empresa, 50, stdin);
    fflush(stdin);
    counter++;
    system("cls");
    }  
}

void contactList(){
    printf("\n-----CONSULTAR AGENDA-----\n\n");


    for (int i = 0; i < counter; i++)
    {
        printf("Cadastro %d:\n",i+1);
        printf("\nNome: %sPhone: %sEmpresa: %s",cadastro[i].nome, cadastro[i].phone, cadastro[i].empresa);
        printf("\n------------------------------\n");
    }
    system("pause");
    system("cls");
}

void contactEdit(){
    int z;
    while (z>counter)
    {
            printf("\nDigite o Nº de um cadastro valido que deseja alterar: ");
            scanf("%d", &z);
            fflush(stdin);
            if (z>counter)
            {
                printf("\nEsse cadastro não existe.");
            }     
    }
    z--;
    printf("\n-----ALTERAR CADASTRO-----\n");

    printf(" Cadastro %d:\n\n",z+1);
    printf("Nome: ");
    fgets(cadastro[z].nome, 50, stdin);
    fflush(stdin);

    printf("Phone: ");
    fgets(cadastro[z].phone, 15, stdin);
    fflush(stdin);

    printf("Empresa: ");
    fgets(cadastro[z].empresa, 50, stdin);
    fflush(stdin);
    system("cls");
}

void contactDel(){
    int w, j;
    while (w>counter)
    {
            printf("\nDigite o Nº de um cadastro valido que deseja deletar: ");
            scanf("%d", &w);
            fflush(stdin);
            if (w>counter)
            {
                printf("\nEsse cadastro não existe.");
            }     
    }
    w--;
    printf("Digite 1 pra confirmar: ");
    scanf("%d", &j);
    fflush(stdin);
    if (j == 1)
    {
        bzero(cadastro[w].nome, limit);
        bzero(cadastro[w].phone, limit);
        bzero(cadastro[w].empresa, limit);
    }
}


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"portuguese");
    system("cls");
    int op=0;
    
    while(op != 5)
    {
        printf("\n---------------MENU---------------\n\n\n");
        printf("1 - Cadastro\n2 - Consultar\n3 - Alterar\n4 - Deletar\n5 - Sair\n");
        printf("\nSelecione a opção desejada: ");
        scanf("%d", &op); 
        fflush(stdin);

        if (op != 5)
        {
            switch (op)
            {
            case 1:contactCreate();
                 break;

            case 2:contactList();
                break;

            case 3:contactEdit();
                break;
            
            case 4:contactDel();
                break;

            default:
            printf("\nOpção invalida. Porfavor digite um número valido.\n");
            system("pause");
            system("cls");
                break;
            }
        }
    }
    printf("\nBye Bye!\n");
    return 0;
}
