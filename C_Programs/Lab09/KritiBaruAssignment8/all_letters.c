#include <stdio.h>

// Function to determine if a character is an alphabetic letter
int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Function to check if all characters in a string are alphabetic
int all_letters(const char *str) {
    int i = 0;
    while (str[i] != '\0') { // Loop through the string until the null terminator
        if (!is_letter(str[i])) {
            return 0; // Found a non-alphabetic character, return 0
        }
        i++; // Move to the next character
    }
    return 1; // All characters are alphabetic, return 1
}