#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define limit 200 // Número máximo de contatos que posso cadastrar.

struct tabela_cadastro{ // Uma tabela de cadastro com nome e telefone.
    char nome[31];
    char telefone[14];
}cadastro[limit];

int contador = 0;

void criarContato(){ // Função pra Criar Novo Contato.

    system("cls");
    if(contador > limit){
        printf("LISTA DE CONTATOS CHEIA!");
    }else if(contador <= limit){
        printf("\n---------NOVO CONTATO---------\n\n");

        printf("Nome: ");
        fgets(cadastro[contador].nome, 30, stdin);
        strupr(cadastro[contador].nome);
        fflush(stdin);

        printf("Telefone: ");
        fgets(cadastro[contador].telefone, 14, stdin);
        fflush(stdin);
        contador++;
    }
}

void excluirContato(int valor){                 // Função para excluir um contato selecionado 
    for (int i = valor; i <= contador; i++)     // e organizar a lista de contatos.
    {
        cadastro[i] = cadastro[i+1];
    }
    contador--;
    cadastro[contador].nome == "NULL";
    cadastro[contador].telefone == "NULL";  
}

void verListaContatos(){ // Mostra uma lista com todos os contatos cadastrados.

        system("cls");
        printf( "--------CONSULTAR AGENDA--------\n\n");

        for (int i = 0; i < contador; i++)
        {
            printf("\nContato %d:\n",i+1);
            printf("\nNome: %sTelefone: %s",cadastro[i].nome, cadastro[i].telefone);
            printf("\n-------------------------------\n");
        }
        system("pause");
}

void opcaoInvalida(){ // Aparece a fraze animada "Opção invalida. . ."
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

void listaVazia(){ // Aparece a fraze animada "Lista de contatos vazia. . ."
    for (int i = 0; i < 2; i++)
    {
        system("cls");
        printf("Lista de contatos vazia");
        Sleep(200);
        for (int j = 0; j < 3; j++)
        {
            printf(".");
            Sleep(200);
        }
    }
}

void pesquisarContatos(){   // Digite o nome corretamente do contato q busca, 
    system("cls");          // edite ou delete esse contado se quizer.
    char pesquisa[31];
    int retorno, op2=0;
    printf( "Nome do contato: ");
    fgets(pesquisa, 30, stdin);
    strupr(pesquisa);
    fflush(stdin);
    for (int i = 0; i <= contador; i++)
    {
        retorno = strcmp(pesquisa, cadastro[i].nome);
        if (retorno == 0)
        {
            do{
                system("cls");
                printf("\nContato %d:\n",i+1);
                printf("\nNome: %sTelefone: %s",cadastro[i].nome, cadastro[i].telefone);
                printf("\n-------------------------------\n");
                printf( "[1]Editar esse contato\n"\
                        "[2]Apagar esse contato\n"\
                        "[3]Sair\n"\
                        "Opção: ");
                scanf("%d", &op2);
                fflush(stdin);
                if (op2 != 3)
                {
                    switch (op2)
                    {
                    case 1: //Editar
                        printf("\n---------EDITAR CONTATO---------\n\n");
                        printf("Nome: ");
                        fgets(cadastro[i].nome, 30, stdin);
                        strupr(cadastro[i].nome);
                        fflush(stdin);

                        printf("Telefone: ");
                        fgets(cadastro[i].telefone, 14, stdin);
                        fflush(stdin);
                        op2 = 3;
                        break;

                    case 2:excluirContato(i); //deletar
                        op2 = 3;
                        break;
                    
                    default:opcaoInvalida();    // Quando o que o usuário digitou 
                        break;                  // não é uma opção
                    }
                }
            }while(op2 != 3);
        }
    }   
}

int main()
{
    setlocale(LC_ALL,"portuguese-brazilian");
    system("cls");
    int op;
    do{
        op = 0; 
        system("cls");
        printf( "[1]Criar Contato\n"\
                "[2]Pesquisar contato\n"\
                "[3]Lista de contatos\n"\
                "[4]Sair\n\n"\
                "Opção: ");

        scanf("%d", &op);
        fflush(stdin);

        if(op != 4){

            switch (op){

                case 1:criarContato();
                    break;

                case 2:
                    if(contador > 0){
                        pesquisarContatos();
                    }
                    else{
                        listaVazia(); // Nenhum contato cadastrado.
                    }          
                    break;

                case 3:
                    if(contador > 0){
                        verListaContatos();
                    }
                    else{
                        listaVazia(); // Nenhum contato cadastrado.
                    };
                    break;

                default:opcaoInvalida();    // Quando o que o usuário digitou
                    break;                  // não é uma opção
            }
        }
    }while( op != 4); // Digite 4 pra encerrar o programa!

    system("cls");
    printf("\n|---------------------PROGRAMA ENCERADO---------------------|\n\n");
    return 0;
}