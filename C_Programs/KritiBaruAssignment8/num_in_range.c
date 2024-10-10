#include <stdio.h>
#include "string.h"

// returns the number of characters c in s1 such that b<=c<=t
int num_in_range(char *s1, char b, char t){
    int count = 0;
    while (*s1) {
        if (*s1 >= b && *s1 <= t) {
            count++;
        }
        s1++;
    }
    return count;
}