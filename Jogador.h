typedef struct{
	int id;
	int passos;
	int pokebolas;
	int pontos;
	int linha;
	int coluna;
}t_jogador;

t_jogador *aloca_jogador(int numero_de_jogadores);

void inicia_player(t_jogador *vetor_de_jogadores, FILE *in, int numero_de_jogadores);

void exibe_jogadores(t_jogador *vetor_de_jogadores, int numero_de_jogadores);