typedef struct celula{
	int linha;
	int coluna;
	struct celula *prox;
}t_celula;

typedef struct{
	t_celula *primeiro;
	t_celula *ultimo;
}t_lista;

void FLV(t_lista *lista_caminho, t_jogador jogador);

int vazia(t_lista lista_caminho);

void adiciona_passo(t_lista *lista_caminho, t_jogador jogador);

t_lista *aloca_lista(int numero_de_jogadores);
