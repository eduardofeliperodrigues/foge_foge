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

    if (direction != 'a' &&
        direction != 's' &&
        direction != 'd' &&
        direction != 'w'){
        return;
        }
    
    int proximox = heroi.x;
    int proximoy = heroi.y;


    switch (direction)
    {
    case 'a':
        proximoy--;
        break;
    case 'w':
        proximox--;
        break;
    case 's':
        proximox++;
        break;
    case 'd':
        proximoy++;
        break;
    }

    if (proximox >= m.linhas){
        return;
    }
    if (proximoy >= m.colunas){
        return;
    }
    if (m.matriz[proximox][proximoy] != '.'){
        return;
    }

    m.matriz[proximox][proximoy] = '@';
    m.matriz[heroi.x][heroi.y] = '.';
    heroi.x = proximox;
    heroi.y = proximoy;
}