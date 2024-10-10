#include <stdio.h>
#include "string.h"

// Shortens the string s to new_len. 
// If the original length of s is less than or equal to new_len, s is unchanged

void shorten(char *s, int new_len){
    int len = 0;
    char *temp = s;
    while (*temp) {
        len++;
        temp++;
    }
    if (len <= new_len) {
        return; // No change needed
    }
    s[new_len] = '\0';
}