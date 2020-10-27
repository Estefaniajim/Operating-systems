#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void signalHandler(int signum){
    int status;
    wait(&status);
}
void controlC(int singnum){
    int status;
    wait(&status);
    printf("Mi hijo termino con status %d", status);
}

int main(int args, char **argv){
    signal(17, signalHandler);
    signal(2, controlC);
    unsigned pid = fork();
     if (pid == 0){
         sleep(5);
         printf("Soy el proceso hijo %u", pid);
         return 1;
     }
     else{
         printf("soy el proceso padre y mi hijo es %u", pid);
         while(1){
             sleep(2);
             printf("trabajando");
         }
         
     }
     printf("Hola mundo");
     return 0;
}
