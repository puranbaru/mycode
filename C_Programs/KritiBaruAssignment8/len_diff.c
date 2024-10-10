#include <stdio.h>
#include "string.h"

// Returns the length of s1 - the length of s2

int len_diff(char *s1, char *s2){
    int len_s1 = 0, len_s2 = 0;
    char *temp1 = s1, *temp2 = s2;
    while (*temp1) {
        len_s1++;
        temp1++;
    }
    while (*temp2) {
        len_s2++;
        temp2++;
    }
    return len_s1 - len_s2;
}