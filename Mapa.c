#include <stdio.h>
#include <stdlib.h>
#include "Mapa.h"

//This function dynamically allocates the map matrix
int **aloca(int tamanho_mapa){
	int **mapa, i;
	mapa = (int**) calloc(tamanho_mapa, sizeof(int*));
	for(i=0; i<tamanho_mapa; i++){
		mapa[i] = (int*) calloc(tamanho_mapa, sizeof(int));
	}

	return mapa;
}

//This method set the map coordinates
void inicia_mapa(int **mapa, FILE *in, int tamanho_mapa){
	int i, j;
	for(i=0; i<tamanho_mapa; i++){
		for(j=0; j<tamanho_mapa; j++){
			fscanf(in, "%d", &mapa[i][j]);
		}
	}
}

//This method show every map coordinate
void exibe_mapa(int **mapa, int tamanho_mapa){
	int i, j;
	for (i=0; i<tamanho_mapa; i++)	{
		for (j=0; j<tamanho_mapa; j++){
			printf("%d", mapa[i][j]);
		}
		printf("\n");
	}
}
