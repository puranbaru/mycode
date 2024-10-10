#include <stdio.h>
#include "string.h"

// Modifies s so that it consists of only its last n characters. If n is ≥ the length of s, the original string is unmodified.
// For example if we call take_last("Brubeck" 5), when the function finishes, the original string becomes "ubeck"

void take_last(char *s, int n){
    int len = strlen(s);
        if (n >= len) {
            return; // no modification needed
        }
        memmove(s, s + len - n, n + 1); // +1 to copy the null terminator
}