#include <stdio.h>
#include "string.h"

// returns a pointer to the first occurrence of n in the string h or NULL if it isn't found

char *ptr_to(char *h, char *n){
    return strstr(h, n);
}