#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos, int tPos);
int min(int hMin, int tMin);
void printWinner (int hPos, int tPos);

int main(){
    srand((unsigned)time(NULL));

    int hPos = 1; // hare start position is 1, cannot slip past 1
    int tPos = 1; // tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!"); // the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!"); // the spacing is modeled after the sample

    while (hPos <= 70 && tPos <= 70) {
        sleep(1); // slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos, tPos);
        puts("");
    }

    puts("Let us see who won");

    printWinner(hPos, tPos);
}

// Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin) {
    return (hMin < tMin) ? hMin : tMin;
}


// Prints who the winner is
void printWinner(int hPos, int tPos) {
    if (hPos > tPos) {
        printf("HARE WINS");
    }
    else {
        printf("TORTOISE WINS");
    }
}

// Prints the position of the H and T
void printRace(int hPos, int tPos) {
    int i;
    for (i = 1; i <= 70; ++i) {
        if (i == hPos && i == tPos)
            printf("OUCH!!!");
        else if (i == hPos)
            printf("H");
        else if (i == tPos)
            printf("T");
        else
            printf(" ");
    }
    printf("\n");
}

// Controls the tortoise movement
void tortMove(int *tPtr) {
    int move = randomNumberGenerator();
    
    if (move >= 1 && move <= 5) {
        *tPtr += 3; // fast plod
    } else if (move >= 6 && move <= 7) {
        *tPtr -= 6; // slip
    } else {
        *tPtr += 1; // slow plod
    }

    // Ensure the tortoise doesn't slip past square 1
    if (*tPtr < 1)
        *tPtr = 1;
}

// Controls the hare movement
void hareMove(int *hPtr) {
    int move = randomNumberGenerator();
    
    if (move == 1 || move == 2) {
        // Sleep, no move
    } else if (move == 3 || move == 4) {
        *hPtr += 9; // big hop
    } else if (move == 5) {
        *hPtr -= 12; // big slip
    } else if (move >= 6 && move <= 9) {
        *hPtr += 1; // small hop
    } else {
        *hPtr -= 2; // small slip
    }

    // Ensure the hare doesn't slip past square 1
    if (*hPtr < 1)
        *hPtr = 1;
}

// Generates random number from 1-10
int randomNumberGenerator() {
    return rand() % (INT_MAX - INT_MIN + 1) + INT_MIN;
}
