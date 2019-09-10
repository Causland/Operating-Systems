#include <stdio.h>
#include <math.h>
#include <string.h>
#include "lab2.h"

int main(int argc, char const *argv[])
{
    char* new_string;
    int hex_in_decimal;
   
    char* hex_string1 = "7DE";

    hex_in_decimal = convert_to_hex(hex_string1);
    printf("Decimal coversion expected: %d\n", 2014);
    printf("Decimal coversion actual:   %d\n", hex_in_decimal);

    char* s1 = "This is a string with a &&| delimiter.";
    new_string = remove_substring(s1);
    printf("remove_substring expected: %s\n", "This is a string with a  delimiter.");
    printf("remove_substring actual:   %s\n", new_string);

    return 0;
}