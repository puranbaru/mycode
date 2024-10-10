#include <stdio.h>
#include "string.h"

// returns 1 if suff is a suffix of s ignoring case or 0 otherwise.

int ends_with_ignore_case(char *s, char *suff){
    if (s == NULL || suff == NULL) {
        return 0;
    }
    int len_s = strlen(s);
    int len_suff = strlen(suff);
    if (len_s < len_suff) {
        return 0;
    }
    return strcasecmp(s + len_s - len_suff, suff) == 0;
}