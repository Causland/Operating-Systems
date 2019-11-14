#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int counter=0;
int array[BUFFER_SIZE];

void* producer(void* arg){
    int item = 1;
    int in=0;
    while(1){
        while(counter==BUFFER_SIZE);
        array[in] = item;
        printf("Produced Item %i\n", item);
        in = (in + 1) % BUFFER_SIZE;
        counter++;
        item++;
    }
}

void* consumer(void* arg){
    int item = 1;
    int out=0;
    while(1){
        while(counter==0);
        item = array[out];
        printf("Consumed Item %i\n", item);
        out = (out + 1) % BUFFER_SIZE;
        counter--;
    }
}

int main(){
    pthread_t prod;
    pthread_t cons;

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}