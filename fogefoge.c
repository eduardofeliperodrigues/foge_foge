#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// para declarar uma matriz passa a primeira dimensão [linhas], e segunda dimensão [colunas].

MAPA m;

int main(){

    leMapa();
    
    do{
        printMapa();

        char comando;
        scanf("%c",&comando);
        fflush(stdin);
        move(comando);

    }while(!acabou());

    liberaMapa();
}


void liberaMapa(){
    /// Limpeza da memoria alocada;
    for (int i = 0; i < m.linhas; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
    ///
}

int acabou(){
    return 0;
}

void move(char direction){
    int x, y;

    //acha a posição do foge foge
    for (int i =0; i < m.linhas; i++){
        for(int j =0; j < m.colunas; j++){
            if(m.matriz[i][j] == '@'){
                x = i;
                y = j;
            }
        }
    }

    switch (direction)
    {
    case 'a':
        m.matriz[x][y-1] = '@';
        break;
    case 'w':
        m.matriz[x-1][y] = '@';
        break;
    case 's':
        m.matriz[x+1][y] = '@';
        break;
    case 'd':
        m.matriz[x][y+1]='@';
        break;
    }

    m.matriz[x][y]= '.';

}

void leMapa(){
    FILE* f;
    
    f = fopen("mapa.txt", "r");

    if (f == 0){
        printf("Erro na abertura do mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

    alocaMapa();

    for(int i = 0; i < m.linhas; i++){
        fscanf(f, "%s", m.matriz[i]);
    }

    fclose(f);
}

void alocaMapa(){
    /// Alocação dinamica de memoria;
    m.matriz = malloc(sizeof(char*) * m.linhas);

    for (int i =0; i<5; i++){
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));
    }
    ///
}

void printMapa(){
    for(int i =0; i< m.linhas; i++){
        printf("%s\n", m.matriz[i]);
    }
}