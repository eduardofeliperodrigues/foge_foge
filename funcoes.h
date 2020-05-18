void liberaMapa();
void leMapa();
void alocaMapa();
void printMapa();
void move(char direction);
int acabou();

struct mapa
{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

