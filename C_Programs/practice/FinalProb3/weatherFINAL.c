/** Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Constantants for matrix size **/
#define ROWS 10
#define COLS 5

/**
1.	(5 points) Write a struct named data_t that contains the following double precision weather related data:
    a.	high (daily forecasted high temperature)
    b.	low (daily forecasted low temperature)
    c.	precip (daily percent chance of precipitation)
    d.	wind (daily forecast for wind speed in MPH)
    e.	humid (daily forecast for humidity)
**/

typedef struct data_t {
    double high;
    double low;
    double precip;
    double wind;
    double humid;
} data_t; 

typedef struct datalists {
    data_t temps;
    int count;
} datalists;

// Prototypes
int read_data(data_t data[], char *filename);
void print_data(data_t data[], int rows);
void sum(double sums[], data_t data[], int rows);
void avg(double avgs[], data_t data[], int rows);
void print_avgs(double avgs[]);
void write_avgs(double avgs[], char *filename);

/**
2.	Free code: main() and has an array of data_t called data[] that stores 10 structs,
an integer rows to receive the number of records read, an array of 5 double named
avgs to contain the avg of all high, low, precip, wind and humid.
**/
int main(){
    data_t data[ROWS];
    int rows;
    double avgs[COLS];


    rows =  read_data(data, "weather.txt");
    //print_data(data, rows);
    //avg(avgs, data, rows);
    //print_avgs(avgs);
    //write_avgs(avgs, "output.txt");

    return 0;
}


/**
3.	(15 points) Write function called read_data() to read the data from the data file �weather.txt�.
Open the file with notepad to see its contents.  There are 10 (ROWS) lines of data, each
containing the five (COLS) doubles of data in the same order as in Step 2 above.   The
function should accept the data[] array from main and populate it with data using a loop,
and the filename to open and return the count of records read.

Hint: You can use fgets and strtok, or fscanf to read the file.
**/
int read_data(data_t data[], char *filename) {
    int count = 0;
    char buffer[200];

    FILE* file;
    filename = "weatherTXT.txt";
    file = fopen(filename, "r");
    if (file == NULL)
        perror("Does not exist");
    
    
    
    while (fgets(buffer, 200, file) != NULL) {
        char* tk = strtok(buffer, " ");

        buffer[strlen(buffer)-1] = "\0";
        printf("%s\n", buffer);
        count +=1;

        //char buffer2[] = "111 222 333";
        // get "111"
        tk = strtok(buffer, " "); // remember to update the first argument to buffer2 for the first time tokenizing buffer2
        printf("%s ", tk);
        // get "222"
        tk = strtok(NULL, " "); // do not update the first argument, we are still on buffer2
        printf("%s ", tk);
        // get "333"
        tk = strtok(NULL, " "); // do not update
        printf("%s", tk);
        printf("\n");
    }

    count = atoi(buffer);
    printf("data[] = %s\n", data[count]);
    return data[count];
}


/**
4.	(5 points) Write function called print_data() to print the array data[] to screen using a loop
as shown in the output below.  It should accept the data array and the filename to read.
This should be called from main after the data is read.  Use 2 digits of precision in
the printf().
5.	Test that you program reads the data properly by calling read_data() then print_data().
**/



/**
6.	(5 points) Write function called sum() to calculate the sum of each datum in the array of data_t.
This requires you pass the data_t array and an array sums[] by reference with 5 doubles,
one for each datum in the struct.  When complete sums[0] should contain the sum of all
daily highs, sums[1] for daily lows, etc.  You will need to pass sums[] and data[] into
sum() from the avg() function described below.
**/



/**
7.	(5 points) Write function called avg() to calculate the average for each datum in the array of
data_t.  The function accept the avgs array and the number of rowsThis function should
call sum() to get a vector for the sum of each datum in the array of data_t.  It should
calculate avgs[i] = sums[i]/rows (=10) in a loop.  The avg() function will be called
from main().

avg should:
    a. Declare and initialize an double array of sums with 5 elements initialized to zeros
    b. Call the sums function to calc sums
    c. Calc averages

**/



/**
8.	(5 points) Write a function called print_avgs() to print the averages to screen as shown in the
output below.  Use 2 digits of precision in the printf().
9.	Test that your program calculates the average by printing the average to screen.
**/



/**
10.	(10 points) Write a function called write_avgs() that writes the averages to a file named �output.txt�.
Use 2 digits of precision in the fprintf().  Hint:  You can copy code from print_avgs(), paste
it and modify it to save some key strokes.
11.	Check that file was written
**/



/**
12.	Close the editor and submit your source code file to Canvas
**/

/// Sample screen output
/**
    File read.

    Read:
    63.00 53.00 0.00 11.00 49.00
    76.00 55.00 20.00 8.00 67.00
    77.00 52.00 20.00 6.00 64.00
    66.00 48.00 10.00 8.00 50.00
    53.00 45.00 100.00 10.00 78.00
    65.00 45.00 10.00 9.00 56.00
    63.00 47.00 20.00 9.00 52.00
    68.00 49.00 10.00 7.00 54.00
    71.00 52.00 20.00 7.00 55.00
    73.00 56.00 20.00 10.00 54.00

    The averages are:
    Average high 67.50
    Average low 50.20
    Average precipitation 23.00
    Average wind 8.50
    Average humidity 57.90

    File written.

    Process returned 0 (0x0)   execution time : 2.692 s
    Press any key to continue.
*/


/// Sample file output
/**
    The averages are:
    Average high 67.50
    Average low 50.20
    Average precipitation 23.00
    Average wind 8.50
    Average humidity 57.90
*/
