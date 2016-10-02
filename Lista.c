#include <stdlib.h>
#include <stdio.h>
#include "Jogador.h"
#include "Lista.h"

void FLV(t_lista *lista_caminho, t_jogador jogador){
	t_celula *no = (t_celula*) malloc(sizeof(t_celula));
	lista_caminho->primeiro = no;
	lista_caminho->ultimo = no;

	//Set player's coordinate
	lista_caminho->primeiro->linha = jogador.linha;
	lista_caminho->primeiro->coluna = jogador.coluna;
	lista_caminho->primeiro->prox = NULL;
}

int vazia(t_lista lista_caminho){
	if(lista_caminho.primeiro == lista_caminho.ultimo)
		return 1;
	else
		return 0;
}

void adiciona_passo(t_lista *lista_caminho, t_jogador jogador){
	t_celula *no = (t_celula*) malloc(sizeof(t_celula));
	
	no->linha = jogador.linha;
	no->coluna = jogador.coluna;
	no->prox = NULL;

	lista_caminho->ultimo->prox = no;
	lista_caminho->ultimo = no;
}

t_lista *aloca_lista(int numero_de_jogadores){
	t_lista *caminho = (t_lista*) calloc(numero_de_jogadores, sizeof(t_lista));
	return caminho;
}
