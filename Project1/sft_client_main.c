//Chris Auslander
//Project 1
//sft_client_main.c

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "sft_client.h"

int main(int argc, char const *argv[])
{
    //Define variables for client
    FILE *fptr;
    char file_to_request[10];
    int port = 1600;

    //Open the requests.txt file
    fptr = fopen("requests.txt", "r");
    if(fptr == NULL){
        printf("file not found\n");
        exit(0);
    }

    //Read all lines - Remove newline from text
    while(fgets(file_to_request, 8, fptr) != NULL){
        if(*(file_to_request+strlen(file_to_request)-1) == '\n'){
            *(file_to_request+strlen(file_to_request)-1) = 0;
        }
        make_request(file_to_request, "127.0.0.1", port);
    }

    fclose(fptr);
    return 0;
}
