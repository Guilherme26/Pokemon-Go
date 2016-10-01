#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Jogador.h"

#define STR_SIZE 4
#define NUM_VIZINHOS 8
#define INVALIDO 7

//This function dynamically alocates every player struct
t_jogador *aloca_jogador(int numero_de_jogadores){
	t_jogador *aloca;
	aloca = (t_jogador*) calloc(numero_de_jogadores, sizeof(t_jogador));

	return aloca;
}

//This method initialize every player with 3 pokeballs and with a personal ID
void inicia_player(t_jogador *vetor_de_jogadores, FILE *in, int numero_de_jogadores){
	int i;
	char str1[STR_SIZE], str2[STR_SIZE], *token;
	
	for(i=0; i<numero_de_jogadores; i++){
		fscanf(in, "%s %s", str1, str2);

	//Find player coordinates, convert them from CHAR to INT and then save on player struct
		token = strtok(str2, ",");
		vetor_de_jogadores[i].linha = atoi(token);
		token = strtok(NULL, ",");
		vetor_de_jogadores[i].coluna = atoi(token);

	//Initialize other variables
		vetor_de_jogadores[i].id = (i+1);
		vetor_de_jogadores[i].pokebolas = 3;
	}
}

//This method show all players
void exibe_jogadores(t_jogador *vetor_de_jogadores, int numero_de_jogadores){
	int i;
	for(i=0; i<numero_de_jogadores; i++){
		printf("id [%d] passos[%d] pokebolas[%d] pontos[%d] linha[%d] coluna[%d]\n", vetor_de_jogadores[i].id, vetor_de_jogadores[i].passos, vetor_de_jogadores[i].pokebolas, vetor_de_jogadores[i].pontos, vetor_de_jogadores[i].linha, vetor_de_jogadores[i].coluna);
	}
}

//This method makes player find place to walk
int andar(t_jogador *jogador, int numero_de_jogadores, int **mapa, int tamanho_do_mapa){
	int i = 0, *vizinhos = NULL, maior = 0, indice_maior = 0;

	vizinhos = explorar(mapa, jogador->linha, jogador->coluna, tamanho_do_mapa);


	for(; i<NUM_VIZINHOS; i++){
		if((vizinhos[i] > maior) && (vizinhos[i] != 7)){
			maior = vizinhos[i];
			indice_maior = i;
		}
	}
	switch(indice_maior){
		case 0:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->linha--;
			jogador->coluna--;
			break;
		}
		case 1:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->linha--;
			break;
		}
		case 2:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->linha--;
			jogador->coluna++;
			break;
		}
		case 3:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->coluna--;
			break;
		}
		case 4:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->coluna++;
			break;
		}
		case 5:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->linha++;
			jogador->coluna--;
			break;
		}
		case 6:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->linha++;
			break;
		}
		case 7:{
			mapa[jogador->linha][jogador->coluna] = 7;
			jogador->linha++;
			jogador->coluna++;
			break;
		}
	}
	free(vizinhos);
}

//This method evaluates the neighbourhood and choose the better place to move on. But the validation is for each player per time
int *explorar(int **mapa, int linha, int coluna, int tamanho_do_mapa){
	int i=0, j=0, k=0, *vizinhos = NULL;
	vizinhos = (int*) calloc(NUM_VIZINHOS, sizeof(int));

	for(i=-1; i<=1; i++){
		for(j=-1; j<=1; j++){
			if((linha+i >= 0) && (linha+i <= tamanho_do_mapa) && (coluna+j >= 0) && (coluna+j <= tamanho_do_mapa)){
				if(!(i == 0) || !(j == 0)){
					vizinhos[k] = mapa[linha+i][coluna+j];
					k++;
				}
			}
			else{
				vizinhos[k] = INVALIDO;
				k++;
			}
		}
	}
	return vizinhos;
}

void caminho_percorrido(){

}

int possui_pokebolas(t_jogador jogador){
	if(jogador.pokebolas > 0){
		return 1;
	}
	else
		return 0;
}

void pokestop(t_jogador *jogador){
	jogador->pokebolas +=1;
}


