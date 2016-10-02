#include <stdio.h>
#include "Jogador.h"
#include "Mapa.h"
#include "Lista.h"

int main(){
//Declarations
	int tamanho_mapa = 0, numero_de_jogadores = 0;
	t_mapa mapa; 
	t_jogador *vetor_de_jogadores;
	t_lista *caminho_jogador;
	FILE *in = fopen("entrada.txt", "r");

//Begin of functions calls
	fscanf(in, "%d", &tamanho_mapa);

	//Initialize map
		mapa.mapa = aloca(tamanho_mapa);
		inicia_mapa(mapa.mapa, in, tamanho_mapa);
	
	fscanf(in, "%d", &numero_de_jogadores);
	
	//Initialize players
		vetor_de_jogadores = aloca_jogador(numero_de_jogadores);
		inicia_player(vetor_de_jogadores, in, numero_de_jogadores);

	//Initialize List
		caminho_jogador = aloca_lista(numero_de_jogadores);

	fclose(in);

	int i;
	for(i=0; i<numero_de_jogadores; i++){
		int condicao = 1;
		while(condicao){
			condicao = andar(&vetor_de_jogadores[3], numero_de_jogadores, mapa.mapa, tamanho_mapa);
		}

		exibe_mapa(mapa.mapa, tamanho_mapa);

		FILE *in = fopen("entrada.txt", "r");
		fscanf(in, "%d", &tamanho_mapa);
		inicia_mapa(mapa.mapa, in, tamanho_mapa);
		fclose(in);
		
		printf("\n\n");
	}


	return 0;
}