#include <stdio.h>

int main(){

    int age;

    printf("Please enter your age\n");
    scanf("%d", &age);
    if(age < 18){
        printf("You can't vote yet\n");
    }
    else{
        printf("You can vote!");
    }

    return 0;
}