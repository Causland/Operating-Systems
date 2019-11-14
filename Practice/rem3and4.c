#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    printf("Enter a string with no spaces\n");
    char input[50];
    scanf("%s", input);

    char* result = malloc(sizeof(input));
    for(int i=3;i<strlen(input)-4;i++){
        *(result+i-3) = input[i];
    }

    printf("%s\n", result);
}