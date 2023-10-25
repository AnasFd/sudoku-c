#include "gridCreation.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Initialisation
    int **grid = createGrid();
    if(!createValidGrid(grid))
        return 0;

    print_grid(grid);
    free_grid(grid);
    
    return 1;
}