/**
 * COMP9024 Assignment 2: Ordered Word Ladders version 2 
 * (using string.h)
 * 
 * @author Wenke Yang
 * @email z5230655@student.unsw.edu.au
 * @create date 2019-07-15 22:18:34
 * @description 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FIRST_STR_SHORTER_CODE 2
#define SECOND_STR_SHORTER_CODE 3

#define INPUT_STR_SIZE 100

/**
 * Input: two null-terminated strings
 * Returns: bool
 * 
 * Check if the two strings satisfy one of the 2 conditions below:
 * 1. changing one letter, e.g. barn→born
 * 2. adding or removing one letter, e.g. band→brand and bran→ran
 * 
*/
bool differByOne(char *, char *);

/**
 * Input: two null-terminated strings with same length
 * Returns: bool
 * 
 * Check if one str changes one letter can become another 
*/
bool changeOne(char *, char *);

/**
 * Input: two null-terminated strings, str1 and str2
 *        str1 is shorter than str2 by 1.
 * Returns: bool 
 * 
 * Check if str1 can transform to str2 by adding one letter
*/
bool addOrRemoveOne(char *, char *);


int main(void) {
    char str1[INPUT_STR_SIZE];
    char str2[INPUT_STR_SIZE];
    printf("Enter the first string:\n");
    scanf("%s", str1);
    printf("%s\n", str1);

    printf("Enter the second string:\n");
    scanf("%s", str2);
    printf("%s\n", str2);

    if (differByOne(str1, str2)) {
        printf("True. Two strings are different by one!\n");
    } else {
        printf("False. Two strings are not differ by one!\n");
    }
    return EXIT_SUCCESS;
}

bool differByOne(char * str1, char * str2) {
    bool isdifferbyOne = false;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int lenDiff = len1 - len2;

    switch (lenDiff) {
        case 0:
            // same length
            isdifferbyOne = changeOne(str1, str2);
            break;
        case 1:
            // diff in length == 1, str2 is shorter
            isdifferbyOne = addOrRemoveOne(str2, str1);
            break;
        case -1:
            // diff in length == 1, str1 is shorter
            isdifferbyOne = addOrRemoveOne(str1, str2);
            break;
        default:
            // diff in length > 1
            break;
    }

    return isdifferbyOne;
}

bool changeOne(char * str1, char * str2) {
    int i = 0;
    char c1 = *str1;
    char c2 = *str2;
    int diff = 0;

    while (c1 != '\0' && diff <= 1) {
        if (c1 != c2) {
            diff++;
        }

        i++;
        c1 = *(str1+i);
        c2 = *(str2+i);
    }

    bool changeOneResult = false;
    if (diff == 1) {
        changeOneResult = true;
    }
    return changeOneResult;
}

bool addOrRemoveOne(char * str1, char * str2) {
    int i1 = 0;
    int i2 = 0;
    char c1 = *str1;
    char c2 = *str2;
    int diff = 0;

    while (c1 != '\0' && diff <= 1) {
        if (c1 == c2) {
            i1++;
        } else {
            diff++;
        }
        i2++;
        c1 = *(str1+i1);
        c2 = *(str2+i2);
    }

    bool addOne = false;
    if (diff <= 1) {
        addOne = true;
    }
    return addOne;
}