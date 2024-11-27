#define _HPUX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/mman.h>

#define PID_FILE "pids.dat"
#define NUM_PROCESOS 6
#define PID_SIZE sizeof(pid_t)
#define FILE_SIZE (NUM_PROCESOS * PID_SIZE)

pid_t pidPrincipal;
pid_t *pids;
pid_t pidHijo[2];

void crea_jerarquia();
void configurar_manejador();
void manejador(int sig);
void escribir_pid(pid_t pid, int index);
pid_t leer_pid(int index);
void proyectar_archivo(int file);
void desproyectar_archivo(int file);
const char* obtener_cabecera();

int main() {
    int i, file;
    pidPrincipal = getpid();

    puts(obtener_cabecera());
    fflush(stdout);
    
    proyectar_archivo(file);
    configurar_manejador();

    fprintf(stdout, "Soy el proceso patriarca, con pid %d\n", pidPrincipal);
    fflush(stdout);
    crea_jerarquia();

    pause();

    if (getpid() == pidPrincipal) {
        kill(pidHijo[0], SIGTERM);

        waitpid(pidHijo[0], NULL, 0);
        fprintf(stdout, "Eliminacion de todo el arbol completada exitosamente\n");
        fflush(stdout);

        desproyectar_archivo(file);
    }

    return 0;
}

void crea_jerarquia() {
    pid_t pidYo;
    switch(pidHijo[0] = fork()) { // Proceso 38
        case -1:
            fprintf(stderr, "main:proceso38:fork");
            fflush(stdout);
            return;
            break;
        case 0:
            switch (pidHijo[0] = fork()) { // Proceso 39
                case -1:
                    fprintf(stderr, "main:proceso39:fork");
                    fflush(stdout);
                    return;
                    break;
                case 0:
                    switch(pidHijo[0] = fork()) { // Proceso 40
                        case -1:
                            fprintf(stderr, "main:proceso40:fork");
                            fflush(stdout);
                            return;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 42
                                case -1:
                                    fprintf(stderr, "main:proceso42:fork");
                                    fflush(stdout);
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 46
                                        case -1:
                                            fprintf(stderr, "main:proceso46:fork");
                                            fflush(stdout);
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 50
                                                case -1:
                                                    fprintf(stderr, "main:proceso50:fork");
                                                    fflush(stdout);
                                                    return;
                                                    break;
                                                case 0:
                                                    switch (pidHijo[0] = fork()) { // Proceso 54
                                                        case -1:
                                                            fprintf(stderr, "main:proceso54:fork");
                                                            fflush(stdout);
                                                            return;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 2);
                                                            switch (pidHijo[0] = fork()) { // Proceso 56
                                                                case -1:
                                                                    fprintf(stderr, "main:proceso56:fork");
                                                                    fflush(stdout);
                                                                    return;
                                                                    break;
                                                                case 0:
                                                                    pidYo=getpid();
                                                                    escribir_pid(pidYo, 4);
                                                                    switch (pidHijo[0] = fork()) { // Proceso 57
                                                                        case -1:
                                                                            fprintf(stderr, "main:proceso57:fork");
                                                                            fflush(stdout);
                                                                            return;
                                                                            break;
                                                                        case 0:
                                                                            switch (pidHijo[0] = fork()) { // Proceso 58
                                                                                case -1:
                                                                                    fprintf(stderr, "main:proceso58:fork");
                                                                                    fflush(stdout);
                                                                                    return;
                                                                                    break;
                                                                                case 0:
                                                                                    pidHijo[0] = -1;
                                                                                    pidHijo[1] = -1;
                                                                                    pause();
                                                                            }
                                                                            pidHijo[1] = -1;
                                                                            pause();
                                                                            break;
                                                                    }
                                                                    pidHijo[1] = -1;
                                                                    pause();
                                                                    break;
                                                            }
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            pause();
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pause();
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 43
                                case -1:
                                    fprintf(stderr, "main:proceso43:fork");
                                    fflush(stdout);
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 47
                                        case -1:
                                            fprintf(stderr, "main:proceso47:fork");
                                            fflush(stdout);
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 51
                                                case -1:
                                                    fprintf(stderr, "main:proceso51:fork");
                                                    fflush(stdout);
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 0);
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pause();
                                    break;
                            }
                            pause();
                            break;
                    }
                    switch (pidHijo[1] = fork()) { // Proceso 41
                        case -1:
                            fprintf(stderr, "main:proceso41:fork");
                            fflush(stdout);
                            return;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 44
                                case -1:
                                    fprintf(stderr, "main:proceso44:fork");
                                    fflush(stdout);
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 48
                                        case -1:
                                            fprintf(stderr, "main:proceso48:fork");
                                            fflush(stdout);
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 52
                                                case -1:
                                                    fprintf(stderr, "main:proceso52:fork");
                                                    fflush(stdout);
                                                    return;
                                                    break;
                                                case 0:
                                                    switch (pidHijo[0] = fork()) { // Proceso 55
                                                        case -1:
                                                            fprintf(stderr, "main:proceso55:fork");
                                                            fflush(stdout);
                                                            return;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 3);
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            pause();
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pause();
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 45
                                case -1:
                                    fprintf(stderr, "main:proceso45:fork");
                                    fflush(stdout);
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 49
                                        case -1:
                                            fprintf(stderr, "main:proceso49:fork");
                                            fflush(stdout);
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 53
                                                case -1:
                                                    fprintf(stderr, "main:proceso53:fork");
                                                    fflush(stdout);
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 1);
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pause();
                                    break;
                            }
                            pause();
                            break;
                    }
                    pause();
                    break;
            }
            pidHijo[1] = -1;
            pause();
            break;
        default:
            pidHijo[1] = -1;
            break;
    }
}

void configurar_manejador() {
    struct sigaction sa;
    // Configurar la estructura sigaction
    sa.sa_handler = manejador;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    // Establecer el manejador de señales para SIGTERM
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        fprintf(stderr, "Error al establecer el manejador de señales");
        fflush(stdout);
        exit(EXIT_FAILURE);
    }
}

void manejador(int sig) {
    pid_t pidYo;
    pidYo = getpid();
    if (sig == SIGTERM) {
        if(pidYo == pidPrincipal) {
            fprintf(stdout, "Comienzo de la propagacion de la señal...\n");
            fflush(stdout);
            return;
        }
        if (pidYo == leer_pid(0)) { // Proceso 51
            pidHijo[0] = leer_pid(2); // Proceso 54
            pidHijo[1] = -1;
        } else if(pidYo == leer_pid(1)) { // Proceso 53
            pidHijo[0] = leer_pid(3); // Proceso 55
            pidHijo[1] = -1;
        } else if (pidYo == leer_pid(3)) { // Proceso 55
            pidHijo[0] = leer_pid(4); // Proceso 56
            pidHijo[1] = -1;
        }
        if(pidHijo[0] != -1) {
            kill(pidHijo[0], SIGTERM);
        }
        if (pidHijo[1] != -1) {
            kill(pidHijo[1], SIGTERM);
        }
        if(pidHijo[0] != -1) {
            waitpid(pidHijo[0], NULL, 0);
        }
        if (pidHijo[1] != -1) {
            waitpid(pidHijo[1], NULL, 0);
        }
        exit(0);
    }
}

void escribir_pid(pid_t pid, int index) {
    pids[index] = pid;
}

pid_t leer_pid(int index) {
    return pids[index];
}

void proyectar_archivo(int file) {
    int fd = open(PID_FILE, O_CREAT | O_RDWR, 0666);

    if (fd == -1) {
        fprintf(stderr, "Error al crear el archivo");
        fflush(stdout);
        exit(EXIT_FAILURE);
    }
    if (ftruncate(fd, FILE_SIZE) == -1) {
        fprintf(stderr, "Error al ajustar el tamaño del archivo");
        fflush(stdout);
        exit(EXIT_FAILURE);
    }

    pids = (pid_t *)mmap(0, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (pids == MAP_FAILED) {
        fprintf(stderr, "Error al mapear el archivo");
        fflush(stdout);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void desproyectar_archivo(int file) {
    // Desmapear la memoria y cerrar el archivo
    if (munmap((void*)pids, NUM_PROCESOS * PID_SIZE) == -1) {
        fprintf(stderr, "Error en munmap");
        fflush(stdout);
    }

    close(file);

    if (remove(PID_FILE) == 0) {
        fprintf(stdout, "Archivo de PIDs eliminado correctamente.\n");
        fflush(stdout);
    } else {
        fprintf(stderr, "Error al eliminar el archivo de PIDs\n");
        fflush(stdout);
    }
}

const char* obtener_cabecera() {
    static const char cabecera[] = 
        "\n"
        "╔════════════════════════════════════════════════════════════╗\n"
        "║             PROGRAMA DE ÁRBOL DE PROCESOS                  ║\n"
        "╚════════════════════════════════════════════════════════════╝\n"
        "\n"
        "Estructura del árbol de procesos:\n\n"
        "                    37               \n"
        "                     |               \n"
        "                    38               \n"
        "                     |               \n"
        "                    39               \n"
        "                  /     \\           \n"
        "                 40       41         \n"
        "                /  \\    /   \\      \n"
        "              42   43   44    45     \n"
        "               |    |    |     |     \n"
        "              46   47   48    49     \n"
        "               |    |    |     |     \n"
        "              50   51   52    53     \n"
        "                \\         \\        \n"
        "                 54        55        \n"
        "                    \\               \n"
        "                     56              \n"
        "                      |              \n"
        "                     57              \n"
        "                      |              \n"
        "                     58            \n\n"
        "Iniciando creación de procesos...\n";
    
    return cabecera;
}
