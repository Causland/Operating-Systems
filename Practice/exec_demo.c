#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int pid = fork();
    if(pid == 0){
        int ret = execl("/bin/hostname", "/bin/hostname",NULL);
        if(ret < 0){
            printf("error creating process");
        }
    }


}

