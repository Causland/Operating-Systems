#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *runner(void *arg);
void* printArr(void* arg);
int global_array[5];

void* printArr(void* arg){
    int i;
    for(i=0;i<5;i++) 
    {
        printf("T2: value %i array %i\n",i, global_array[i]);
    }
}

//this is a function pointer
//it takes a generic argument delcared as a void pointer
//this just means we can pass any pointer type to it
void *runner(void *arg) {
   int i;
    for(i=0;i<5;i++) {
        global_array[i]=i;
    }
}

int main(int argc, char const *argv[])
{

    pthread_t tid;
    pthread_t t2;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr,runner,NULL);
    pthread_create(&t2, &attr, printArr, NULL);
    
    //main thread and new thread run at the same time
    //if you don't call join, the main thread will print the result of sum before the
    //new thread has completed incrementing it
    pthread_join(t2, NULL);
    pthread_join(tid, NULL);
    
    //try calling sleep to see if thread has begun incrementing
    //sleep(1);
    int i;
    for(i=0;i<5;i++) 
    {
        printf("value %i array %i\n",i, global_array[i]);
    }

    return 0;
}
