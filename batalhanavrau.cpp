#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define  ANST_COLOR_RED "\033[31m"
#define  ANSR_COLOR_GREEN "\033[32m"
#define  ANSR_COLOR_YELLOW "\033[33m"
#define  ANSR_COLOR_BLUE "\033[34m"
#define  ANSR_COLOR_MAGENTA "\033[35m"
#define  ANSR_COLOR_CYAN "\033[36m"

char mapa1[10][10];			// para os dados de navios e água
char mapaimpressao[10][10]; // para mostrar ao usuário

int naviosrestantes;
//protótipo de função
void inicio();
void menu();
void comojogar();
void sair();
void info();
void inicializabatalha();
void imprimemapa1();
void jogar();
void navios();
void geranavios();
int main(){
	srand(time(NULL));
	inicio();
	menu();
	return 0;
}

void menu(){   //menu do jogo
	char op;
	do{
		system ("cls");
		printf ("\033[32m");
		printf ("\n\t\t\t%c%c%c%c%c%c%cMENU%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
		printf ("\n\t\t\t%c                %c ",179,179);
		printf ("\n\t\t\t%c\033[34m [1]- Novo Jogo %c ",179,179);
		printf ("\n\t\t\t%c                %c ",179,179);
		printf ("\n\t\t\t%c\033[35m [2]- Como Jogar%c ",179,179);
		printf ("\n\t\t\t%c                %c ",179,179);
		printf ("\n\t\t\t%c\033[36m [3]- Info      %c ",179,179);
		printf ("\n\t\t\t%c                %c ",179,179);
		printf ("\n\t\t\t%c\033[31m [4]- Sair      %c ",179,179);
		printf ("\n\t\t\t%c                %c ",179,179);
		printf ("\n\t\t\t%c%c%c%c%c%c%cMENU%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
		printf ("\n");
		printf ("\033[33m");
		printf ("\n\t\tDigite a opcao desejada: ");
		scanf ("%d",&op);
		switch(op){
			case 1: inicializabatalha();
					geranavios();
					Beep(510,200);
					while (naviosrestantes > 0){
						imprimemapa1();
						jogar();
						if (naviosrestantes == 0){
							printf ("parabens,voce ganhou.\n\n\n\n");
							    Beep(660,80);Sleep( 150);
                                Beep(500,80);Sleep( 300);
                                Beep(430,80);Sleep( 150);
                                Beep(380,80);Sleep( 600);
                                Beep(660,100);Sleep( 150);
                                Beep(660,100);Sleep( 300);
                                Beep(660,100);Sleep( 300);
                                Beep(510,100);Sleep( 100);
                                Beep(660,100);Sleep( 300);
                                Beep(770,100);Sleep( 550);
                                Beep(380,100);Sleep( 575);
                            printf ("Obrigado por jogar...\n\n\n\n");
							system ("pause");
						}	
					}
					break;
			case 2: comojogar();
					Beep(510,100);
					break;
			case 3: info();
					Beep(510,100);
					break;
			case 4: sair();
					Beep(510,100);
			        break;
			default: printf ("\n\t\tErro, opcao invalida!");
					printf ("\n\t\t");
					Beep(1000,200);
					break;
		}
		system ("pause");
	}while (op!=0);
 }
 void inicio(){
 	Beep(950,100);
 	printf ("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
 	printf ("\n\t\t%c           BATALHANAVRAU          %c",179,179);
 	printf ("\n\t\t%c             Bem-Vindo            %c",179,179);
 	printf ("\n\t\t%c                                  %c",179,179);
 	printf ("\n\t\t%c   Para jogar escolha uma linha   %c",179,179);
 	printf ("\n\t\t%c     e uma coluna entre 0 e 9     %c",179,179);
 	printf ("\n\t\t%c                                  %c",179,179);
 	printf ("\n\t\t%c             BOM-JOGO             %c",179,179);
 	printf ("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\t\t",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	printf ("\n");
	system ("pause");
system ("cls");
}
void geranavios(){ //funcao que gera navios
		for(int i = 0; i<10; i++)
		{
			for(int j = 0; j<10; j++)
			{
				mapa1[i][j] = '*';
			}
		}
		int aux;
		for(int i = 0; i<10; i++)
		{
			for(int j = 0; j<1; j++)
			{
				aux = rand()%9;
				if(mapa1[i][aux] != 'N')
				{	
					mapa1[i][aux] = 'N';	
				}
				else
				{
					j--;
				}	
			}
		}
		naviosrestantes = 10;
}
 void sair(){
    system ("exit");
 }
void jogar(){   //funcao linha e coluna
 	int lin,col;
 	printf ("\033[32m");
 	printf ("\nNavios restantes: [%d]",naviosrestantes);
 	printf ("\n");
 	printf ("\033[33m");
 	printf("\nEscolha uma linha para jogar : ");
	scanf("%d", &lin);
	Beep(290,150);
	printf ("\033[35m");
	printf("\nEscolha uma coluna para jogar : ");
	scanf("%d", &col);
	Beep(290,150);
	if (lin < 0 || lin > 9 || col < 0 || col > 9){
		printf ("\nErro, Digite um numero entre 0 e 9\n");
		system ("pause");
	}
	else{
		if (mapaimpressao[lin][col] == ' '){
			mapaimpressao[lin][col] = mapa1[lin][col];
			if (mapaimpressao [lin][col] == 'N'){
				naviosrestantes--;
				Beep(100,300);
			}
		}
		else{
			printf ("\nErro,jogue novamente!\n\n");
			system ("pause");
		}
	}
 }
void comojogar(){   //funcao jogar
	printf ("\033[36m");
	printf ("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	printf ("\n\t%c                                                 %c",179,179);
	printf ("\n\t%c O objetivo do jogo e afundar os navios inimigos.%c",179,179);
	printf ("\n\t%c escolhendo a linha e coluna...                  %c",179,179);
	printf ("\n\t%c Quando sua pontuacao chegar a zero,voce ganha!  %c",179,179);
	printf ("\n\t%c                                                 %c",179,179);
	printf ("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
    printf ("\n\n");
}
void info(){   //funcao info
	printf ("\033[34m");
	printf ("\n\t\t\t%c%c%c%c%cINFO%c%c%c%c%c",218,196,196,196,196,196,196,196,196,191);
	printf ("\n\t\t\t%c            %c",179,179);
	printf ("\n\t\t\t%c  [~]Mar    %c",179,179);
	printf ("\n\t\t\t%c  [%c]Navio  %c",179,254,179);
	printf ("\n\t\t\t%c            %c",179,179);
	printf ("\n\t\t\t%c%c%c%c%cINFO%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217);
	printf ("\n\n\t\t");
}
// preenche cada célula com ' ' um espaço em branco
void inicializabatalha(){
	int i,j;
   	for(int i=0; i<10; i++){
		for(int j=0;j<10;j++){
			printf ("\033[34m");
			mapa1[i][j]= '~';
			mapaimpressao[i][j] = ' ';
    	}
 	}
 } 
void imprimemapa1(){   //funcao que gera o mapa
	int i,j;
	printf ("\033[34m");
	system("cls");	
	printf ("   ");
	for(int i=0; i<10; i++){
		printf (" %d  ",i);	
	}
	printf ( "\n");	
	for(int i=0; i<10; i++){	
		printf ( "  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197);
		printf ( "%d %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",i,179,mapaimpressao[i][0],179,mapaimpressao[i][1],179,mapaimpressao[i][2],179,mapaimpressao[i][3],179,mapaimpressao[i][4],179,mapaimpressao[i][5],179,mapaimpressao[i][6],179,mapaimpressao[i][7],179,mapaimpressao[i][8],179,mapaimpressao[i][9],179);
	}
	printf ( "  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,217);
	printf ( "\n\n\n\n");
}
