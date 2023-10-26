#include "gridCreation.h"
#include "headers.h"
#include <stdio.h>
#include <stdlib.h>

int isValidGrid(int **grid) {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            int num = grid[row][col];

            // Check rows and columns for duplicates
            for (int i = 0; i < GRID_SIZE; i++) {
                if (i != col && grid[row][i] == num) {
                    return 0; // Duplicate found in the same row.
                }
                if (i != row && grid[i][col] == num) {
                    return 0; // Duplicate found in the same column.
                }
            }

            // Check the 3x3 subgrid for duplicates
            int startRow = (row / SUBGRID_SIZE) * SUBGRID_SIZE;
            int startCol = (col / SUBGRID_SIZE) * SUBGRID_SIZE;

            for (int i = startRow; i < startRow + SUBGRID_SIZE; i++) {
                for (int j = startCol; j < startCol + SUBGRID_SIZE; j++) {
                    if (i != row && j != col && grid[i][j] == num) {
                        return 0; // Duplicate found in the same subgrid.
                    }
                }
            }
        }
    }

    return 1; // Grid is valid; no duplicates found.
}


int main(void) {
  // Variables
  int **validGrid = createGrid();
  int **easyGrid = createGrid();
  int inputDifficulty;
  int difficulty;

  // Initialisation
  if (!createValidGrid(validGrid)) { // Creates a valid grid (gridCreation.c)
    perror("Unable to create a valid grid");
    EXIT_FAILURE;
  }

  easyGrid = copyOf(validGrid);

  // Asking the user to select a difficulty
  do {
    printf("Select a difficulty (1: easy, 2: medium, 3: hard): ");
    if (scanf("%d", &inputDifficulty) != 1) {
      // Invalid input, clear the input buffer
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      printf("Invalid input. Please enter a valid difficulty level.\n");
      continue;
    }

    // Check if the input is valid
    if (inputDifficulty < 1 || inputDifficulty > 3) {
      printf("Invalid difficulty level. Please enter 1, 2, or 3.\n");
    }
  } while (inputDifficulty < 1 || inputDifficulty > 3);

  if (inputDifficulty == 1)
    difficulty = EASY;
  else if (inputDifficulty == 2)
    difficulty = MEDIUM;
  else
    difficulty = HARD;

  generateGridByDifficulty(easyGrid, difficulty); // generates a grid by difficulty (difficulty.c)


  // Grid generated, let's play
  if (solved(easyGrid))
    printf("Sudoku puzzle solved!\n");
  else
    printf("User exited the program.\n");

  free_grid(validGrid);
  free_grid(easyGrid);

  return 0;
}