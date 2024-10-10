/*
    Please code solutions for the problems below.  You should only have one main function
    and call the required functions for each problem.  Sample output:

    Enter the colors of the resistor's three bands, beginning with
    the band nearest the end. Type the colors in lowercase letters
    only, NO CAPS.
    Band 1 => green
    Band 2 => black
    Band 3 => yellow
    Resistance value: 500 kilo-ohm(s)
    Do you want to decode another resistor: y

    Enter the colors of the resistor's three bands, beginning with
    the band nearest the end. Type the colors in lowercase letters
    only, NO CAPS.
    Band 1 => brown
    Band 2 => vilet
    Band 3 => gray
    Resistance value: -1 kilo-ohm(s)
    Do you want to decode another resistor: n

    Enter a string: chair
    The plural of chair is chairs
    Do you want to convert another string: y

    Enter a string: dairy
    The plural of dairy is dairies
    Do you want to convert another string: y

    Enter a string: boss
    The plural of boss is bosses
    Do you want to convert another string: n

    Enter first string: procrastination
    Enter second string: destination
    The suffix of procrastination and destination is stination
    Do you want to find another suffix: y

    Enter first string: globally
    Enter second string: internally
    The suffix of globally and internally is ally
    Do you want to find another suffix: y

    Enter first string: gloves
    Enter second string: dove
    The suffix of gloves and dove is
    Do you want to find another suffix: n


    Process returned 0 (0x0)   execution time : 124.085 s
    Press any key to continue.


*/

// Import standard input/output library



// Function prototypes go here



// Main function goes here
// Main, libraries and prototypes: 5 points



/*

Problem 1: 10 points

A resistor is a circuit device designed to have a specific resistance value
between its ends. Resistance values are expressed in ohms or kilo-ohms.
Resistors are frequently marked with colored bands that encode their
resistance values, as shown below. The first two bands are digits, and the
third is a power-of-ten multiplier.

The table below shows the meanings of each band color. For example, if the
first band is green, the second is black, and the third is yellow, the resistor has a
value of 50 x 10^4 or 500k.  The 50 is 10 x green(index 5) + black(index 0)).  The
10^4 is 10^yellow(index 4).  The information in the table can be stored in a C program
as an array of strings.

    char COLOR_CODES[10][7] = {"black", "brown", "red",
    "orange", "yellow", "green", "blue", "violet", "gray",
    "white"};

Notice that "red" is COLOR_CODES[2] and has a digit value of 2 and a multiplier
value of 10 2 . In general, COLOR_CODES[ n ] has digit value n and multiplier value 10 n .
Write a function that accepts the colors of Band 1, Band 2, and Band 3,
and then returns the resistance in kilo-ohms. Include a helper function search
that takes three parameters--the list of strings, the size of the list, and a target
string, and returns the subscript of the list element that matches the target or
returns -1 if the target is not in the list.

Color Codes for Resistors*
    Color Value     Digit Value     Multiplier
    Black           0               10^0
    Brown           1               10^1
    Red             2               10^2
    Orange          3               10^3
    Yellow          4               10^4
    Green           5               10^5
    Blue            6               10^6
    Violet          7               10^7
    Gray            8               10^8
    White           9               10^9

    FORMULA:
    resistance = (digit0 * 10 + digit1) * (10^multiplier); 

*Adapted from Sears and Zemansky�s University Physics , 10th edited by Hugh D. Young and Roger A.
Freedman (Boston: Addison-Wesley, 2000), p. 807.

*/

// resistor function goes here



// search function goes here



/*

Problem 2: 5 points

Write a function that takes nouns and forms their plurals on the basis of
these rules:

    a. If noun ends in "y", remove the "y" and add "ies".
    b. If noun ends in "s", "ch", or "sh", add "es".
    c. In all other cases, just add "s".

Print each noun and its plural. Try the following data:
    chair   dairy   boss    circus  fly dog church  clue    dish

*/

// plural function goes here



/*

Problem 3: 5 points

Write and test a function that finds and returns through an output parameter
the longest common suffix of two words (e.g., the longest common suffix of
"procrastination" and "destination" is "stination", of "globally" and "internally"
is "ally", and of "gloves" and "dove" is the empty string).

*/

// suffix function goes here

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>

// DEFINE PROTOTYPES
int get_value(char color[]) ;
void calc_res ();


int get_value (char color[])
{
    // 0      1       2      3         4          5        6       7        8       9
    char *COLOR_CODES[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
    
    int index = -1;
    // find the index, for loop, strcmp
    for (int i=0; i < 10; i++) {
        //printf("Color = %s :: Color_Code[] = %s \n", color, COLOR_CODES[i]);
        if (color == COLOR_CODES[i]) {
            index = i;
            printf("Matched color = %s and index = %d\n", color, i);
            return index;
        }
    }
}

void calc_res ()
{

    // get 3 bands
    char band0[15], band1[15], band2[15];
    char answer;
    printf ("I am starting ..\n");
    answer = 'y';
    
    while(answer == 'y') {
        printf("Band 1 => ");
        scanf ("%s", band0);
        //printf("Band 1 = %s \n", band0);
        
        printf("Band 2 => ");
        scanf ("%s", band1);
        
        printf("Band 3 => ");
        scanf ("%s", band2);
        
        //get value of 3 bands
        int digit0 = get_value(band0);
        int digit1 = get_value(band1);
        int multiplier = get_value(band2);
        
        // int resistance = (digit0 * 10 + digit1) * (10^multiplier); 
        printf("Values of digit0 = %d :: digit 1 = %d :: multiplier = %d", digit0, digit1, multiplier);
        int resistance = (digit0 * 10 + digit1) * pow(10, multiplier);
        // print result
        printf("Resistance value: %d kilo-ohm(s)", resistance);

        printf(" Do you want to decode another resistor: ");
        scanf("%c", &answer);
    }
}

void get_plural(char word[], char plural[])
{
    // given word, fill the plural version of word into plural
    int len = strlen(word);
    //char answer;
    
    // bunny \n
    // bunnies

        if (word[len - 1] == 'y')
        {
            // strcpy(word, plural, len);
            plural[len - 1] = 'i';
            plural[len]     = 'e';
            plural[len + 1] = 's';
            plural[len + 2] = '\n';
        }
        else if (word[len - 1] == 's' ||
            (word[len - 2] == 'c' && word[len - 1] == 'h') ||
            (word[len - 2] == 's' && word[len - 1] == 'h'))
        {  
            strcat(plural, "es");
        }
        else
        {   
            strcat(plural, "s");
        }

        printf("New word is: ", plural); 
        // printf("%s", plural);

        // printf("Do you want to convert another string: ");
        // scanf("%s", &answer);
}

void get_common_suffix(char word0[], char word1[], char suffix[])
{
    // given word0 and word1, find the longest common suffix
    // and store the result into suffix
    int index = 0;
    int len = strlen(word0);
    char answer = 'y';
    // global
    // gloves
    // index = 3 
    while (answer == 'y') {
        for (int i = 0; i < len; i++)
        {
            if (word0[i] == word1[i]) {
                suffix += word0[i];
                continue;
            }
            else
            {
                index = i;
                break;
            }
        }
        printf("The suffix of %s and %s is %s", word0, word1, suffix);

        printf("Do you want to find another suffix: ");
        scanf("%c", &answer);
    }
}

int main()
{
    char word[20] = "bunny";
    

    return 0;
}





