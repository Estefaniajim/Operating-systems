#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum){
    printf("hahaha no me metas");
}


int main(){
    signal(2, signalHandler);
    while(1){
        sleep(2);
        printf("trabajando");
    }
    return 0;
}