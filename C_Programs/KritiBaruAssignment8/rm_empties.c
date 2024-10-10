#include <stdio.h>
#include "string.h"

// words is an array of string terminated with a NULL pointer. The function removes any empty strings (i.e., strings
// of length 0) from the array

void rm_empties(char **words){
     if (words == NULL) {
        return;
    }
    int i = 0;
    while (words[i] != NULL) {
        if (strlen(words[i]) == 0) {
            for (int j = i; words[j]; j++) {
                words[j] = words[j + 1];
            }
        } else {
            i++;
        }
    }
}