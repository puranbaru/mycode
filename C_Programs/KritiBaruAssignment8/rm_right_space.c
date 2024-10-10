#include <stdio.h>
#include "string.h"

// removes whitespace characters from the end of s

void rm_right_space(char *s){
    char *end = s;
    while (*end) {
        end++;
    }
    end--;
    while (end >= s && (*end == ' ' || *end == '\t' || *end == '\n')) {
        *end = '\0';
        end--;
    }
}