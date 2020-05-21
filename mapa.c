#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
void leMapa(MAPA* m){
    FILE* f;
    
    f = fopen("mapa.txt", "r");

    if (f == 0){
        printf("Erro na abertura do mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocaMapa(m);

    for(int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void alocaMapa(MAPA* m){
    /// Alocação dinamica de memoria;
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for (int i =0; i<5; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
    ///
}

void printMapa(MAPA* m){
    for(int i =0; i< m->linhas; i++){
        printf("%s\n", m->matriz[i]);
    }
}

void liberaMapa(MAPA* m){
    /// Limpeza da memoria alocada;
    for (int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }

    free(m->matriz);
    ///
}

void encontraMapa(MAPA* m, POSICAO* p, char c){
    //acha a posição do foge foge
    for (int i =0; i < m->linhas; i++){
        for(int j =0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
            }
        }
    }
}