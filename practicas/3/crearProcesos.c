#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int args, char **argv){
    unsigned pid = fork();
    if (pid == 0){
        char *newargve[] = {NULL};
        printf("Soy el proceso hijo");
        execve(argv[1], &argv[1], newargve);
        return 10;
    }else {
        int status;
        printf("soy el proceso padre y mi hijo es %u", pid);
        wait(&status);
        printf("terminando despues del hijo y estatus %d", status);
    }
    printf("Hola mundo");
    return 0;
}