#include <stdio.h>
#include <ctype.h>
#include "string.h"

// Function prototype
// int all_letters(const char *str);
// void shorten(char *s, int new_len);

int main() {
    // Test cases
    char str1[] = "Hello World";
    char str2[] = "Hello World";
    
    // Shorten to length 5
    shorten(str1, 5);
    printf("Test 1: After shortening to length 5: '%s'\n", str1); // Expected: "Hello"
    
    // Attempt to shorten to length 20 (should do nothing)
    shorten(str2, 20);
    printf("Test 2: After attempting to shorten to length 20: '%s'\n", str2); // Expected: "Hello World"
    
    return 0;
}
// int main(void) {
//     // My Test cases
//     // const char *test1 = "HelloWorld"; // All alphabetic, should return 1
//     // const char *test2 = "He11oWorld"; // Contains numbers, should return 0
//     // const char *test3 = "Hello World"; // Contains a space, should return 0
//     // const char *test4 = "ABCxyz"; // All alphabetic, should return 1

//     // // Testing the function with various inputs
//     // printf("Test 1: '%s' - Result: %d\n", test1, all_letters(test1));
//     // printf("Test 2: '%s' - Result: %d\n", test2, all_letters(test2));
//     // printf("Test 3: '%s' - Result: %d\n", test3, all_letters(test3));
//     // printf("Test 4: '%s' - Result: %d\n", test4, all_letters(test4));

//     // return 0;


// // Test case Example. Needs cleanup


//     // puts ("Test for all_letters ··");
//     // char *s = "hello";
//     // char *sl: "sir'';
//     // int all_letters_ - all_letters(s);
//     // if (all_letters_) {
//     //     printf("String:%s\n", s);
//     //     puts("All characters in string were letters\n");
//     // }else {
//     //     puts("All characters in string were not letters\n");
//     //     }


//     // puts("Test for num_in_range");
//     // int num_in_range_ - num_in_range(s, a, "h");
//     // printf( "The String:%s\n"', s);
//     // printf("The range %c-%c", 'a', 'h' );
//     // printf("%s %d %s\n\n", "There are", num_in_range_, "letters in the range");
//     // puts("Test for diff");
//     // int diff_ - diff(s, s1);
//     // printf("The Strings: %s, %s\n", s, s1);
//     // printf("%s %d %s\n\n", "The strings differ in", diff_, "'4ays");
    
//     // puts( "Test for shorten");
//     // puts("Before:");
//     // printf("%s\n", s);
//     // puts("After: ");
//     // char word(] - "hello";
//     // shorten(word, 3);
//     // printf("%s\n\n", '4ord);
//     // puts("Test for len_diff");
//     // int len_diff_ = len_diff(s, s1);
//     // printf("The Strings: %s, %s\n", s, sl);
// }
