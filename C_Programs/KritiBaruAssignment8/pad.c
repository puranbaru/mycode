#include <stdio.h>
#include "string.h"

// returns a new string consisting of all of the letters of s, but padded with spaces at the end so that the total length
// of the returned string is an even multiple of d. If the length of s is already an even multiple of d, the function
// returns a copy of s. The function returns NULL on failure or if s is NULL. Otherwise, it returns the new string. It is
// up to the caller to free any memory allocated by the function

char *pad(char *s, int d) {
    if (s == NULL) {
        return NULL;
    }
    int len = strlen(s);
    int pad_len = len + (d - (len % d)); // Calculate padded length
    char *result = (char *)malloc((pad_len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
    strcpy(result, s);
    for (int i = len; i < pad_len; i++) {
        result[i] = ' ';
    }
    result[pad_len] = '\0'; // Null-terminate the string
    return result;
}