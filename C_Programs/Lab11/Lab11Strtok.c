
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int extract_by_strtok()
{
    // suppose you already got this line from a file
    char buffer[100] = "123 456 789";

    // then we use strtok to extract integers from it

    // firstly, call strtok to get the first token
    // tokens are the strings seperated by the second argument of 'strtok'
    // for example, for the following line, in buffer ("123 456 789"), separated by " " (a space)
    // there are 3 tokens, "123", "456", "789"
    char* tk = strtok(buffer, " ");  

    // now tk is the first token
    while(tk != NULL)
    {
        // convert tk to an integer
        int num = atoi(tk);
        // print the result
        printf("%d ", num);

        // get the next token
        // be aware that this time we do not pass buffer to strtok, but keep passing " " (the delim)
        tk = strtok(NULL, " "); // do not update the first argument, we are still on buffer
    }
    printf("\n");
    // here all tokens in the buffer is processed


    // if you need to use strtok to tokenize a new string (buffer2 in this case), separated by "-"
    char buffer2[] = "111 222 333";
    // get "111"
    tk = strtok(buffer2, " "); // remember to update the first argument to buffer2 for the first time tokenizing buffer2
    printf("%s ", tk);
    // get "222"
    tk = strtok(NULL, " "); // do not update the first argument, we are still on buffer2
    printf("%s ", tk);
    // get "333"
    tk = strtok(NULL, " "); // do not update
    printf("%s", tk);
    printf("\n");
}


int main()
{
    // example to use strtok
    // remember to #include <string.h>
    extract_by_strtok();

    /*
    you will see the following 2 lines:
    123 456 789
    111 222 444
    */

    return 0;
}