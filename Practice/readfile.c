#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE *fptr;
    char filename[15];
    char file_line[50];

    printf("Enter filename\n");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("file not found\n");
        exit(0);
    }
    
    while(fgets(file_line, 50, fptr) != NULL){
        printf("%s\n", file_line);
    }

    return 0;
}