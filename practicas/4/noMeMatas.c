#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum){
    int status;
    printf("hahaha no me matas");
}


int main(){
    signal(2, signalHandler);
    while(1){
        sleep(2);
        printf("trabajando");
    }
    return 0;
}
