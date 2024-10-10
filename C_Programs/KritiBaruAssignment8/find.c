#include <stdio.h>
#include "string.h"

// returns the index of the first occurrence of n in the string h or -1 if it isn't found

int find(char *h, char *n){
    char *ptr = strstr(h, n);
    if (ptr != NULL) {
        return ptr - h;
    }
    return -1;
}