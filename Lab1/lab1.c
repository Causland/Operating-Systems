//Chris Auslander
//Lab 1

#include <stdio.h>

int min(int n1, int n2, int n3, int n4, int n5){
    int min = n1;
    if(n2 < min){
        min = n2;
    }
    if(n3 < min){
        min = n3;
    }
    if(n4 < min){
        min = n4;
    }
    if(n5 < min){
        min = n5;
    }
    return min;
}

int max(int n1, int n2, int n3, int n4, int n5){
    int max = n1;
    if(n2 > max){
        max = n2;
    }
    if(n3 > max){
        max = n3;
    }
    if(n4 > max){
        max = n4;
    }
    if(n5 > max){
        max = n5;
    }
    return max;
}

float avg(int n1, int n2, int n3, int n4, int n5){
    int sum = n1+n2+n3+n4+n5;
    float avg = sum/5.0;
    return avg;
}

int search(int n1, int n2, int n3, int n4, int n5){
    if(n1 == 5){
        return 1;
    }
    else if(n2 == 5){
        return 1;
    }
    else if(n3 == 5){
        return 1;
    }
    else if(n4 == 5){
        return 1;
    }
    else if(n5 == 5){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n1, n2, n3, n4, n5;

    printf("Please enter 5 numbers:\n");

    scanf("%d\n %d\n %d\n %d\n %d", &n1, &n2, &n3, &n4, &n5);

    printf("The min is %d\nThe max is %d\nThe average is %.2f\n", 
            min(n1,n2,n3,n4,n5), max(n1,n2,n3,n4,n5), avg(n1,n2,n3,n4,n5));

    if(search(n1,n2,n3,n4,n5)){
        printf("You entered a 5\n");
    }
    else{
        printf("No 5 entered\n");
    }

    return 0;
}