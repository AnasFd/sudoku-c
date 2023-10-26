#include "difficulty.h"
#include "gridCreation.h"
#include "headers.h"

int isPartiallyEmpty(int **grid) {
  for (int row = 0; row < GRID_SIZE; row++) {
    for (int col = 0; col < GRID_SIZE; col++) {
      if (grid[row][col] == 0) {
        return 1; // Found an empty cell
      }
    }
  }
  return 0; // No empty cell found
}

int solved(int **easyGrid) {
  int row, col, value, retour = 1;
  char input[10];
  while (isPartiallyEmpty(easyGrid)) {
    print_grid(easyGrid);
    printf("Enter the row (0-8), column (0-8), and value (1-9) to insert\n"
           "(e.g., 3 4 7), or q to exit : ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
      printf("Invalid input\n");
      retour = 0;
      break;
    }

    if (input[0] == 'q') {
      printf("Exiting the game.\n");
      retour = 0;
      break;
    } else if (sscanf(input, "%d %d %d", &row, &col, &value) != 3) {
      printf("Invalid input values lewla\n");
    } else if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE ||
               value < 1 || value > 9) {
      printf("Invalid input values tanya\n");
    } else {
      // Inserting the value into the easyGrid
      if (easyGrid[row][col] == 0) {
        if (isValidPlacement(easyGrid, row, col, value)) {
          easyGrid[row][col] = value;
          printf("Value inserted successfully.\n");
        } else
          printf("Invalid placement for the value.\n");
      } else
        printf("Cell is not empty.\n");
    }
  }
  return retour;
}
