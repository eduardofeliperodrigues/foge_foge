#ifndef FUNCOES_H_
#define FUNCOES_H_

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char direction);

int ehdirecao(char direcao);
void fantasmas();

int praondeofantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
void explodePilula();
void explodePilula2(int x, int y, int somax, int somay, int qtd);

#endif