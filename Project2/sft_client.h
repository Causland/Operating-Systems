//Chris Auslander
//Project 2
//sft_client.h with structure and make_request for extra credit

typedef struct connectiondetails {
    char* file_to_request;
    char* address;
    int port;
}connectiondetails;

void* make_request(void* arg);