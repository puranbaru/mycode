#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** Constants for matrix size */
#define ROWS 20
#define COLS 5

/** Step 1: Write a struct that contains 3 doubles: low, high
and avg, named stats_t. */
typedef struct stats_t
{
    double low;
    double high;
    double avg;
}stats_t;

typedef struct statsList
{
    stats_t stats[ROWS];
    int length;
    int count;
}statsList;

/** Function prototypes */
int read_temps(double temps[][COLS], char *filename);
double find_low(double row[], int length);
double find_high(double row[], int length);
double find_avg(double row[], int length);
void print_stats(stats_t stats);
void print_stats_array(stats_t *array, int count);
void calc_stats(stats_t *stats, double temps[][COLS], int count);
void write(stats_t *stats, int count, char *filename);


/** Step 2: Write main function. */
int main()
{

    FILE *filePointer;
    char* filename = "Final_temps.txt";
    double temps[ROWS][COLS];
    read_temps(temps,  filename);

    // filePointer = fopen(filename, "w+");
    // if (filePointer == NULL)
    // {
    //     printf("Requested file does not exists in system or not found. \n");
    //     return 0;
    // }



    //print_employee(el.employees[0]);
    
    //print_employee_list(&el);
    
    //Expense calculations
    // ExpenseList exl = create_expense_list();
    // int countexp = read_expenses(&exl);
    
    // //print_expense(exl.expenses[0]);
    // print_expense_list(&exl);
    
    // // Calculate all expenses for individuals
    // calc_expense(&el, &exl);
    
    return 0;
}



/** Step 3: Write function to read the three rows of doubles
from file into a matrix.  The function should be named read.
The function should use scanf to read 5 doubles from each line.
The loop should terminate when EOF is returned by scanf.  The
main function should print the number of rows read from the
file. Note that the #defines for ROWS and COLS of the matrix is
included in the starter file with all function prototypes. */
/** Step 4: Test that you program opens the file and reads the
data properly by calling read function from main and returning the
matrix as an output parameter. */
int read_temps(double temps[][COLS], char *file) {
    int i= 0;
    FILE *filename;
    filename = fopen(file, "r");
    for (fscanf(file, ("%lf\t%lf\t%lf\t%lf\t%lf", &temps[i][0], &temps[i][1], &temps[i][2], &temps[i][3], &temps[i][4]) != EOF;) i++;) {
        printf("%lf %lf %lf %lf %lf", temps[i][0], temps[i][1], temps[i][2], temps[i][3], temps[i][4]);
    }
    
    // while(fscanf(filename,("%lf %lf %lf %lf %lf", &temps[i][0], &temps[i][1], &temps[i][2], &temps[i][3]), &temps[i][4])) != EOF) {
    //     printf("%lf %lf %lf %lf %lf", temps[i][0], temps[i][1], temps[i][2], temps[i][3], temps[i][4]);
    // }
    fclose(filename);
    return 0;
}

/** Step 5: Write function called print_stats to print a stats_t
struct to screen. */



/** Step 6: Write a function called print_stats_array to print an
array of stats_t structs to screen by repetitively calling
print_stats. */



/** Step 7: Write a function called find_low to find a low temp in a
row of the temps matrix (Hint: passing temps[i] will pass a row of a
matrix). */



/** Step 8: Copy find_low and paste it below find_low.  Rename it to
find_high and modify it to find the high temp in a row. */


/** Step 9: Write a function calc_avg to calculate the average
temp in a row. */



/** Step 10: Write function calc_stats to calculate the low, high
and avg for each row, storing the result in the array of stats_t.
Note that COLS has the number of elements in each row. */
/**  Step 11: Test that your program calculates the stats by printing
them to the screen from main using the print_stats_array function. */


/** Step 12: Write function write to write the stats_t array to a file as
shown in the output in doc. */
/** Step 13: Test that your program writes the file. */


/** Step 14: Close the editor and submit your source code file to Canvas. */

