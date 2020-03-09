#include <iostream>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool desejajogar();
void limpartabuleiro( char casas3[3][3]);
void jogada_do_jogador(char casas4[3][3]);
void jogada_da_maquina( char c[3][3]);
void tabuleiro(char casas2[3][3]);


void tabuleiro(char casas2[3][3]){
	
	printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]  );
	printf("\t ----------\n");
	printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]  );
	printf("\t ----------\n");
	printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]  );
	printf("\t ----------\n\n");
}

int main(int argc, char** argv) {
	bool jogar = true;
	int jogadas  =0;
	char casas[3][3] = { {'x','x','x'},{'x','x','x'},{'x','x','x'} };
	
	jogar = desejajogar();
	while(jogar){
		
		limpartabuleiro(casas);
		tabuleiro(casas);
		jogadas = 0;
		while(jogadas < 9){
			jogada_do_jogador(casas);
			tabuleiro(casas);
			jogadas++;
			jogada_da_maquina(casas);
			tabuleiro(casas);
			jogadas++;
		}
		printf("\n *** fim de jogo ***\n\n");
		jogar = desejajogar();
	}
	return 0;
}


void jogada_do_jogador( char casas4[3][3]){
	bool jogou = false;
	int l, c;
	while (jogou==false){
		printf("Digite a linha: ");
		scanf(" %i", &l);
		printf("Digite a coluna: ");
		scanf(" %i",&c);
		
		if (casas4[l][c] != ' '){
		    printf("A casa está ocupada.\n");
		    jogou = false;
		} else {
			casas4[l][c]= 'x';
			jogou = true;
		}
	}
}


bool desejajogar(){
	char resposta= 's';
	printf("Desejar jogar uma partida: (s/n):");
	
	scanf(" %c", &resposta);
	return resposta == 's';
}
void limpartabuleiro(char casas3[3][3] ){
	int i,z;
	for(i=0;i<3;i++){
		for(z=0;z<3;z++){
			casas3[i][z]=' ';
		}
	}
	
}

void jogada_da_maquina( char c[3][3]){
	// aqui vai a inteligencia da maquina
	// na primeira jogada - se adversario no canto entao deve colocar no centro
	// se o meio foi ocupado por x
	
	if (c[1][1]=='x'){
		if (c[0][0]==' '){
			c[0][0]='O';
			return;
		}
		if (c[2][2]==' '){
			c[2][2]='O';
			return;
		}
		if (c[0][2]==' '){
			c[0][2]='O';
			return;
			}
		if (c[2][0]==' '){
			c[2][0]='O';
			return;
		}
	} else {
		if (c[0][0] == 'x' || c[2][2] == 'x' || c[0][2]=='x' || c[2][0]){
		   // se o meio está vazio // joga no meio
		   if (c[1][1] ==' '){
		   	   c[1][1] ='O';
		   } else {
		   	   c[0][0] = '0';
		   }
		}
   }
}

