#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lab2.h"

int convert_to_hex(char* s){
    int decimal = 0;
    int p = 0;
    for(int i=strlen(s)-1;i>=0;--i){
        switch(*(s+i)){
            case 'A':
            case 'a':
                decimal = decimal + (10 * pow(16, p));
                break;
            case 'B':
            case 'b':
                decimal = decimal + (11 * pow(16, p));
                break;
            case 'C':
            case 'c':
                decimal = decimal + (12 * pow(16, p));
                break;
            case 'D':
            case 'd':
                decimal = decimal + (13 * pow(16, p));
                break;
            case 'E':
            case 'e':
                decimal = decimal + (14 * pow(16, p));
                break;
            case 'F':
            case 'f':
                decimal = decimal + (15 * pow(16, p));
                break;
            default:
                decimal = decimal + ((*(s+i)-48) * pow(16, p));
                break;
        }
        ++p;
    }
    return decimal;
}

char* remove_substring(char* s){
    int count = 0;
    int index = 0;
    char* result = malloc(strlen(s));
    char* delimiter = "&&|";
    char* f;
    
    f = strstr(s, delimiter);

    for(int i=0;i<strlen(s);i++){
        if(&(*f) == &(*(s+i)) && count < strlen(delimiter)){
            f = f+1;
            count = count + 1;
        }
        else{
            *(result+index) = *(s+i);
            index = index + 1;
        }
    }
    return result;
}

