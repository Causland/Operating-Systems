#include <stdio.h>
#include <pthread.h>

int sum = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* runner(void* arg){
    int i = 0;
    int total = 100000000;
    for(i=0;i<total;i++){
        pthread_mutex_lock(&m);
        sum+=1;
        //pthread_mutex_unlock(&m);
    }

}


int main(){
    pthread_t tid;
    pthread_t t2;
    pthread_attr_t attr;

    pthread_mutex_init(&m, NULL);

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, NULL);
    pthread_create(&t2, &attr, runner, NULL);

    pthread_join(tid, NULL);
    pthread_join(t2, NULL);

    printf("Sum = %i", sum);
}