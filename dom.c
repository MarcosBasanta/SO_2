// Instrucciones de uso en el README.md
// Falta limpiar el codigo, salidas de comprobacion, printf, etc
// Añadir interfaz de usuario minima para dar informacion y feedback
// Sincronizar la escritura de los PIDs en el archivo (Opcional)
// Sincronizar la lectura de los PIDs en el archivo (Opcional)

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
    fflush(stdout); // Forzar el vaciado del búfer
    
    proyectar_archivo(file);
    configurar_manejador();

    crea_jerarquia();

    pause();

    if (getpid() == pidPrincipal) {
        fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidPrincipal, pidHijo[0]);
        fflush(stdout); // Forzar el vaciado del búfer
        kill(pidHijo[0], SIGTERM);

        waitpid(pidHijo[0], NULL, 0);

        desproyectar_archivo(file);

        // exit(0);
    }

    return 0;
}

void crea_jerarquia() {
    pid_t pidYo;
    switch(pidHijo[0] = fork()) { // Proceso 38
        case -1:
            fprintf(stderr, "main:proceso38:fork");
            fflush(stdout); // Forzar el vaciado del búfer
            return;
            break;
        case 0:
            switch (pidHijo[0] = fork()) { // Proceso 39
                case -1:
                    fprintf(stderr, "main:proceso39:fork");
                    fflush(stdout); // Forzar el vaciado del búfer
                    return;
                    break;
                case 0:
                    switch(pidHijo[0] = fork()) { // Proceso 40
                        case -1:
                            fprintf(stderr, "main:proceso40:fork");
                            fflush(stdout); // Forzar el vaciado del búfer
                            return;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 42
                                case -1:
                                    fprintf(stderr, "main:proceso42:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 46
                                        case -1:
                                            fprintf(stderr, "main:proceso46:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 50
                                                case -1:
                                                    fprintf(stderr, "main:proceso50:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    // escribir_pid(pidYo, 0);
                                                    switch (pidHijo[0] = fork()) { // Proceso 54
                                                        case -1:
                                                            fprintf(stderr, "main:proceso54:fork");
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            return;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 2);
                                                            switch (pidHijo[0] = fork()) { // Proceso 56
                                                                case -1:
                                                                    fprintf(stderr, "main:proceso56:fork");
                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                    return;
                                                                    break;
                                                                case 0:
                                                                    pidYo=getpid();
                                                                    escribir_pid(pidYo, 4);
                                                                    switch (pidHijo[0] = fork()) { // Proceso 57
                                                                        case -1:
                                                                            fprintf(stderr, "main:proceso57:fork");
                                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                                            return;
                                                                            break;
                                                                        case 0:
                                                                            switch (pidHijo[0] = fork()) { // Proceso 58
                                                                                case -1:
                                                                                    fprintf(stderr, "main:proceso58:fork");
                                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                                    return;
                                                                                    break;
                                                                                case 0:
                                                                                    pidHijo[0] = -1;
                                                                                    pidHijo[1] = -1;
                                                                                    pidYo=getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pidYo);
                                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                                    pause();
                                                                            }
                                                                            pidHijo[1] = -1;
                                                                            pidYo=getpid();
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pidYo);
                                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                                            pause();
                                                                            break;
                                                                    }
                                                                    pidHijo[1] = -1;
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pidYo);
                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                    pause();
                                                                    break;
                                                            }
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pidYo);
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            pause();
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 42(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 43
                                case -1:
                                    fprintf(stderr, "main:proceso43:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 47
                                        case -1:
                                            fprintf(stderr, "main:proceso47:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 51
                                                case -1:
                                                    fprintf(stderr, "main:proceso51:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 0);
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    fprintf(stdout, "Soy el proceso 51(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 47(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 43(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 40(pid=%d)\n", pidYo);
                            fflush(stdout); // Forzar el vaciado del búfer
                            pause();
                            break;
                    }
                    switch (pidHijo[1] = fork()) { // Proceso 41
                        case -1:
                            fprintf(stderr, "main:proceso41:fork");
                            fflush(stdout); // Forzar el vaciado del búfer
                            return;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 44
                                case -1:
                                    fprintf(stderr, "main:proceso44:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 48
                                        case -1:
                                            fprintf(stderr, "main:proceso48:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 52
                                                case -1:
                                                    fprintf(stderr, "main:proceso52:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    // escribir_pid(pidYo, 2);
                                                    switch (pidHijo[0] = fork()) { // Proceso 55
                                                        case -1:
                                                            fprintf(stderr, "main:proceso55:fork");
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            return;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 3);
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            fprintf(stdout, "Soy el proceso 55(pid=%d)\n", pidYo);
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            pause();
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 52(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 48(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 44(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 45
                                case -1:
                                    fprintf(stderr, "main:proceso45:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 49
                                        case -1:
                                            fprintf(stderr, "main:proceso49:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 53
                                                case -1:
                                                    fprintf(stderr, "main:proceso53:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 1);
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    fprintf(stdout, "Soy el proceso 53(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 49(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 45(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 41(pid=%d)\n", pidYo);
                            fflush(stdout); // Forzar el vaciado del búfer
                            pause();
                            break;
                    }
                    pidYo=getpid();
                    fprintf(stdout, "Soy el proceso 39(pid=%d)\n", pidYo);
                    fflush(stdout); // Forzar el vaciado del búfer
                    pause();
                    break;
            }
            pidHijo[1] = -1;
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pidYo);
            fflush(stdout); // Forzar el vaciado del búfer
            pause();
            break;
        default:
            pidHijo[1] = -1;
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 37(pid=%d)\n", pidYo);
            fflush(stdout); // Forzar el vaciado del búfer
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
    fprintf(stdout, "Proceso %d recibió la señal %d\n", pidYo, sig);
    if (sig == SIGTERM) {
        if(pidYo == pidPrincipal) {
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
            fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
            fflush(stdout); // Forzar el vaciado del búfer
        }
        if (pidHijo[1] != -1) {
            kill(pidHijo[1], SIGTERM);
            fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[1]);
            fflush(stdout); // Forzar el vaciado del búfer
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
        "                    37                \n"
        "                   /  \\              \n"
        "                 38    39            \n"
        "                /     /  \\           \n"
        "              42    40    41        \n"
        "              |     |     | \\       \n"
        "              46   44    45  43     \n"
        "              |     |     |   |     \n"
        "              50   48    49  47     \n"
        "              |     |     |   |     \n"
        "              54   52    53  51     \n"
        "              |     |     |   |     \n"
        "              58   56    57  55     \n\n"
        "Iniciando creación de procesos...\n\n";
    
    return cabecera;
}
