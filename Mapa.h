typedef struct{
	int **mapa;
}t_mapa;

int **aloca(int tamanho_mapa);

void inicia_mapa(int **mapa, FILE *in, int tamanho_mapa);

void exibe_mapa(int **mapa, int tamanho_mapa);
