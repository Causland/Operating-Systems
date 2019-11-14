#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int sum;

void* runner(void* arg){
    int i;
    for(i=0;i<5;i++){
        sum+=1;
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);
}