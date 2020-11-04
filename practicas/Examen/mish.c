#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_NUM_ARGS 10
size_t string_parser(char *input, char *word_array[]) {
size_t n = 0;
while (*input) {
    while (isspace((unsigned char)*input))
    ++input;
if (*input) {
    word_array[n++] = (char *)input;
    while (*input && !isspace((unsigned char)*input))
    ++input;
*(input) = '\0';
++input;
}
}
word_array[n] = NULL;
return n;
}
 
int main(void) {
  char *args[MAX_NUM_ARGS + 1]; /* command line (of 80) has max of 5 arguments */
  char line[MAX_LINE + 1];
  int should_run = 1;
 
  int i;
 
  while (should_run) {
    printf("mish> ");
    if (!fgets(line,MAX_LINE,stdin)){
        break;
    }

    line[strcspn(line, "\n")] = '\0';
    // Separamos la línea en palabras separadas por espacio
    // y las guardamos en args
    i = string_parser(line,args); // i contiene el número de argumentos
    printf("%d, %s %s\n", i, args[1],line); // Es solo para pruebas borrar cuando esté listo
    
    pid_t pid, wpid;
    int status;

    pid = fork(); //Se crea un proceso hijo
    if (pid == 0) {
        // Proceso del hijo
        if (execvp(args[0], args) == -1) {
            perror("lsh");
        }
     printf("Programa no encontrado");
     exit(EXIT_FAILURE);
     } 
    else if (pid < 0) {
    // Si se llega a tener un error
    perror("lsh");
    }
    else {
         // Proceso del hijo
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
            } 
        while (!WIFEXITED(status) && !WIFSIGNALED(status));

        }
    return 1;
    fflush(stdout);
    fflush(stdin);
    line[0] = '\0';
    }
    return 0;
    }



