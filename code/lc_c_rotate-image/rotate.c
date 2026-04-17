#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {

    // init row and col for local use
    int row = matrixSize;
    int col = *matrixColSize;

    // determine the number of layers required for looping
    int layers;
    if (1 == row % 2) layers= col / 2;
    else              layers= col / 2 + 1;

    //int test = 5/2;
    //printf("%d\n", loop);
    //printf("%d\n", test);

    int currLayer = 0;
    while (currLayer < layers) {
        int bound = col - (currLayer * 2);
        int currRow = 0, currCol = 0;
        for (int i = 0; i < bound; i++) {
            int carried = matrix[currRow][currCol];

            // 4 step cycle replacement; moves initial element to rotated
            // position which cascades through relevant elements
            for (int j = 0; j < 4; j++) {
                int nextRow = matrixSize-1-currCol;
                int nextCol = currRow;
                int displaced = matrix[nextRow][nextCol];
                matrix[nextRow][nextCol] = carried;
                carried = displaced;
                currRow = nextRow;
                currCol = nextCol;
            }
        }
        currLayer++;
    }
}

/*****************************************************************************
 *****************************************************************************/

void printMatrix(int**, int, int*);
int** createMatrix(int, int);

int main() {
    int row = 3;
    int col = 3;
    int* column = &col;
    int** matrix = createMatrix(row, *column);

    int counter = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < *column; j++) {
            matrix[i][j] = counter++;
        }
    }

    printMatrix(matrix, row, column);
    rotate(matrix, row, column);
    printMatrix(matrix, row, column);

    free(matrix);
}

void printMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** createMatrix(int rows, int cols) {
    int** matrix = malloc(rows * sizeof(int*));
    if (!matrix) return NULL;

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            // cleanup if allocation fails
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}
