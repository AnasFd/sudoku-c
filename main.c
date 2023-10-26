#include "headers.h"

#define EASY 27
#define MEDIUM 40
#define HARD 54

int main(void) {
    // Initialisation
    int **validGrid = createGrid();
    if(!createValidGrid(validGrid)) {
        perror("Unable to create a grid");
        exit(1);
    }

    printf("Valid grid: \n\n");
    print_grid(validGrid);
    printf("\n\n");

    int **easyGrid = copyOf(validGrid);
    generateGridByDifficulty(easyGrid, EASY);
    printf("Easy grid: \n\n");
    print_grid(easyGrid);

    free_grid(validGrid);
    free_grid(easyGrid);
    
    return 0;
}