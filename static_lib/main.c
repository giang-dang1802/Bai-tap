#include <stdio.h>
#include <string.h>
#include "strutils.h" // include file .h

int main() {
    char str1[100] = " Hello World ";
    char str2[100] = "Embedded Linux";
    char numStr[100] = "12345";

    printf("Original str1: '%s'\n", str1);
    str_trim(str1);
    printf("Trimmed: '%s'\n", str1);

    printf("\nOriginal str2: '%s'\n", str2);
    str_reverse(str2);
    printf("After reverse: '%s'\n", str2);

    int number = str_to_int(numStr);
    printf("\nConverted '%s' to integer: %d\n", numStr, number);

    return 0;
}
