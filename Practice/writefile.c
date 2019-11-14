#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    char filename[15];
    char file_line[50];

    printf("Enter filename\n");
    scanf("%s", filename);
    fptr = fopen(filename, "w");
    if(fptr == NULL){
        printf("error opening file\n");
        exit(0);
    }
    printf("Enter text\n");
    scanf("%s", file_line);
    fprintf(fptr, file_line, strlen(file_line));

}