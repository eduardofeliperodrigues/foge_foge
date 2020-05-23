struct mapa
{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct posicao
{
    int x;
    int y;
};

typedef struct posicao POSICAO;

void liberaMapa();
void leMapa();
void alocaMapa();
void printMapa();
void encontraMapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA*m, int x, int y);
int ehcaminho(MAPA*m , int x, int y);
void andamapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);

#define VAZIO '.'