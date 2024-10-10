#include <stdio.h>
#include "string.h"

// returns a new string based on s, but without any duplicate characters. For example, if s is the string, "There's
// always money in the banana stand.", the function returns the string "Ther's alwymonitbd.". It is up
// to the caller to free the memory allocated by the function

char dedup(char *s){
    int len = strlen(s);
    char *result = (char *)malloc((len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
    int hash[256] = {0}; // Hash table to store character occurrences
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (!hash[(unsigned char)s[i]]) {
            result[index++] = s[i];
            hash[(unsigned char)s[i]] = 1;
        }
    }
    result[index] = '\0'; // Null-terminate the string
    return result;
}