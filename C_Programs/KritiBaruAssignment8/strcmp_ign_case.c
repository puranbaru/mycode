#include <stdio.h>
#include "string.h"

// Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a
// negative number if it would appear before s2, or 0 if the two are equal.

int strcmp_ign_case(char *s1, char *s2){
    while (*s1 && *s2) {
        if (tolower(*s1) != tolower(*s2)) {
            return tolower(*s1) - tolower(*s2);
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}