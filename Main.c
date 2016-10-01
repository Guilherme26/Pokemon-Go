#include <stdio.h>
#include "Jogador.h"
#include "Mapa.h"

int main(){
//Declarations
	int tamanho_mapa = 0, numero_de_jogadores = 0;
	t_mapa mapa; 
	t_jogador *vetor_de_jogadores;
	FILE *in = fopen("entrada.txt", "r");

//Begin of functions calls
	fscanf(in, "%d", &tamanho_mapa);
	printf("%d\n", tamanho_mapa);//Debugger

	//Initialize map
		mapa.mapa = aloca(tamanho_mapa);
		inicia_mapa(mapa.mapa, in, tamanho_mapa);
	
	fscanf(in, "%d", &numero_de_jogadores);
	printf("%d\n", numero_de_jogadores);//Debugger
	
	//Initialize players
		vetor_de_jogadores = aloca_jogador(numero_de_jogadores);
		inicia_player(vetor_de_jogadores, in, numero_de_jogadores);

	fclose(in);

	int condicao = 1;
	while(condicao){
		condicao = andar(&vetor_de_jogadores[0], numero_de_jogadores, mapa.mapa, tamanho_mapa);
	}

	exibe_mapa(mapa.mapa, tamanho_mapa);

	return 0;
}