/* 
Kriti Baru
February 18, 2024
CIS 2107
HW 5: 2D Arrays
*/

// preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// function definitions
int max();
int rowSum();
int columnSum();
int isSquare();
void displayOutputs(int rows, int cols, int array[rows][cols]);

int main(){
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

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &arrNum);

            array[i][j] = arrNum;

        }
        printf("\n");
    }

    displayOutputs(rows, cols, array);
  
}


int max(){

    return 0;
}

void displayOutputs(int rows, int cols, int array[rows][cols]){

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

}