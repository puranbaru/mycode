#include <stdio.h>
#include "string.h"

// Returns an array of string consisting of the characters in s split into tokens based on the dimeter c, followed by
// a NULL pointer. For example, if s is "I am ready for a nice vacation" and c is '', it returns {"I", "am", "ready",
// "for", "a", "nice", "vacation", NULL}

char **str_chop_all(char *s, char c){
    if (s == NULL) {
        return NULL;
    }
    int len = strlen(s);
    int num_tokens = 1; // At least one token
    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            num_tokens++;
        }
    }
    char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
    if (tokens == NULL) {
        return NULL; // Memory allocation failed
}