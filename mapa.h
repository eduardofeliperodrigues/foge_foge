#ifndef MAPA_H_
#define MAPA_H_

#define PERSONAGEM '@'
#define FANTASMA 'F'
#define PILULA 'P'
#define VAZIO '.'
#define PAREDEVERTICAL '|'
#define PAREDEHORIZONTAL '-'

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
int encontraMapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA*m, int x, int y);
int ehcaminho(MAPA*m , int x, int y);
void andamapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);

#endif