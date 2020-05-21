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