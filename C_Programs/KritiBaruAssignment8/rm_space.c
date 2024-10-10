#include <stdio.h>
#include "string.h"

// removes whitespace characters from the beginning and the ending s

void rm_space(char *s){
    rm_left_space(s);
    rm_right_space(s);
}