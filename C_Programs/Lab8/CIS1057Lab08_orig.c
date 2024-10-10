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

*Adapted from Sears and Zemansky’s University Physics , 10th edited by Hugh D. Young and Roger A.
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




