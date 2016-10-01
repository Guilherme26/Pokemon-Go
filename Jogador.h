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

int andar(t_jogador *jogador, int numero_de_jogadores, int **mapa, int tamanho_do_mapa);

int *explorar(int **mapa, int linha, int coluna, int tamanho_do_mapa);

void caminho_percorrido();

int possui_pokebolas(t_jogador jogador);

void pokestop(t_jogador *jogador);
