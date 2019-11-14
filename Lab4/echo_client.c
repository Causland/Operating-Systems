//Lab 3 Chris Auslander

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

void* send1(void* arg){
    int send_fd, readval;
    struct sockaddr_in servaddr;
    char* sendMessage = malloc(sizeof(char)*16);
    char buffer[16];

    sendMessage = "Echo send 1";

    /*create a socket to listen on */
    send_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (send_fd < 0){ 
        printf("ERROR opening socket");
        int* result;
        *result = -1;
        return result;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000); 

    //Connect to the server
    if(connect(send_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        printf("Invalid Address \n");
        int* result;
        *result = -1;
        return result;
    }

    //Send message to server
    send(send_fd, sendMessage, strlen(sendMessage), 0);
    printf("Message sent: %s\n", sendMessage);

    //Receive message from server
    readval = read(send_fd, buffer, 1024);
    printf("Message received from server: %s\n", buffer);
}

void* send2(void* arg){
    int send_fd, readval;
    struct sockaddr_in servaddr;
    char* sendMessage = malloc(sizeof(char)*16);
    char buffer[16];

    sendMessage = "Echo send 2";

    /*create a socket to listen on */
    send_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (send_fd < 0){ 
        printf("ERROR opening socket");
        int* result;
        *result = -1;
        return result;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000); 

    //Connect to the server
    if(connect(send_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        printf("Invalid Address \n");
        int* result;
        *result = -1;
        return result;
    }

    //Send message to server
    send(send_fd, sendMessage, strlen(sendMessage), 0);
    printf("Message sent: %s\n", sendMessage);

    //Receive message from server
    readval = read(send_fd, buffer, 1024);
    printf("Message received from server: %s\n", buffer);
}

void* send3(void* arg){
    int send_fd, readval;
    struct sockaddr_in servaddr;
    char* sendMessage = malloc(sizeof(char)*16);
    char buffer[16];

    sendMessage = "Echo send 3";

    /*create a socket to listen on */
    send_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (send_fd < 0){ 
        printf("ERROR opening socket");
        int* result;
        *result = -1;
        return result;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000); 

    //Connect to the server
    if(connect(send_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        printf("Invalid Address \n");
        int* result;
        *result = -1;
        return result;
    }

    //Send message to server
    send(send_fd, sendMessage, strlen(sendMessage), 0);
    printf("Message sent: %s\n", sendMessage);

    //Receive message from server
    readval = read(send_fd, buffer, 1024);
    printf("Message received from server: %s\n", buffer);
}

int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    if(pthread_create(&t1, NULL, send1, NULL) < 0){
        printf("error creating thread 1\n");
    }

    if(pthread_create(&t2, NULL, send2, NULL) < 0){
        printf("error creating thread 1\n");
    }

    if(pthread_create(&t2, NULL, send3, NULL) < 0){
        printf("error creating thread 1\n");
    }

    void* result;
    if(pthread_join(t1, result) < 0){
        printf("error joining threads\n");
    }

    if(pthread_join(t2, result) < 0){
        printf("error joining threads\n");
    }

    if(pthread_join(t3, result) < 0){
        printf("error joining threads\n");
    }

    return 0;
}