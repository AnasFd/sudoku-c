#include "headers.h"

// Function that removes numbers from a valid sudoku grid
int **copyOf(int **validGrid){
    int **easyGrid = createGrid();
    for(int i = 0; i < GRID_SIZE; i++)
        for(int j = 0; j < GRID_SIZE; j++)
            easyGrid[i][j] = validGrid[i][j];
    return easyGrid;
}

void generateGridByDifficulty(int **copiedGrid, int dificulty){
    srand(time(NULL));
    for (int i = 0; i < dificulty; i++) {
        int seed = (int)time(NULL) + i;
        srand(seed);
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        copiedGrid[row][col] = 0;
    }
}