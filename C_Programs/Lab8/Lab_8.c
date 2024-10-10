#include <stdio.h>
#include <math.h>
#include <string.h>

// Initialize Prototypes
int get_value(char color[]);
void calc_res();
void get_plural(char word[], char plural[]);
//void get_common_suffix(char *word0, char *word1);

// get_value function
int get_value(char color[])
{
    // 0      1       2      3         4          5        6       7        8       9
    char *COLOR_CODES[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};

    int index = -1;
    // find the index, for loop, strcmp
    for (int i = 0; i < 10; i++)
    {
        // printf("Color = %s :: Color_Code[] = %s \n", color, COLOR_CODES[i]);
        if (color == COLOR_CODES[i])
        {
            index = i;
            printf("Matched color = %s and index = %d\n", color, i);
            return index;
        }
    }
    return 0;
}

// calc_res function
void calc_res()
{
    // get 3 bands
    char band0[15], band1[15], band2[15];

    printf("Band 1 => ");
    scanf("%s", band0);
    // printf("Band 1 = %s \n", band0);

    printf("Band 2 => ");
    scanf("%s", band1);

    printf("Band 3 => ");
    scanf("%s", band2);

    // get value of 3 bands
    int digit0 = get_value(band0);
    int digit1 = get_value(band1);
    int multiplier = get_value(band2);

    // int resistance = (digit0 * 10 + digit1) * (10^multiplier);
    // printf("Values of digit0 = %d :: digit 1 = %d :: multiplier = %d", digit0, digit1, multiplier);
    int resistance = (digit0 * 10 + digit1) * pow(10, multiplier);
    // print result
    printf("Resistance value: %d kilo-ohm(s) \n", resistance);
}

// get_pluralfunction
void get_plural(char word[], char plural[])
{
    // given word, fill the plural version of word into plural
    int len = strlen(word);

    if (word[len - 1] == 'y')
    {
        // strcpy(word, plural, len);
        plural[len - 1] = 'i';
        plural[len] = 'e';
        plural[len + 1] = 's';
        plural[len + 2] = '\n';
    }
    else if (word[len - 1] == 's' ||
             (word[len - 2] == 'c' && word[len - 1] == 'h') ||
             (word[len - 2] == 's' && word[len - 1] == 'h'))
    {
        strcat(plural, "es\n");
    }
    else
    {
        strcat(plural, "s\n");
    }

    printf("New word is: %s", plural);
}

// //get_common_suffix function
// void get_common_suffix_old(char word0[], char word1[], char suffix[])
// {
//     // given word0 and word1, find the longest common suffix
//     // and store the result into suffix
//     int start_ind = 0;
//     int end_ind = 0;
//     int len1 = strlen(word0);
//     int len2 = strlen(word1);
//     // global
//     // gloves
//     // index = 3

//     printf("The suffix of %s and %s is ",word0, word1);
//     for (int j = 0; j < len2; j++)
//     {                                  // Word1 parsing
//         for (int i = 0; i < len1; i++) // Word2 parsing
//         {
//             // printf("Suffix = %s :: word0 = %c :: word1 = %c \n", suffix, word0[i], word1[j]);

//             if (strcmp(word0[i], word1[j]) == 0)
//             {
//                 suffix += word0[i];
//                 // printf("Suffix = %s :: word0 = %c :: word1 = %c \n", suffix, word0[i], word1[j]);
//                 continue;
//             }
//             else
//             {
//                 end_ind = i;
//                 break;
//             }
//         }
//     }

//     printf("%s \n", suffix);
// }

// void get_common_suffix(char word0[], char word1[], char suffix[])
// {
//     // given word0 and word1, find the longest common suffix
//     // and store the result into suffix
    
//     int len = strlen(word0);
//     int index = -1;
//     char suf[25];
//     // global
//     // gloves
//     // index = 3 
//     printf("The suffix of %s and %s is ",word0, word1);
//     for (int i = 0; i < len; i++)
//     {
//         if (word0[i] == word1[i]) {
//             strcat(suf, word0[i]);
//             continue;
//         }          
//         else
//         {
//             index = i;
//             break;
//         }
//     }
//     printf("%s \n", suffix);
// }

void get_common_suffix(const char *word0, const char *word1)
{
    int count[256] = {0};
    
    printf ("The suffix of %s and %s is ", word0, word1);
    
    while (*word0) {
        count[*word0]++;
        word0++;
    }
    while (*word1) {
        if (count[*word1] > 0) {
            printf("%c", *word1);
        }
        word1++;
    }
    printf("\n");
}

int main()
{
    char ans[10] = "y";
    char word[20] = "bush";
    char first[25], second[25];
    // calc_res();

    while (strcmp(ans, "y") == 0)
    {

        // Problem 1
        // calc_res();

        // Problem 2
        // printf("Enter a string: ");
        // scanf("%s", word);
        // get_plural(word, word);

        // //Problem 3
        // Enter first string: procrastination
        // Enter second string: destination
        // The suffix of procrastination and destination is stination

        printf("Enter first string: ");
        scanf("%s", first);
        printf("Enter second string: ");
        scanf("%s", second);
        get_common_suffix(first, second);

        /////////////////////////////////////////
        // Get the answer
        // printf ("Do you want to decode another resistor: ");
        // printf ("Do you want to convert another string: ");
        printf("Do you want to find another suffix: ");
        scanf("%s", ans);
        /////////////////////////////////////////
    }

    return 0;
}
