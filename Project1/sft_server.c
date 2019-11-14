//Chris Auslander
//Project 1
//sft_server.c

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <unistd.h>
 #include <netdb.h>
 #include <arpa/inet.h>
 #include "sft_server.h"
 #define BUFFER_SIZE 1600
 #define SMALL_BUFFER_SIZE 160


void start_server(int port)
{
    //Connection information and buffers
    char requestString[BUFFER_SIZE];
    char fileLines[10][SMALL_BUFFER_SIZE];
    int listen_fd, comm_fd;    
    struct sockaddr_in servaddr;

    //Create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        printf("ERROR opening socket");
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

        //Discover file to send and open
        FILE *fileptr;
        char* filepath = malloc(strlen(request)+2);
        strcat(filepath, "./");
        strcat(filepath, request);
        
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

    }
}