//Lab 3 Chris Auslander

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

int main(){
    int send_fd, readval;
    struct sockaddr_in servaddr;
    char* sendMessage = malloc(sizeof(char)*16);
    char buffer[16];

    printf("Enter a message to send\n");
    scanf("%s", sendMessage);

    /*create a socket to listen on */
    send_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (send_fd < 0){ 
        printf("ERROR opening socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000); 

    //Connect to the server
    if(connect(send_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        printf("Invalid Address \n");
        return -1;
    }

    //Send message to server
    send(send_fd, sendMessage, strlen(sendMessage), 0);
    printf("Message sent: %s\n", sendMessage);

    //Receive message from server
    readval = read(send_fd, buffer, 1024);
    printf("Message received from server: %s\n", buffer);
    return 0;
}