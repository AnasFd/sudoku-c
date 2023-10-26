#ifndef GRIDCREATION_H
#define GRIDCREATION_H

/* Main grid functions */
int **createGrid(void); // Does the creation and initialisation at 0 using calloc
void free_grid(int **grid);
void print_grid(int **grid);
void fill_grid(int **grid);

/* Filling diagonal subgrids */
void fillDiagonalSubgrids(int **grid);
void fillSubgrid(int **grid, int start_row, int start_col, int* numbers);
void shuffleTable(int* tab);

/* Placement functions */
int isValidPlacement(int **grid, int row, int column, int number);
int isValidSubGrid(int **grid, int row, int column, int number);
int isValidRow(int **grid, int row, int number);
int isValidColumn(int **grid, int column, int number);

/* Grid creation functions */
int findEmptyCell(int **grid, int *row, int *col); // Could use some optimization
int solveSudoku(int **grid);
int createValidGrid(int **grid);

#endif
