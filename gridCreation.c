#include "headers.h"

int **createGrid(void){
    int **grid = (int **)calloc(GRID_SIZE, sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++){
        grid[i] = (int *)calloc(GRID_SIZE, sizeof(int));
    }
    return grid;
}

void free_grid(int **g){
    for (int i = 0; i < GRID_SIZE; i++)
        free(g[i]);
    free(g);
}

void print_grid(int **g){
    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++){
            printf("%d ", g[i][j]);
            (j == 2 || j == 5) ? printf("\t") : 0;
        }
        printf("\n");
        (i == 2 || i == 5) ? printf("\n") : 0;
    }
}

int isValidRow(int **grid, int row, int number){
    int j=0;
    while(j<GRID_SIZE){
        if(grid[row][j] == number) return 0;
        j++;
    }
    return 1;
}

int isValidColumn(int **grid, int column, int number){
    int i=0;
    while(i<GRID_SIZE){
        if(grid[i][column] == number) return 0;
        i++;
    }
    return 1;
}

int isValidSubGrid(int **grid, int row, int column, int number){
    int startRow = row - (row % SUBGRID_SIZE); // 0 || 3 || 6
    int startCol = column - (column % SUBGRID_SIZE); // 0 || 3 || 6
    for(int i = startRow; i<SUBGRID_SIZE; i++)
        for(int j = startCol; j<SUBGRID_SIZE; j++)
            if(grid[i][j] == number) return 0;
        
    return 1;
}

int isValidPlacement(int **grid, int row, int column, int number){
    return isValidRow(grid, row, number) 
            && isValidColumn(grid, column, number) 
            && isValidSubGrid(grid, row, column, number);
}

void shuffleTable(int* tab){
    // Generate a random permutation of numbers 1 to 9
    srand(time(NULL));
    for (int i = 8; i > 0; i--) {
        int j = rand() % (i + 1); // Generate a random index
        // Swap numbers[i] and numbers[j]
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

void fillSubgrid(int **grid, int start_row, int start_col, int* numbers){
    int index=0;
    for(int row = start_row; row < start_row+SUBGRID_SIZE ; row++){
        for(int col = start_col; col < start_col+SUBGRID_SIZE; col++){
            grid[row][col] = numbers[index++];
        }
    }
}

void fillDiagonalSubgrids(int **grid){
    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i=0; i<GRID_SIZE; i+=3) {
        shuffleTable(numbers);
        fillSubgrid(grid, i, i, numbers);
    }
}

int findEmptyCell(int **grid, int *row, int *col) {
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1; // Found an empty cell
            }
        }
    }
    return 0; // No empty cell found
}

int solveSudoku(int **grid) {
    int row, col;

    // Find the next empty cell, starting from the last known position
    if (!findEmptyCell(grid, &row, &col))
        return 1;

    // Try placing numbers 1 to 9
    for (int num = 1; num <= GRID_SIZE; num++) {
        if (isValidPlacement(grid, row, col, num)) {
            // Place the number
            grid[row][col] = num;

            // Recur to the next empty cell
            if (solveSudoku(grid)) {
                return 1; // Solved
            }

            // If not successful, backtrack
            grid[row][col] = 0;
        }
    }
    return 0; // No solution found
}

int createValidGrid(int **grid) {
    // Filling the diagonal subgrids
    fillDiagonalSubgrids(grid);
    return (solveSudoku(grid));
}
