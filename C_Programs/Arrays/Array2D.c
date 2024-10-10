#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int max(int rows, int cols, int array[rows][cols]);
int rowSum(int rows, int cols, int array[rows][cols]);
int columnSum(int rows, int cols, int array[rows][cols]);
int isSquare(int rows, int cols);

void displayOutputs(int rows, int cols, int array[rows][cols]);

int main() {
    puts("Welcome to Processing 2D Arrays!\n");

    int rows = 0;
    int cols = 0;

    printf("\nEnter number of rows: ");
    scanf("%d", &rows);

    printf("\nEnter number of columns: ");
    scanf("%d", &cols);

    int array[rows][cols];

    // entered num in array
    int arrNum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &arrNum);

            array[i][j] = arrNum;
        }
        printf("\n");
    }

    displayOutputs(rows, cols, array);

    return 0;
}

int max(int rows, int cols, int array[rows][cols]) {
    // Implementation of max function goes here
    return 0;
}

int rowSum(int rows, int cols, int array[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += array[i][j];
        }
        printf("Sum of row %d: %d\n", i + 1, sum);
    }
    return 0;  // You can modify the return value based on your needs
}


int columnSum(int rows, int cols, int array[rows][cols]) {
    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += array[i][j];
        }
        printf("Sum of column %d: %d\n", j + 1, sum);
    }
    return 0;  // You can modify the return value based on your needs
}


int isSquare(int rows, int cols) {
    // Implementation of isSquare function goes here
    return 0;
}

void displayOutputs(int rows, int cols, int array[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

