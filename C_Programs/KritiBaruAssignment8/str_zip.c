#include <stdio.h>
#include "string.h"

// Returns a new string consisting of all of the characters of s1 and s2 interleaved with each other. For example, if
// s1 is "Spongebob" and s2 is "Patrick", the function returns the string "SPpaotnrgiecbkob"

char str_zip(char *s1, char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        result[k++] = s1[i++];
        result[k++] = s2[j++];
    }
    while (i < len1) {
        result[k++] = s1[i++];
    }
    while (j < len2) {
        result[k++] = s2[j++];
    }
    result[k] = '\0'; // Null-terminate the string
    return result;
}