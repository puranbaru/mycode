#include <stdio.h>
#include "string.h"

// Changes s so that the first letter of every word is in upper case and each additional letter is in lower case

void capitalize(char *s){
    int capitalize_next = 1;
    while (*s) {
        if (isalpha(*s)) {
            if (capitalize_next) {
                *s = toupper(*s);
                capitalize_next = 0;
            } else {
                *s = tolower(*s);
            }
        } else {
            capitalize_next = 1;
        }
        s++;
    }
}