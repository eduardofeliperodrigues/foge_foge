#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// para declarar uma matriz passa a primeira dimensão [linhas], e segunda dimensão [colunas].
char** mapa;
int linhas;
int colunas;

int main(){

    leMapa();

    printMapa();

    liberaMapa();
}


void liberaMapa(){
    /// Limpeza da memoria alocada;
    for (int i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
    ///
}

void leMapa(){
    FILE* f;
    
    f = fopen("mapa.txt", "r");

    if (f == 0){
        printf("Erro na abertura do mapa\n");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);

    alocaMapa();

    for(int i = 0; i < linhas; i++){
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

void alocaMapa(){
    /// Alocação dinamica de memoria;
    mapa = malloc(sizeof(char*) * linhas);

    for (int i =0; i<5; i++){
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
    ///
}

void printMapa(){
    for(int i =0; i< linhas; i++){
        printf("%s\n", mapa[i]);
    }
}