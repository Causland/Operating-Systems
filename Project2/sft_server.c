//Chris Auslander
//Project 2
//sft_server.c

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <pthread.h>
 #include "sft_server.h"
 #include "voidQueue.h"
 #define BUFFER_SIZE 1600
 #define SMALL_BUFFER_SIZE 160

Queue* queue;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t boss_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t worker_cond = PTHREAD_COND_INITIALIZER;

void* worker(void* arg){
    workdetails* item;
    char fileLines[10][SMALL_BUFFER_SIZE];
    while(1){
        
        //Lock the queue until dequeue successful
        pthread_mutex_lock(&m);
        while(isEmpty(queue)){
            pthread_cond_wait(&worker_cond, &m);
        }
        item = dequeue(queue);
        printf("Processing request\n");
        pthread_mutex_unlock(&m);
        
        //Queue item processing
        char* filepath = item->filepath;
        char* request = item->full_request;
        int comm_fd = item->socket_descriptor;

        FILE *fileptr;
        fileptr = fopen(filepath, "r"); 
        if(fileptr == NULL){
            exit(0);
        }

        //Extract content from the file
        int count = 0;
        while(fgets(fileLines[count], SMALL_BUFFER_SIZE, fileptr) != NULL){
            ++count;
        }
        
        //Concatenate all lines together for one write to socket
        char* writeString = malloc(BUFFER_SIZE);
        for(int i=0;i<count;i++){
            strcat(writeString, fileLines[i]);
        }

        write(comm_fd, writeString, strlen(writeString)); 

        printf("Completed request\n");
    }
}


void start_server(int port)
{
    //Connection information and buffers
    char requestString[BUFFER_SIZE];
    int listen_fd, comm_fd;    
    struct sockaddr_in servaddr;

    //Create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        printf("ERROR opening socket");
    }

    //Create threads
    pthread_t workerThread[10];
    queue = createQueue(5);
    for(int i=0;i<10;i++){
        pthread_create(&workerThread[i],NULL,worker,NULL);
    }

    //Set options for the socket
    int optval = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, 
            (const void *)&optval , sizeof(int));

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, 
            (const void *)&optval , sizeof(int));
    
    //Populate connection information for server
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(port); 

    //Bind socket to address
    if (bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("error binding");
    }

    //Listen on the socket
    if (listen(listen_fd, 10) < 0) {
        printf("error listening");
    } 

    //Run the server to termination
    while(1) {
        //Accept incoming connection
        comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
        if(comm_fd < 0) {
            printf("error accepting");
        }

        //Make sure that the memory is clear
        memset(requestString,0,sizeof(requestString));
        
        //Read data from the socket
        read(comm_fd,requestString,100);

        //Parse out the file request
        char* request = malloc(strlen(requestString)-8);
        strcat(request, requestString+4);
        *(request+6) = 0;

        //Discover file to send
        char* filepath = malloc(strlen(request)+2);
        strcat(filepath, "./");
        strcat(filepath, request);

        //Create workdetails
        workdetails* details = malloc(sizeof(workdetails));
        details->filepath = filepath;
        details->full_request = request;
        details->socket_descriptor = comm_fd;

        //Lock the queue and enqueue details
        pthread_mutex_lock(&m);
        while(isFull(queue)){
            pthread_cond_wait(&boss_cond, &m);
        }
        enqueue(queue,details);
        printf("Request added to the queue\n");
        pthread_mutex_unlock(&m);
        pthread_cond_signal(&worker_cond);
    }
}