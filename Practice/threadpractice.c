#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int global_array[5];

void* populate_array(void* arg){
    for(int i=0;i<5;i++){
        global_array[i] = i;
    }
}

int main(){

    pthread_t t1;
    



}