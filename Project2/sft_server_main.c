//Chris Auslander
//Project 2
//sft_server_main.c

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include "sft_server.h"

int main(int argc, char const *argv[])
{
    start_server(1600);
    return 0;
}
