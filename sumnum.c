#include <stdio.h>

typedef enum {false, true} bool;

int main(){

    int x, y, sum;
    float f;
    double d;

    printf("Enter 2 numbers:\n");
    scanf("%d", &x);
    scanf("%d", &y);

    sum = x + y;

    printf("The sum of %d and %d is %d\n", x,y,sum);

    return 0;
}