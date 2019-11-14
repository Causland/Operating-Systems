#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    double sum1 = 0;
    double sum2 = 0;
    if(fork()==0){
        for(double i=0;i<123456789012345678901234567890;i++){
            sum1++;
        }
    }
    else{
        for(double i=0;i<123456789012345678901234567890;i++){
            sum2++;
        }
    }

    return 0;

}