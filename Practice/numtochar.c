#include <stdio.h>

void numtochar(int* nums, char* alphabet){
    for(int i=65;i<91;i++){
        nums[i-65] = i;
        alphabet[i-65] = i;
        printf("Number %i : Char %c\n", nums[i-65], alphabet[i-65]);
    }
}

int main(){
    int nums[91-65];
    char alphabet[91-65];
    numtochar(nums, alphabet);
}