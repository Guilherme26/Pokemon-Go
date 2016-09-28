#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Jogador.h"

#define STR_SIZE 4

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
