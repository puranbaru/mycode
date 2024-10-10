#include <stdio.h>
#include "string.h"

// Returns a new string consisting of the characters in s repeated x times, with the character sep in between. For
// example, if s is the string all right, x is 3, and sep is , the function returns the new string all right,all
// right,all right. If s is NULL, the function returns NULL. It is up to the caller to free any memory allocated by
// the function.

char *repeat(char *s, int x, char sep){
    if (s == NULL) {
        return NULL;
    }
    int len_s = strlen(s);
    int result_len = (len_s + 1) * x - 1; // Length of repeated string
    char *result = (char *)malloc((result_len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
    int k = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < len_s; j++) {
            result[k++] = s[j];
        }
        if (i != x - 1) {
            result[k++] = sep;
        }
    }
    result[result_len] = '\0'; // Null-terminate the string
    return result;
}
