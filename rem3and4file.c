#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    
    int count = 0;
    while(fgets(file_line, 50, fptr) != NULL){
        file_line[count] = fptr;
    }

    for(int j=0;j<sizeof(file_line);j++){
        for(int i=3;i<strlen(file_line[j])-4;i++){
            file_line[j][i-3] = file_line[j][i];
        }
    }

    printf("%s\n", result);
}