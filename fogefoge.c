#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "mapa.h"

MAPA m;
MAPA copia;
POSICAO heroi;

int main(){

    leMapa(&m);
    encontraMapa(&m, &heroi, PERSONAGEM);
    
    do{
        printMapa(&m);

        char comando;
        scanf("%c",&comando);
        fflush(stdin);

        move(comando);

        fantasmas();

    }while(!acabou());

    liberaMapa(&m);
}

int acabou(){
    POSICAO pos;
    int encontrou = encontraMapa(&m, &pos, PERSONAGEM);
    return !encontrou;
}

int ehdirecao(char direcao){
    return direcao == ESQUERDA || direcao == DIREITA || direcao == CIMA || direcao == BAIXO;
}

void move(char direction){

    if (!ehdirecao(direction))
        return;
    
    int proximox = heroi.x;
    int proximoy = heroi.y;


    switch (direction)
    {
    case ESQUERDA:
        proximoy--;
        break;
    case CIMA:
        proximox--;
        break;
    case BAIXO:
        proximox++;
        break;
    case DIREITA:
        proximoy++;
        break;
    }

    if(!podeandar(&m, PERSONAGEM, proximox, proximoy))
        return;
        
    andamapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int praondeofantasmavai(int xatual, int yatual,int* xdestino, int* ydestino){
    int opcoes[4][2] = {
        {xatual, yatual -1},
        {xatual-1, yatual},
        {xatual, yatual+1},
        {xatual+1, yatual}
    };
    srand(time(0));
    for(int i = 0; i <10; i++){
        int posicao = rand() % 4;

        if (podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;

        }
    }

    return 0;
}

void fantasmas(){

    copiamapa(&copia, &m);

    for (int i=0; i < m.linhas; i++){
        for(int j=0; j < m.colunas; j++){
                
            if (copia.matriz[i][j] == FANTASMA){
                int xdestino;
                int ydestino;

                int encontrou = praondeofantasmavai(i, j, &xdestino, &ydestino);
                
                if(encontrou){
                    andamapa(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }

    liberaMapa(&copia);
}