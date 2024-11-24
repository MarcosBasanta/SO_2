#define _HPUX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define PID_FILE "pids.txt"
#define NUM_PROCESOS 7
#define PID_SIZE 12

int crea_jerarquia();
void configurar_manejador();
void manejador(int sig);
void escribir_pid(pid_t pid, int index);
pid_t leer_pid(int index);


// Falta usar un archivo proyectado en memoria para guardar los pids
// Falta comprobar si de verdad se hace bien
// Falta comprobar funcionamiento en encina


int main() {
    int i;
    pid_t pidHijo;
    FILE *file = fopen(PID_FILE, "w");

    configurar_manejador();

    // Limpiar el archivo de PIDs al inicio
    if (file == NULL) {
        perror("Error al abrir el archivo de PIDs");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    pidHijo = crea_jerarquia();

    system("pstree | grep 'main'");
    pause();
    waitpid(pidHijo, NULL, 0);
    return 0;
}

pid_t crea_jerarquia() {
    pid_t pidHijo[2];
    pid_t pidYo;
    switch(pidHijo[0] = fork()) { // Proceso 38
        case -1:
            perror("main:proceso38:fork");
            return 2;
            break;
        case 0:
            switch (pidHijo[0] = fork()) { // Proceso 39
                case -1:
                    perror("main:proceso39:fork");
                    return 3;
                    break;
                case 0:
                    switch(pidHijo[0] = fork()) { // Proceso 40
                        case -1:
                            perror("main:proceso40:fork");
                            return 4;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 42
                                case -1:
                                    perror("main:proceso42:fork");
                                    return 6;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 46
                                        case -1:
                                            perror("main:proceso46:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 50
                                                case -1:
                                                    perror("main:proceso50:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 0);
                                                    switch (pidHijo[0] = fork()) { // Proceso 54
                                                        case -1:
                                                            perror("main:proceso54:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 4);
                                                            switch (pidHijo[0] = fork()) { // Proceso 56
                                                                case -1:
                                                                    perror("main:proceso56:fork");
                                                                    return 9;
                                                                    break;
                                                                case 0:
                                                                    pidYo=getpid();
                                                                    escribir_pid(pidYo, 6);
                                                                    switch (pidHijo[0] = fork()) { // Proceso 57
                                                                        case -1:
                                                                            perror("main:proceso57:fork");
                                                                            return 9;
                                                                            break;
                                                                        case 0:
                                                                            switch (pidHijo[0] = fork()) { // Proceso 58
                                                                                case -1:
                                                                                    perror("main:proceso58:fork");
                                                                                    return 9;
                                                                                    break;
                                                                                case 0:
                                                                                    pidYo=getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pidYo);
                                                                                    pause();
                                                                                    exit(0);
                                                                            }
                                                                            pidYo=getpid();
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pidYo);
                                                                            pause();
                                                                            exit(0);
                                                                            break;
                                                                    }
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pidYo);
                                                                    pause();
                                                                    exit(0);
                                                                    break;
                                                            }
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pidYo);
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 42(pid=%d)\n", pidYo);
                                    pause();
                                    exit(0);
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 43
                                case -1:
                                    perror("main:proceso43:fork");
                                    return 7;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 47
                                        case -1:
                                            perror("main:proceso47:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 51
                                                case -1:
                                                    perror("main:proceso51:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 1);
                                                    fprintf(stdout, "Soy el proceso 51(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 47(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 43(pid=%d)\n", pidYo);
                                    pause();
                                    exit(0);
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 40(pid=%d)\n", pidYo);
                            pause();
                            exit(0);
                            break;
                    }
                    switch (pidHijo[1] = fork()) { // Proceso 41
                        case -1:
                            perror("main:proceso41:fork");
                            return 5;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 44
                                case -1:
                                    perror("main:proceso44:fork");
                                    return 6;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 48
                                        case -1:
                                            perror("main:proceso48:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 52
                                                case -1:
                                                    perror("main:proceso52:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 2);
                                                    switch (pidHijo[0] = fork()) { // Proceso 55
                                                        case -1:
                                                            perror("main:proceso55:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 5);
                                                            fprintf(stdout, "Soy el proceso 55(pid=%d)\n", pidYo);
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                                                    fprintf(stdout, "Soy el proceso 52(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 48(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 44(pid=%d)\n", pidYo);
                                    pause();
                                    exit(0);
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 45
                                case -1:
                                    perror("main:proceso45:fork");
                                    return 7;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 49
                                        case -1:
                                            perror("main:proceso49:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 53
                                                case -1:
                                                    perror("main:proceso53:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 3);
                                                    fprintf(stdout, "Soy el proceso 53(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 49(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 45(pid=%d)\n", pidYo);
                                    pause();
                                    exit(0);
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 41(pid=%d)\n", pidYo);
                            pause();
                            exit(0);
                            break;
                    }
                    pidYo=getpid();
                    fprintf(stdout, "Soy el proceso 39(pid=%d)\n", pidYo);
                    pause();
                    exit(0);
                    break;
            }
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pidYo);
            pause();
            exit(0);
            break;
        default:
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 37(pid=%d)\n", pidYo);
            break;
    }
     
    return pidHijo[0];
}

void configurar_manejador() {
    struct sigaction sa;

    // Configurar la estructura sigaction
    sa.sa_handler = manejador;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    // Establecer el manejador de señales para SIGTERM
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error al establecer el manejador de señales");
        exit(EXIT_FAILURE);
    }
}

void manejador(int sig) {
    printf("Proceso %d recibió la señal %d\n", getpid(), sig);
    if (sig == SIGTERM) {
        pid_t pidYo, pidHijo;
        pidYo = getpid();
        if (pidYo == leer_pid(0)) { // Proceso 50
            exit(0); // Terminar el proceso
        } else if (pidYo == leer_pid(1)) { // Proceso 51
            pidHijo = leer_pid(4); // Proceso 54
        } else if (pidYo == leer_pid(2)) { // Proceso 52
            exit(0); // Terminar el proceso
        } else if(pidYo == leer_pid(3)) {
            pidHijo = leer_pid(5); // Proceso 55
        } else if (pidYo == leer_pid(4)) { // Proceso 54
            exit(0); // Terminar el proceso
        } else if (pidYo == leer_pid(5)) { // Proceso 55
            pidHijo = leer_pid(6); // Proceso 56
        } else {
            // Enviar señal SIGTERM a todos los hijos
            kill(0, SIGTERM); // Enviar a todos los procesos en el mismo grupo de procesos
            // Esperar a que todos los hijos terminen
            while (waitpid(-1, NULL, 0) > 0);
            exit(0); // Terminar el proceso
        }

        // Enviar señal SIGTERM al hijo específico
        kill(pidHijo, SIGTERM);

        // Esperar a que el hijo termine
        waitpid(pidHijo, NULL, 0);

        exit(0); // Terminar el proceso
    }
}

void escribir_pid(pid_t pid, int index) {
    FILE *file = fopen(PID_FILE, "a");
    if (file == NULL) {
        perror("Error al abrir el archivo de PIDs");
        exit(EXIT_FAILURE);
    }

    // Bloquear el archivo
    if (flock(fileno(file), LOCK_EX) == -1) {
        perror("Error al bloquear el archivo de PIDs");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Escribir la posición y el PID
    fprintf(file, "%d %d\n", index, pid);
    fprintf(stdout, "Se escribió el PID %d en la posición %d\n", pid, index);

    // Desbloquear el archivo
    if (flock(fileno(file), LOCK_UN) == -1) {
        perror("Error al desbloquear el archivo de PIDs");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

pid_t leer_pid(int index) {
    FILE *file = fopen(PID_FILE, "r");
    pid_t pid;
    int pos;

    if (file == NULL) {
        perror("Error al abrir el archivo de PIDs");
        exit(EXIT_FAILURE);
    }
    
    // Bloquear el archivo
    if (flock(fileno(file), LOCK_SH) == -1) { // LOCK_SH para bloqueo compartido
        perror("Error al bloquear el archivo de PIDs");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d %d", &pos, &pid) == 2) {
        if (pos == index) {
            // Desbloquear el archivo
            if (flock(fileno(file), LOCK_UN) == -1) {
                perror("Error al desbloquear el archivo de PIDs");
                fclose(file);
                exit(EXIT_FAILURE);
            }
            fclose(file);
            return pid;
        }
    }
    // Desbloquear el archivo
    if (flock(fileno(file), LOCK_UN) == -1) {
        perror("Error al desbloquear el archivo de PIDs");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    fprintf(stderr, "Error: no se encontró el PID en la posición %d\n", index);
    exit(EXIT_FAILURE);
}