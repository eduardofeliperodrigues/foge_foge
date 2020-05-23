#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

void fantasmas(){
    for (int i=0; i < m.linhas; i++){
        for(int j=0; j < m.colunas; j++){
            if (m.matriz[i][j] == FANTASMA){
                if(ehvalida(&m, i, j+1)){
                    andamapa(&m, i, j, i , j+1);
                }
            }
        }
    }
}

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
    return 0;
}

int ehdirecao(char direcao){
    return direcao == ESQUERDA || direcao == DIREITA || direcao == CIMA || direcao == BAIX;
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

    if(!ehvalida(&m, proximox, proximoy))
        return;

    if(!ehmapa(&m, proximox, proximoy))
        return;
        
    andamapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}