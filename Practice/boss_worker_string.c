#include "voidQueue.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Queue* queue;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t boss_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t worker_cond = PTHREAD_COND_INITIALIZER;

void* worker(void* arg){
    char* item;
    while(1){
        pthread_mutex_lock(&m);
        while(isEmpty(queue)){
            pthread_cond_wait(&worker_cond, &m);
        }
        item = dequeue(queue);
        pthread_mutex_unlock(&m);
        pthread_cond_signal(&boss_cond);
        printf("dequeued %s\n", item);
    }
}

int main(){

    pthread_t workerThread[10];
    queue = createQueue(5);

    for(int i=0;i<10;i++){
        pthread_create(&workerThread[i],NULL,worker,NULL);
    }

    char* item = malloc(10*sizeof(char));
    strcpy(item, "workdetails");

    while(1){
        pthread_mutex_lock(&m);
        while(isFull(queue)){
            pthread_cond_wait(&boss_cond, &m);
        }
        enqueue(queue,item);
        pthread_mutex_unlock(&m);
        pthread_cond_signal(&worker_cond);
        printf("boss put item in queue\n");
    }
}