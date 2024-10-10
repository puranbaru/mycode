/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main (Problem 2 should print the results for the substance to
    screen.  See below.).  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.


    1. Write a function that determines the day number (1 to 366) in a year for a
    date that is provided as input data. 
    
    As an example, January 1, 1994, is day 1.
    December 31, 1993, is day 365. December 31, 1996, is day 366, since 1996 is
    a leap year. A year is a leap year if it is divisible by four, except that any year
    divisible by 100 is a leap year only if it is divisible by 400. Your function should
    accept the month, day, and year as integers from main as arguments. 
    
    Include an additional function leap that returns 1 if called with a leap year, 0 otherwise.
    
    Sample screen output:

        CALCULATE DAY OF YEAR
        Enter a date: 12 31 2004
        12/31/2004 is the 366th day of 2004

    Note that a leap year is a year that is (divisible by 4 but not by 100) or (divisible
    by 400).  1900 was not a leap year because it's divisible by 4 but is also divisible
    by 100.  2000 was a leap year because it's divisible by 400.  1904 was a leap year
    because it's divisible by 4 but not divisible by 100.

    2. The table below shows the normal boiling points of several substances. Write
    a function that accepts an argument [the observed boiling point of a substance
    in degrees Celsius] and identifies the substance if the observed boiling point
    is within 5% of the expected boiling point. If the data input is more than 5%
    higher or lower than any of the boiling points in the table, the function should
    output the message Substance unknown.  Note that the {function} should print the
    substance and not {main}.  This will simplify the function call in main.  You need
    to test each substance in an else if chain for the temperature passed from main.

        Substance   Normal boiling point (Celsius)
        Water       100
        Mercury     357
        Copper      1187
        Silver      2193
        Gold        2660

    Your function should define and call a function within_x_percent that takes
    as parameters a reference value ref , a data value data , and a percentage value
    x and returns 1 meaning true if data is within x % of ref -that is, (ref - x%
    * ref) <= data <= (ref + x % * ref) . Otherwise within_x_percent would
    return zero, meaning false. For example, the call within_x_percent(357,
    323, 10) would return true, since 10% of 357 is 35.7, and 323 falls between
    321.3 and 392.7. Sample screen output:

        FIND SUBSTANCE FOR BOILING POINT
        Enter a temperature: 360
        The substance is Mercury

*/

// Preprocessor directives
#include <stdio.h>


// Function prototypes
int is_leap_year(int year);
int calc_days(int month, int date, int year);

int get_material(double bp, double range);
int within_x_percent(double bps, double bp, double range);

// Main function

int main()
{
    int month, date, year;
    printf("Enter the date: ");
    scanf("%d %d %d", &month, &date, &year);
    int days = calc_days(month, date, year);
    printf("%d/%d/%d is day %d of %d", month, date, year, days, year);
    
    
    double bp, bp2, range;
    printf("Enter the boiling point of liquid: ");
    scanf("%lf", &bp);
    

    //within_x_percent(bp,  bp2,  range);

    char* names[] = {"water", "mercury", "copper", "silver", "gold"};
    int index = get_material(bp, 0.1); // 0.1 refers to 10%
    if (index != -1)
        printf("It is %s.", names[index]);
    else
        printf("Unknown material.");
    
    return 0;
}



// Function for Coding Problem 1

int calc_days(int month, int date, int year)
{
    int days;
    
     //amount of days in each month
     int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
    //accumulation of days in order of month 
    int days_to_month[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    
    //month = 3, days_to_month[Feb], days_to_month[1], days_to_month[month-2]
    days = days_to_month[month - 2];
    days += date;
    
    if( is_leap_year(year) && month >= 3)
        days += 1;
    
    return days;
}

// leap function
int is_leap_year(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    
    else 
        return 0;
}

// Function for Coding Problem 2
int get_material(double bp, double range)
{
    double bps[] = {100, 357, 1187, 2193, 2660};
    
   if (within_x_percent(bps[0],bp,range))
    // 90 <= bp && bp <= 110
        {
            return 0;
        }
    
    if (within_x_percent(bps[1],bp,range))
    // 357 - 35.7 <= bp && bp <= 357 +35.7
        {
            return 1;
        }
        
    if (within_x_percent(bps[2],bp,range))
    // 1187 - 11.87 <= bp && bp <= 1187 + 11.87
        {
            return 2;
        }
    if (within_x_percent(bps[3],bp,range))
        { 
            return 3;
        }
    
    if (within_x_percent(bps[4],bp,range))
        {
            return 4;
        }
    
    if (within_x_percent(bps[5],bp,range))
        {
            return 5;
        }
    
    
    return -1;
    
}

// within_x_percent function
// Function within_x_percent(bp,  bp2,  range)
int within_x_percent(bps,  bp,  range)
{
    if (bps * (1-range) <= bp && bp <= bps*(1+range))
    // 90 <= bp && bp <= 110
        {
            return 1;
        }
    else
        {
            return 0;
        }
}


