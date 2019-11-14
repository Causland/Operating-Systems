#include <stdio.h>
#include <stdlib.h>

int main(){

    int* arr = malloc(sizeof(int)*20);
    for(int i=0;i<20;i++){
        *(arr+i) = i;
    }

    for(int i=0;i<30;i++){
        printf("%i\n", *(arr+i));
    }

    return 0;
}