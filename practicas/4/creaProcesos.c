#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void signalHandler(int signum){
    printf("hahaha no me matas");
}

int main(int args, char **argv){
    signal(17, signalHandler);
    unsigned pid = fork();
     if (pid == 0){
         printf("Soy el proceso hijo");
         return 10;
     }
     else{
         int status;
         sleep(2);
         printf("soy el proceso padre y mi hijo es %u", pid);
         printf("terminando despues del hijo y estatus %d", status);
     }
     printf("Hola mundo");
     return 0;
}
