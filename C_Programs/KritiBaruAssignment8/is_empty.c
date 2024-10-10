#include <stdio.h>
#include "string.h"

// returns 1 if s is NULL, consists of only the null character ('') or only whitespace. returns 0 otherwise

int is_empty(char *s){
    if (s == NULL) {
        return 1;
    }
    while (*s) {
        if (!isspace(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}