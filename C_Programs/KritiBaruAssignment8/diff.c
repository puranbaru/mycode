#include <stdio.h>
#include "string.h"

// returns the number of positions in which s1 and s2 differ, i.e., it returns the number of changes that would need to
// be made in order to transform s1 into s2, where a change could be a character substitution, an insertion, or a
// deletion.

int diff(char *s1, char *s2){
    int count = 0;
    while (*s1 || *s2) {
        if (*s1 != *s2) {
            count++;
        }
        s1++;
        s2++;
    }
    return count;
}