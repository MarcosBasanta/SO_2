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

#define PID_FILE "pids.txt"
#define NUM_PROCESOS 5
#define PID_SIZE sizeof(pid_t)

pid_t pidPrincipal;

int file;
pid_t *pids;
pid_t pidHijo[2];

pid_t crea_jerarquia();
void configurar_manejador();
void manejador(int sig);
void escribir_pid(pid_t pid, int index);
pid_t leer_pid(int index);
void proyectar_archivo();
void desproyectar_archivo();

// Casi acabado el trabajo esta, se envia la señal, con los caminos que estan en  el arbol, bueno eso creo, hay que comprobarlo
// Instrucciones de uso en el README
// Encina no propaga la señal SIGTERM a los hijos
// Falta sincronizar la escritura de los PIDs en el archivo
// Falta sincronizar la lectura de los PIDs en el archivo
// Falta comprobar si de verdad se hace bien
// Falta comprobar funcionamiento en encina


int main() {
    int i;
    pid_t pidHijo;

    pidPrincipal = getpid();

    configurar_manejador();
    proyectar_archivo();

    pidHijo = crea_jerarquia();

    system("pstree | grep 'main'");
    pause();

    if (getpid() == pidPrincipal) {
        fprintf(stdout, "Proceso %d envía señal SIGTERM a %d\n", pidPrincipal, pidHijo);
        // Enviar señal SIGTERM al hijo
        kill(pidHijo, SIGTERM);
        // Esperar a que el hijo termine
        waitpid(pidHijo, NULL, 0);
    }

    desproyectar_archivo();
    // Borrar el archivo de PIDs al finalizar
    if (remove(PID_FILE) == 0) {
        printf("Archivo de PIDs eliminado correctamente.\n");
    } else {
        perror("Error al eliminar el archivo de PIDs");
    }

    return 0;
}

pid_t crea_jerarquia() {
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
                                                    // escribir_pid(pidYo, 0);
                                                    switch (pidHijo[0] = fork()) { // Proceso 54
                                                        case -1:
                                                            perror("main:proceso54:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 2);
                                                            switch (pidHijo[0] = fork()) { // Proceso 56
                                                                case -1:
                                                                    perror("main:proceso56:fork");
                                                                    return 9;
                                                                    break;
                                                                case 0:
                                                                    pidYo=getpid();
                                                                    escribir_pid(pidYo, 4);
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
                                                                                    pidHijo[0] = -1;
                                                                                    pidHijo[1] = -1;
                                                                                    pidYo=getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pidYo);
                                                                                    pause();
                                                                                    exit(0);
                                                                            }
                                                                            pidHijo[1] = -1;
                                                                            pidYo=getpid();
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pidYo);
                                                                            pause();
                                                                            exit(0);
                                                                            break;
                                                                    }
                                                                    pidHijo[1] = -1;
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pidYo);
                                                                    pause();
                                                                    exit(0);
                                                                    break;
                                                            }
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            pidYo=getpid();
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pidYo);
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
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
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 0);
                                                    fprintf(stdout, "Soy el proceso 51(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 47(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
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
                                                    // escribir_pid(pidYo, 2);
                                                    switch (pidHijo[0] = fork()) { // Proceso 55
                                                        case -1:
                                                            perror("main:proceso55:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 3);
                                                            fprintf(stdout, "Soy el proceso 55(pid=%d)\n", pidYo);
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 52(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 48(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
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
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 1);
                                                    fprintf(stdout, "Soy el proceso 53(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 49(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
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
            pidHijo[1] = -1;
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pidYo);
            pause();
            exit(0);
            break;
        default:
            pidHijo[1] = -1;
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
        pid_t pidYo, pidAux;
        pidYo = getpid();
        if (pidYo == pidPrincipal) {
            return;
        }
        if (pidYo == leer_pid(0)) { // Proceso 51
            pidAux = leer_pid(2); // Proceso 54
        } else if(pidYo == leer_pid(1)) { // Proceso 53
            pidAux = leer_pid(3); // Proceso 55
        } else if (pidYo == leer_pid(3)) { // Proceso 55
            pidAux = leer_pid(4); // Proceso 56
        } else {
            fprintf(stdout, "Proceso %d envía señal SIGTERM a todos sus hijos\n", pidYo);
            // Enviar señal SIGTERM a todos los hijos
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
            exit(0); // Terminar el proceso
        }

        fprintf(stdout, "Proceso %d envía señal SIGTERM a %d\n", pidYo, pidAux);
        // Enviar señal SIGTERM al hijo específico
        kill(pidAux, SIGTERM);

        // Esperar a que el hijo termine
        waitpid(pidAux, NULL, 0);

        exit(0); // Terminar el proceso
    }
}

void escribir_pid(pid_t pid, int index) {
    pids[index] = pid;
}

pid_t leer_pid(int index) {
    return pids[index];
}

void proyectar_archivo() {
    file=open(PID_FILE, O_RDWR | O_CREAT, 0666);
    if (file == -1) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    // Desplazar el puntero del archivo para que entren 7 PIDs
    if (lseek(file, NUM_PROCESOS * PID_SIZE - 1, SEEK_SET) == -1) {
        perror("Error en lseek");
        close(file);
        exit(EXIT_FAILURE);
    }

    // Escribir un byte vacío para extender el archivo
    if (write(file, "", 1) != 1) {
        perror("Error en write");
        close(file);
        exit(EXIT_FAILURE);
    }

    pids=(pid_t*) mmap(NULL, NUM_PROCESOS * PID_SIZE, PROT_WRITE, MAP_SHARED, file, 0);
    if (pids == MAP_FAILED) {
        perror("Error en mmap");
        close(file);
        exit(EXIT_FAILURE);
    }
}

void desproyectar_archivo() {
    // Desmapear la memoria y cerrar el archivo
    if (munmap((void*)pids, NUM_PROCESOS * PID_SIZE) == -1) {
        perror("Error en munmap");
    }
    close(file);
}
