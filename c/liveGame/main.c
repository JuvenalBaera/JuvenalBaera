#include <stdio.h>
#include <stdlib.h>

#define TAM_MAT 25

void inicializar_matriz(char matriz[TAM_MAT][TAM_MAT], char dead){
    char live = 219;

    for(int i = 0; i < TAM_MAT; i++)
        for(int j = 0; j < TAM_MAT; j++)
            matriz[i][j] = dead;
    
    matriz[3][3] = live;
    matriz[4][3] = live;
    matriz[5][3] = live;
    matriz[5][4] = live;
    matriz[4][5] = live;
    matriz[5][5] = live;
    matriz[5][6] = live;

    matriz[10][10] = live;
    matriz[10][11] = live;
    matriz[11][11] = live;
    matriz[9][12] = live;
    matriz[8][3] = live;
    matriz[7][3] = live;


    matriz[1][13] = live;
    matriz[1][14] = live;
    matriz[2][14] = live;

    matriz[15][15] = live;

    matriz[20][15] = live;
    matriz[21][16] = live;

    matriz[25][20] = live;
    matriz[25][19] = live;
    matriz[25][18] = live;
    matriz[24][19] = live;
    matriz[21][21] = live;
    matriz[22][21] = live;
    matriz[22][22] = live;
    matriz[23][23] = live;
}

int total_vivo_redor(char matriz[TAM_MAT][TAM_MAT], int i, int j){
    char live = 219;
    unsigned short int countlive = 0;

    if(matriz[i-1][j] == live)
        countlive++;
    if(matriz[i+1][j] == live)
        countlive++;
    if(matriz[i][j-1] == live)
        countlive++;
    if(matriz[i][j+1] == live)
        countlive++;
    if(matriz[i-1][j-1] == live)
        countlive++;
    if(matriz[i+1][j+1] == live)
        countlive++;
    if(matriz[i-1][j+1] == live)
        countlive++;
    if(matriz[i+1][j-1] == live)
        countlive++;
    return countlive;
}

void copy_gen(char aGen[TAM_MAT][TAM_MAT], char nGen[TAM_MAT][TAM_MAT]){
    for(int i = 0; i < TAM_MAT; i++)
        for(int j = 0; j < TAM_MAT; j++)
            aGen[i][j] = nGen[i][j];
}

void print_matriz(char matriz[TAM_MAT][TAM_MAT]){
    system("cls");
    printf("\n ");
    for(int i = 0; i < TAM_MAT; i++)
        printf(" %2d ", i);
    printf("\n");
    for(int i = 0; i < TAM_MAT; i++){
        printf("%2d", i);
        for(int j = 0; j < TAM_MAT; j++){
            printf(" %c  ", matriz[i][j]);
        }
        printf("%d", i);
        putchar('\n');
    }
    for(int i = 0; i < TAM_MAT; i++)
    printf(" %2d ", i);
}

void intro(){
    system("cls");
    printf("==========================================\n");
    printf("Autor    : Juvenal Baera :)\n");
    printf("Data     : 27 de Novembro de 2022\n");
    printf("Descricao: Baseado no jogo de vida e morte\n\t\tde John Conway\n");
    printf("==========================================\n");
}

int main(){

    char atualGen[TAM_MAT][TAM_MAT];
    char nextGen[TAM_MAT][TAM_MAT];
    char dead = ' ', live = 219;

    int i, j, totalVivo=0;

    intro();
    printf("\nClique <ENTER> para continuar>>>");
    getchar();
    

    inicializar_matriz(atualGen, dead);
    inicializar_matriz(nextGen, dead);
    print_matriz(atualGen);
    printf("\nClique <ENTER> para comecar a simulacao>>>");
    getchar();
    
    while(1){
        for(i = 0; i < TAM_MAT; i++){
            for(j = 0; j < TAM_MAT; j++){
                totalVivo = total_vivo_redor(atualGen, i, j);
                if(totalVivo == 2)
                    nextGen[i][j] = atualGen[i][j];
                else if (totalVivo == 3)
                    nextGen[i][j] = live;
                else
                    nextGen[i][j] = dead;
            }
        }
        print_matriz(nextGen);
        printf("\nContrl C para para sair\n");
        copy_gen(atualGen, nextGen);
    }

    return 0;
}