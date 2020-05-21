#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int main(){

    leMapa(&m);
    encontraMapa(&m, &heroi, '@');
    
    do{
        printMapa(&m);

        char comando;
        scanf("%c",&comando);
        fflush(stdin);
        move(comando);

    }while(!acabou());

    liberaMapa(&m);
}

int acabou(){
    return 0;
}

void move(char direction){

    m.matriz[heroi.x][heroi.y] = '.';

    switch (direction)
    {
    case 'a':
        m.matriz[heroi.x][heroi.y-1] = '@';
        heroi.y--;
        break;
    case 'w':
        m.matriz[heroi.x-1][heroi.y] = '@';
        heroi.x--;
        break;
    case 's':
        m.matriz[heroi.x+1][heroi.y] = '@';
        heroi.x++;
        break;
    case 'd':
        m.matriz[heroi.x][heroi.y+1]='@';
        heroi.y++;
        break;
    }

}