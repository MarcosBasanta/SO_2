#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void crear_proceso(const char *nombre_proceso) {
    pid_t pidYo, pidHijo;

    switch (pidHijo = fork()) {
        case -1:
            perror("Error al crear proceso");
            exit(EXIT_FAILURE);
        case 0:
            pidYo = getpid();
            fprintf(stdout, "Soy el %s (pid=%d)\n", nombre_proceso, pidYo);
            exit(EXIT_SUCCESS);
        default:
            waitpid(pidHijo, NULL, 0);
    }
}

int main() {
    crear_proceso("proceso 45");
    crear_proceso("proceso 49");
    crear_proceso("proceso 53");

    // Solo el proceso principal ejecuta el comando pstree para depuración
    if (getppid() == 1) {
        system("pstree | grep 'main'");
    }

    return 0;
}