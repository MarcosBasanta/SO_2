#define _HPUX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void manejador(int sig);
void crear_procesos(int nivel, int max_nivel);

int main() {
    struct sigaction sa;
    sa.sa_handler = manejador;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction failed");
        exit(1);
    }

    crear_procesos(1, 5); // Crear una jerarquía de 5 niveles

    // Proceso padre
    printf("Soy el proceso padre (pid=%d)\n", getpid());
    sleep(1); // Asegurarse de que todos los hijos estén listos
    kill(0, SIGUSR1); // Enviar señal a todos los procesos en el mismo grupo

    // Esperar a que todos los hijos terminen
    while (waitpid(-1, NULL, 0) > 0);

    return 0;
}

void manejador(int sig) {
    printf("Proceso %d recibió la señal %d\n", getpid(), sig);
    if (sig == SIGUSR1) {
        // Esperar a que todos los hijos terminen
        while (waitpid(-1, NULL, 0) > 0);

        // Enviar señal al proceso padre si existe
        if (getppid() != 1) { // Si el proceso padre no es init
            kill(getppid(), SIGUSR1);
        }
        exit(0); // Terminar el proceso
    }
}

void crear_procesos(int nivel, int max_nivel) {
    if (nivel > max_nivel) return; // Limitar la profundidad de la jerarquía

    for (int i = 0; i < 2; i++) { // Crear dos hijos por nivel
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            // Proceso hijo
            printf("Soy el proceso de nivel %d (pid=%d)\n", nivel, getpid());
            crear_procesos(nivel + 1, max_nivel); // Crear el siguiente nivel de procesos
            pause(); // Esperar señal
            exit(0);
        }
    }
}