#include <stdio.h>
#include "string.h"

// removes whitespace characters from the beginning of s
void rm_left_space(char *s){
    while (*s == ' ' || *s == '\t' || *s == '\n') {
        s++;
    }
}