#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* t1_hello(void* arg){
    int i;
    for(i=0;i<5;i++){
        printf("hello from thread 1\n");
    }
}

void* t2_hello(void* arg){
    int i;
    for(i=0;i<5;i++){
        printf("hello from thread 2\n");
    }
}

int main(int argc, char const *argv[]){
    pthread_t t1;
    pthread_t t2;

    if(pthread_create(&t1, NULL, t1_hello, NULL) < 0){
        printf("error creating thread 1\n");
    }

    if(pthread_create(&t2, NULL, t2_hello, NULL) < 0){
        printf("error creating thread 1\n");
    }

    pthread_cancel(t2);

    void* result;
    if(pthread_join(t2, result) < 0){
        printf("error joining threads\n");
    }

    if(pthread_join(t1, result) < 0){
        printf("error joining threads\n");
    }

    return 0;
}