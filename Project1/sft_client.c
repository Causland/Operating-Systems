//Chris Auslander
//Project 1
//sft_client.c
 
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <netdb.h>
 #include "sft_client.h"
 #define BUFFER_SIZE 1600

int make_request(char* request, char* server, int port) 
{
    //Connection information and buffer
    int send_fd, readval;
    char rBuffer[BUFFER_SIZE];
    struct sockaddr_in servaddr;

    //Create socket
    send_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (send_fd < 0){ 
        printf("ERROR opening socket");
        return -1;
    }

    //Populate connection information at server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, server, &servaddr.sin_addr.s_addr);
    servaddr.sin_port = htons(port); 
    
    //Connect to server
    if(connect(send_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        printf("Invalid Address \n");
        return -1;
    }
    
    //Create command for server processing and send
    char* fullMessage = malloc(strlen(request) + 9);
    strcat(fullMessage, "GET ");
    strcat(fullMessage, request);
    strcat(fullMessage, " EOR");
    send(send_fd, fullMessage, strlen(fullMessage), 0);

    //Read the response from server (Should be one string)
    readval = read(send_fd, rBuffer, sizeof(rBuffer));

    //Add null termination to read text
    *(rBuffer+readval) = 0;

    //Create file to open
    FILE *fileptr;
    char* filepath = malloc(strlen(request) + 16);
    strcat(filepath, "./client_files/");
    strcat(filepath, request);

    //Open the file to write
    fileptr = fopen(filepath, "w"); 
    fprintf(fileptr, rBuffer, strlen(rBuffer));

    return 0;
}