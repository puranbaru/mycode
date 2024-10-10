#include <stdio.h>
#include "string.h"

// Returns a string consisting of the first n strings in strs with the character c used as a separator.
// For example, if strs contains the strings {"Washington", "Adams", "Jefferson"}
// and c is '+', the function returns the string
// "Washington+Adams+Jefferson"

char *str_connect(char **strs, int n, char c){
    if (strs == NULL || n <= 0) {
        return NULL;
    }
    int total_len = 0;
    for (int i = 0; i < n; i++) {
        total_len += strlen(strs[i]);
    }
    total_len += n - 1; // For separator characters
    char *result = (char *)malloc((total_len + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        int len = strlen(strs[i]);
        strcpy(&result[k], strs[i]);
        k += len;
        if (i != n - 1) {
            result[k++] = c;
        }
    }
    result[total_len] = '\0'; // Null-terminate the string
    return result;

}