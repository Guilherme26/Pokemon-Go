#include <stdio.h>
#include <stdlib.h>
#include "Jogador.h"
#include "Mapa.h"

int main(){
	//Declarations
	int tamanho_mapa = 0, numero_de_jogadores = 0;
	t_mapa mapa; 
	t_jogador *vetor_de_jogadores;
	t_lista *caminho_jogador = (t_lista*) malloc(sizeof(t_lista));;
	FILE *in = fopen("entrada.txt", "r");
	FILE *out = fopen("saida.txt", "w");


	fscanf(in, "%d", &tamanho_mapa);
	//Initialize map
		mapa.mapa = aloca(tamanho_mapa);
		inicia_mapa(mapa.mapa, in, tamanho_mapa);
	fscanf(in, "%d", &numero_de_jogadores);	
	//Initialize players
		vetor_de_jogadores = aloca_jogador(numero_de_jogadores);
		inicia_player(vetor_de_jogadores, in, numero_de_jogadores);

	fclose(in);

	int i;
	for(i=0; i<numero_de_jogadores; i++){
		int condicao = 1;
		FLV(caminho_jogador, vetor_de_jogadores[i]);
		while(condicao){
			condicao = andar(&vetor_de_jogadores[i], caminho_jogador, numero_de_jogadores, mapa.mapa, tamanho_mapa);
		}

		imprime_saida(caminho_jogador, vetor_de_jogadores[i], out);

		FILE *in = fopen("entrada.txt", "r");
		fscanf(in, "%d", &tamanho_mapa);
		inicia_mapa(mapa.mapa, in, tamanho_mapa);
		fclose(in);
	}


	int *vencedores = vencedor(vetor_de_jogadores, numero_de_jogadores);
	fprintf(out, "VENCEDOR: ");
	for(i=0; i<numero_de_jogadores; i++){
		if(vencedores[i] == 1)
			fprintf(out, "J%d ", i+1);
	}

	fclose(out);
	return 0;
}