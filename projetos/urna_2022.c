//A senha padrão é 12345;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h> 

#if defined(_WIN32) || defined(_WIN64)
	#define OS_Windows
    #include <Windows.h>                     //Biblioteca para usar Sleep no windows
	#include <conio.h>            
#endif

void Menu(){
	LimpaTela();   	
	printf("\n\t\t\t\t***** VOTAÇÃO URNA ELETRÔNICA *****\n\n\n");

	printf("\t\t\t\t ____________________ ELEIÇÕES ___________________ \n");
	printf("\t\t\t\t|                                                 |\n");
	printf("\t\t\t\t|    1  -  DEFINIR A QUANTIDADE DE VOTANTE        |\n");
	printf("\t\t\t\t|    2  -  INICIAR VOTAÇÃO                        |\n");
	printf("\t\t\t\t|    3  -  CONTABILIZAR VOTOS                     |\n");
	printf("\t\t\t\t|    4  -  SAIR                                   |\n");
	printf("\t\t\t\t|_________________________________________________|\n\n");
};

void Relatorio(int votos, int rodrigues, int adriano, int alcides, int alessandra, int antonio, int brancoDE, int nuloDE, int abraao, int adail, int adelita, int andre, int chris, int brancoDF, int nuloDF, int camilo, int carlos, int kamila, int erika, int brancoS, int nuloS, int wagner, int chico, int elmano, int roberto, int serley, int brancoG, int nuloG, int bolsonaro, int lula, int soraya, int padre, int ciro, int brancoP, int nuloP){
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos); 
	data_hora_atual = localtime(&segundos);
	
	LimpaTela();
	printf("\t\t\t\t _________________________________________________\n");
	printf("\t\t\t\t                                                  \n");
	printf("\t\t\t\t           RELATÁRIO DETALHADO DAS VOTAÇÕES       \n");
	printf("\t\t\t\t  - - - - - - - - - - - - - - - - - - - - - - - - \n");
	printf("\t\t\t\t                                                  \n");
	printf("\t\t\t\t     NÚMEROS DE VOTOS: %d                         \n\n",votos);
    printf("\t\t\t\t---------TOTAL DE VOTOS DE CADA CANDIDATO---------\n\n");
    printf("\t\t\t\t     DEPUTADO ESTADUAL:                           \n");
	printf("\t\t\t\t     RODRIGUES DE OLIVEIRA: %d                    \n",rodrigues);
	printf("\t\t\t\t     ADRIANO BARBOSA: %d                          \n",adriano);
	printf("\t\t\t\t     ALCIDES FERNANDES: %d                        \n",alcides);
	printf("\t\t\t\t     ALESSANDRA AIRES: %d                         \n",alessandra);
	printf("\t\t\t\t     ANTONIO VALDENIZO: %d                        \n",antonio);
	printf("\t\t\t\t     VOTOS BRANCOS: %d                            \n",brancoDE);
	printf("\t\t\t\t     VOTOS NULOS: %d                              \n\n",nuloDE);

	printf("\t\t\t\t     DEPUTADO FEDERAL:                            \n");
	printf("\t\t\t\t     ABRAÃO LUCAS: %d                             \n",abraao);
	printf("\t\t\t\t     ADAIL CARNEIRO: %d                           \n",adail);
    printf("\t\t\t\t     ADELITA MONTEIRO: %d                         \n",adelita);
    printf("\t\t\t\t     ANDRÉ FERNANDES: %d                          \n",andre);
    printf("\t\t\t\t     CHRISTIANNE COELHO: %d                       \n",chris);
	printf("\t\t\t\t     VOTOS BRANCOS: %d                            \n",brancoDF);
	printf("\t\t\t\t     VOTOS NULOS: %d                              \n\n",nuloDF);

    printf("\t\t\t\t     SENADOR:                                     \n");
	printf("\t\t\t\t     CAMILO SANTANA: %d                           \n",camilo);
	printf("\t\t\t\t     CARLOS SILVA: %d                             \n",carlos);
    printf("\t\t\t\t     KAMILA CARDOSO: %d                           \n",kamila);
    printf("\t\t\t\t     ÉRIKA AMORIM: %d                             \n",erika);
	printf("\t\t\t\t     VOTOS BRANCOS: %d                            \n",brancoS);
	printf("\t\t\t\t     VOTOS NULOS: %d                              \n\n",nuloS);

    printf("\t\t\t\t     GOVERNADOR:                                  \n");
	printf("\t\t\t\t     ABRAÃO LUCAS: %d                             \n",wagner);
	printf("\t\t\t\t     ADAIL CARNEIRO: %d                           \n",chico);
    printf("\t\t\t\t     ADELITA MONTEIRO: %d                         \n",elmano);
    printf("\t\t\t\t     ANDRÉ FERNANDES: %d                          \n",roberto);
    printf("\t\t\t\t     CHRISTIANNE COELHO: %d                       \n",serley);
	printf("\t\t\t\t     VOTOS BRANCOS: %d                            \n",brancoG);
	printf("\t\t\t\t     VOTOS NULOS: %d                              \n\n",nuloG);

    printf("\t\t\t\t     PRESIDENTE:                                  \n");
	printf("\t\t\t\t     JAIR BOLSONARO: %d                           \n",bolsonaro);
	printf("\t\t\t\t     LULA: %d                                     \n",lula);
    printf("\t\t\t\t     SORAYA THRONICKE: %d                         \n",soraya);
    printf("\t\t\t\t     PADRE KELMON: %d                             \n",padre);
    printf("\t\t\t\t     CIRO GOMES: %d                               \n",ciro);
	printf("\t\t\t\t     VOTOS BRANCOS: %d                            \n",brancoP);
	printf("\t\t\t\t     VOTOS NULOS: %d                              \n\n",nuloP);
	printf("\t\t\t\t _________________________________________________\n");
	printf("\t\t\t\t EMISSÃO: DATA: %d/%d/%d",data_hora_atual->tm_mday,data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900);
	printf(" às %d:%d:%d \n\n",data_hora_atual->tm_hour,data_hora_atual->tm_min,data_hora_atual->tm_sec);	
}

void LimpaTela(){
	system("cls || clear");
};

void Fim(){
		LimpaTela();
}

void Delay(int tempo){                  //Função para da um delay
	int win;
	win = tempo * 1000;
	
	#ifdef OS_Windows
		Sleep(win); 
	#else 
		sleep(tempo);
	#endif
};

int LendoVotantes(){                    //Função para ler o número de votantes
	int votantes = 0;

	do{
		LimpaTela();
		printf("\n\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - - - - +");
		printf("\n\t\t\t\t    Defina o número de votantes na eleição: ");
		scanf("%d", &votantes);
		printf("\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - - - - +");
		
		Delay(2);
			
		if(votantes < 3){
			LimpaTela();
			printf("\n\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - - - - +");
			printf("\n\t\t\t\t **  É necessário ter no mínimo 3 votantes!  **\n");
			printf("\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - - - - +");
			Delay(3);
		};
	} while(votantes < 3);

	return(votantes);
};

void Permissao(char senha[50]){        //Função para validação de senha
	char permissao[50], entrada;
	int cont = 0;
	
	do{ 
		LimpaTela(); 
		printf("\n\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
		printf("\t\t\t\t       Informe a SENHA para prosseguir      \n");
		printf("\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
		printf("\t\t\t\t  -> Senha: ");
		
		cont = 0;
		do{
   			entrada = getch();   
	       	
	    	if(isprint(entrada)){   
	        	permissao[cont] = entrada;  
	           	cont++;
	           	printf("*");   
	    	} else if(entrada == 8 && cont){
	       	    permissao[cont] = '\0';
	          	cont--;
	           	printf("\b \b");   
  			}
		} while(entrada != 13);
		permissao[cont]= '\0';   
		
		if(strcmp(senha, permissao) != 0){
			LimpaTela();
			Delay(1);
			printf("\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
			printf("\a\t\t\t\t           SENHA INCORRETA!\n\t\t\t\t      Digite novamente em instantes...\n");
			printf("\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
			Delay(2);   	
		}
		Delay(1);
	}while(strcmp(senha,permissao) != 0);
	
}



int main(){
	setlocale(LC_ALL, "portuguese");
	int i, opcao, corrige, validacao, votantes = 0, cont = 0, seguir = 1;
	int votos = 0, brancoDE = 0, nuloDE = 0, brancoDF = 0, nuloDF = 0, brancoS = 0, nuloS = 0, brancoG = 0, nuloG = 0, brancoP = 0, nuloP = 0;
    //deputado estadual:
    int rodrigues = 0, adriano = 0, alcides = 0, alessandra = 0, antonio = 0; 
    //deputado federal:
    int abraao = 0, adail = 0, adelita = 0, andre = 0, chris = 0;
    // senador:
    int camilo = 0, carlos = 0, kamila = 0, erika = 0;
    //governador:
    int wagner = 0, chico = 0, elmano = 0, roberto = 0, serley = 0;
    //presidente:
    int bolsonaro = 0, lula = 0, soraya = 0, padre = 0, ciro = 0;
	char entrada, voto[6], senha[50];
	
	//A senha padrão é 12345;
	//É possível alterar a senha digitando 1229 no MENU principal;	
	seguir = 1;
	strcpy(senha, "12345");
	
	do{
		Menu();
		printf("\t\t\t\t -> Opção: ");
		scanf("%d", &opcao);
			
		if(opcao == 1){
			Permissao(senha);
			votantes = LendoVotantes();
		} else if(opcao == 2){
			Permissao(senha);
			
			if(!votantes){
				LimpaTela();
				printf("\n\t\t\t\a ** É necessário ter o número de VOTANTES primeiro! **\n");
				printf("\n\t\t\t\t -> Pressione ENTER para continuar...");
				getch();
			} else {	
				for(i = 1; i <= votantes; i++){
					strcpy(voto, "");
					votos++;
					
					corrige = 1;
					validacao = 0;
					
					do{
						system("cls");
						strcpy(voto, "");
						printf("\t\t\t\t ___________________________________________________________\n");
						printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|          CANDIDATOS A DEPUTADO ESTADUAL                   |\n");
						printf("\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
						printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  10369  - RODRIGUES DE OLIVEIRA           - REPUBLICANOS  |\n");
						printf("\t\t\t\t|  33444  - ADRIANO BARBOSA GOMES DA SILVA  - PMB           |\n");
						printf("\t\t\t\t|  22222  - ALCIDES FERNANDES DA SILVA      - PL            |\n");
						printf("\t\t\t\t|  12789  - ALESSANDRA AIRES SABINO VIEIRA  - PDT           |\n");
						printf("\t\t\t\t|  13777  - ANTONIO VALDENIZO DA COSTA      - PT            |\n");
						printf("\t\t\t\t|  00000  - BRANCO                                          |\n");
                        printf("\t\t\t\t|___________________________________________________________|\n");
						printf("\n\t\t\t\t- INFORME SEU VOTO PARA DEPUTADO ESTADUAL: ");
						scanf("%s", voto);
						Delay(1); 
						
						
						printf("\t\t\t\t- Informe 1 para CONFIRMAR ou 2 para CORRIGIR: ");
						scanf("%d", &validacao);
						
						if(validacao == 1){
							corrige = 0;
						};
						
						if(validacao != 1 && validacao != 2){
							LimpaTela();
							printf("\n\t\t\t\t\t\a** OPÇÃO INVÁLIDA! ** \n\n\t\t\t\t -> Insira seu voto novamente...");
							Delay(2);
						};
					} while(corrige);
								
					if(strcmp(voto, "10369") == 0){
						rodrigues++;
					} else if(strcmp(voto, "33444") == 0){
						adriano++;
					} else if(strcmp(voto, "22222") == 0){
						alcides++;
					} else if(strcmp(voto, "12789") == 0){
						alessandra++;
					} else if(strcmp(voto, "13777") == 0){
						antonio++;
					} else if(strcmp(voto, "00000") == 0){
						brancoDE++;
					} else {
						nuloDE++;
					};	
					
					votos++;
					strcpy(voto, "");
					corrige = 1;
					validacao = 0;

                    do{
                        system("cls");
						strcpy(voto, "");
                        printf("\t\t\t\t ___________________________________________________________\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|          CANDIDATOS A DEPUTADO FEDERAL                    |\n");
                        printf("\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|  1516  - ABRAÃO LUCAS        - MDB                        |\n");
						printf("\t\t\t\t|  1022  - ADAIL CARNEIRO      - REPUBLICANOS               |\n");
						printf("\t\t\t\t|  5013  - ADELITA MONTEIRO    - PSQL                       |\n");
						printf("\t\t\t\t|  2222  - ANDRÉ FERNANDES     - PDT                        |\n");
						printf("\t\t\t\t|  1321  - CHRISTIANNE COELHO  - PT                         |\n");
						printf("\t\t\t\t|  0000  - BRANCO                                           |\n");
                        printf("\t\t\t\t|___________________________________________________________|\n");

						printf("\n\t\t\t\t- INFORME SEU VOTO PARA DEPUTADO FEDERAL: ");
						scanf("%s", voto);
						Delay(1);
						
						
						printf("\t\t\t\t- Informe 1 para CONFIRMAR ou 2 para CORRIGIR: ");
						scanf("%d", &validacao);
						
						if(validacao == 1){
							corrige = 0;
						};
						
						if(validacao != 1 && validacao != 2){
							LimpaTela();
							printf("\n\t\t\t\t\t\a** OPÇÃO INVÁLIDA! ** \n\n\t\t\t\t -> Insira seu voto novamente...");
							Delay(2);
						};
					} while(corrige);
										
					if(strcmp(voto, "1516") == 0){
						abraao++;
					}else if(strcmp(voto, "1022") == 0){
						adail++;
					}else if(strcmp(voto, "5513") == 0){
						adelita++;
					}else if(strcmp(voto, "2222") == 0){
						andre++;
					} else if(strcmp(voto, "1321") == 0){
						chris++;
					} else if(strcmp(voto, "0000") == 0){
						brancoDF++;
					} else {
						nuloDF++;
					};

                    votos++;
					strcpy(voto, "");
					corrige = 1;
					validacao = 0;

                    do{
						system("cls");
						strcpy(voto, "");
						printf("\t\t\t\t ___________________________________________________________\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|             CANDIDATOS A SENADOR                          |\n");
                        printf("\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|  131  - CAMILO SANTANA  - PT                              |\n");
						printf("\t\t\t\t|  160  - CARLOS SILVA    - PSTU                            |\n");
						printf("\t\t\t\t|  700  - KAMILA CARDOSO  - AVANTE                          |\n");
						printf("\t\t\t\t|  555  - ÉRIKA AMORIM    - PSD                             |\n");
						printf("\t\t\t\t|  000  - BRANCO                                            |\n");
                        printf("\t\t\t\t|___________________________________________________________|\n");
                        
						printf("\n\t\t\t\t- INFORME SEU VOTO PARA SENADOR: ");
						scanf("%s", voto);
						Delay(1); 
						
						
						printf("\t\t\t\t- Informe 1 para CONFIRMAR ou 2 para CORRIGIR: ");
						scanf("%d", &validacao);
						
						if(validacao == 1){
							corrige = 0;
						};
						
						if(validacao != 1 && validacao != 2){
							LimpaTela();
							printf("\n\t\t\t\t\t\a** OPÇÃO INVÁLIDA! ** \n\n\t\t\t\t -> Insira seu voto novamente...");
							Delay(2);
						};
					} while(corrige);
								
					if(strcmp(voto, "131") == 0){
						camilo++;
					} else if(strcmp(voto, "160") == 0){
						adriano++;
					} else if(strcmp(voto, "700") == 0){
						alcides++;
					} else if(strcmp(voto, "555") == 0){
						alessandra++;
					} else if(strcmp(voto, "000") == 0){
						brancoS++;
					} else {
						nuloS++;
					};

                    votos++;
					strcpy(voto, "");
					corrige = 1;
					validacao = 0;

                    do{
						system("cls");
						strcpy(voto, "");
						printf("\t\t\t\t ___________________________________________________________\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|             CANDIDATOS A GOVERNADOR                       |\n");
                        printf("\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|  44  - CAPITÃO WAGNER     - UNIÃO BRASIL                  |\n");
                        printf("\t\t\t\t|        VICE: RAIMUNDO MATOS                               |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  21  - CHICO MALTA        - PCB                           |\n");
                        printf("\t\t\t\t|        VICE: NAURI ARAÚJO                                 |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  13  - ELMANO DE FREITAS  - PT                            |\n");
                        printf("\t\t\t\t|        VICE: JADE ROMERO                                  |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  12  - ROBERTO CLÁUDIO    - PSD                           |\n");
                        printf("\t\t\t\t|        VICE: DOMINGOS FILHO                               |\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|  80  - SERLEY LEAL        - UP                            |\n");
                        printf("\t\t\t\t|        VICE: FRANCISCO BITA TAPEBA                        |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  00  - BRANCO                                             |\n");
						printf("\t\t\t\t|___________________________________________________________|\n");
						printf("\n\t\t\t\t- INFORME SEU VOTO PARA GOVERNADOR: ");
						scanf("%s", voto);
						Delay(1); 
						
						
						printf("\t\t\t\t- Informe 1 para CONFIRMAR ou 2 para CORRIGIR: ");
						scanf("%d", &validacao);
						
						if(validacao == 1){
							corrige = 0;
						};
						
						if(validacao != 1 && validacao != 2){
							LimpaTela();
							printf("\n\t\t\t\t\t\a** OPÇÃO INVÁLIDA! ** \n\n\t\t\t\t -> Insira seu voto novamente...");
							Delay(2);
						};
					} while(corrige);
								
					if(strcmp(voto, "44") == 0){
						wagner++;
					} else if(strcmp(voto, "21") == 0){
						chico++;
					} else if(strcmp(voto, "13") == 0){
						elmano++;
					} else if(strcmp(voto, "12") == 0){
						roberto++;
					} else if(strcmp(voto, "80") == 0){
						serley++;
					} else if(strcmp(voto, "00") == 0){
						brancoG++;
					} else {
						nuloG++;
					};

                    votos++;
					strcpy(voto, "");
					corrige = 1;
					validacao = 0;

                    do{
						system("cls");
						strcpy(voto, "");
						printf("\t\t\t\t ___________________________________________________________\n");
						printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|             CANDIDATOS A PRESIDENTE                       |\n");
						printf("\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
						printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  22  - JAIR BOLSONARO     - PL                            |\n");
                        printf("\t\t\t\t|        VICE: WALTER BRAGA                                 |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  13  - LULA               - PT                            |\n");
                        printf("\t\t\t\t|        VICE: GERALDO ALCKMIN                              |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  44  - SORAYA THRONICKE   - UNIÃO                         |\n");
                        printf("\t\t\t\t|        VICE: MARCOS CINTRA                                |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  14  - PADRE KELMON       - PTB                           |\n");
                        printf("\t\t\t\t|        VICE: LUIZ GAMONAL                                 |\n");
                        printf("\t\t\t\t|                                                           |\n");
                        printf("\t\t\t\t|  12  - CIRO GOMES         - PDT                           |\n");
                        printf("\t\t\t\t|        VICE: ANA PAULA                                    |\n");
                        printf("\t\t\t\t|                                                           |\n");
						printf("\t\t\t\t|  00  - BRANCO                                             |\n");
						printf("\t\t\t\t|___________________________________________________________|\n");
						printf("\n\t\t\t\t- INFORME SEU VOTO PARA PRESIDENTE: ");
						scanf("%s", voto);
						Delay(1); 
						
						
						printf("\t\t\t\t- Informe 1 para CONFIRMAR ou 2 para CORRIGIR: ");
						scanf("%d", &validacao);
						
						if(validacao == 1){
							corrige = 0;
						};
						
						if(validacao != 1 && validacao != 2){
							LimpaTela();
							printf("\n\t\t\t\t\t\a** OPÇÃO INVÁLIDA! ** \n\n\t\t\t\t -> Insira seu voto novamente...");
							Delay(2);
						};
					} while(corrige);
								
					if(strcmp(voto, "22") == 0){
						bolsonaro++;
					} else if(strcmp(voto, "13") == 0){
						lula++;
					} else if(strcmp(voto, "44") == 0){
						soraya++;
					} else if(strcmp(voto, "14") == 0){
						padre++;
					} else if(strcmp(voto, "12") == 0){
						ciro++;
					} else if(strcmp(voto, "00") == 0){
						brancoP++;
					} else {
						nuloP++;
					};
					
					Fim();
					Delay(2);				
					
					Permissao(senha);		
					Delay(1); 	  	  	     
			  	  	LimpaTela();
			  	  	printf("\n\t\t\t\t\t ** GRAVANDO VOTO **");		
					Delay(2); 	  	  	    
			  	  	LimpaTela();
				};	
			};
		} else if(opcao == 3){
			Permissao(senha);
			Relatorio(votos, rodrigues, adriano, alcides, alessandra, antonio, brancoDE, nuloDE, abraao, adail, adelita, andre, chris, brancoDF, nuloDF, camilo, carlos, kamila, erika, brancoS, nuloS, wagner, chico, elmano, roberto, serley, brancoG, nuloG, bolsonaro, lula, soraya, padre, ciro, brancoP, nuloP);
			getch();
			
		} else if(opcao == 4){
			break;
		
	 	//TROCAR A SENHA:	
		} else if(opcao == 1229){
			strcpy(senha, "");
			LimpaTela();
			printf("\n\t\t\t\t+ - - - - - - - - - - - - - - - - - - +");
			printf("\n\t\t\t\t       Cadastrando uma nova SENHA \n");
			printf("\t\t\t\t+ - - - - - - - - - - - - - - - - - - +");
			printf("\n\t\t\t\t  -> Nova senha: ");
			
			do{
	        	entrada = getch();
	        	
	            if(isprint(entrada)){   //Se a tecla pressionada for imprimível(que não é uma tecla/caractere de controle)
	            	senha[cont] = entrada;  //Armazena o caractere
	            	cont++;
	            	printf("*");
	            } else if(entrada == 8 && cont){
	           	    senha[cont] = '\0';
	            	cont--;
	            	printf("\b \b");   //Apagando o caractere digitado
	            }
	        } while(entrada != 13);
	        
			senha[cont]= '\0';   //não considerar o ENTER como senha	
			Delay(2);
			
			LimpaTela();
			
	        printf("\n\t\t\t\t -- Senha cadastrada com sucesso! --\n\n");			  	
	        Delay(1);
		} else {
			LimpaTela();	
			printf("\n\t\t\t\t\t\a** OPÇÃO INVÁLIDA! ** \n\n\t\t\t\t -> Pressione ENTER para continuar...");
			getch(); 
		};
	} while(opcao != 4);

	LimpaTela();
	printf("\n\t\t\t\t\t ** OBRIGADA POR PARTICIPAR **\n\n");
	Delay(1);
	system("pause");
	return(0);
}