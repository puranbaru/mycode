#include <stdio.h>
#include "string.h"

/*Returns a copy of the string s, but with each instance of pat replaced with rep, note that len(pat) can be less
than, greater than, or equal to len(rep). The function allocates memory for the resulting string, and it is up to
the caller to free it. For example, if we call replace("NBA X", "X", "rocks"), what is returned is the new
string NBA rocks (but remember, pat could be longer than an individual character and could occur multiple
times*/

char *replace(char *s, char *pat, char *rep){
    if (s == NULL || pat == NULL || rep == NULL) {
        return NULL;
    }
    int len_s = strlen(s);
    int len_pat = strlen(pat);
    int len_rep = strlen(rep);
    char *result = (char *)malloc((len_s + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }
    int i = 0, j = 0;
    while (s[i]) {
        if (strstr(&s[i], pat) == &s[i]) {
            strcpy(&result[j], rep);
            j += len_rep;
            i += len_pat;
        } else {
            result[j++] = s[i++];
        }
    }
    result[j] = '\0'; // Null-terminate the string
    return result;
}