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
// Error en encina escribe bien en memoria mapeada, se va guardando bien, pero a la hora de leer no lo hace bien y fuerza la finalizacion del proceso
// Falta sincronizar la escritura de los PIDs en el archivo
// Falta sincronizar la lectura de los PIDs en el archivo
// Falta comprobar si de verdad se hace bien
// Falta comprobar funcionamiento en encina

int main() {
    int i;
    pid_t pidAux;

    pidPrincipal = getpid();

    configurar_manejador();
    proyectar_archivo();

    pidAux = crea_jerarquia();

    // system("pstree | grep 'main'"); // Comentar en encina
    pause();

    if (getpid() == pidPrincipal) {
        fprintf(stdout, "Proceso %d envía señal SIGTERM a %d\n", pidPrincipal, pidAux);
        fflush(stdout); // Forzar el vaciado del búfer
        // Enviar señal SIGTERM al hijo
        kill(pidAux, SIGTERM);
        // Esperar a que el hijo termine
        waitpid(pidAux, NULL, 0);
    }

    pause(); // Prueba para comprobar que los procesos terminan

    desproyectar_archivo();
    // Borrar el archivo de PIDs al finalizar
    if (remove(PID_FILE) == 0) {
        printf("Archivo de PIDs eliminado correctamente.\n");
    } else {
        fprintf(stderr, "Error al eliminar el archivo de PIDs");
        fflush(stdout); // Forzar el vaciado del búfer
    }


    return 0;
}

pid_t crea_jerarquia() {
    pid_t pidYo;
    switch(pidHijo[0] = fork()) { // Proceso 38
        case -1:
            fprintf(stderr, "main:proceso38:fork");
            fflush(stdout); // Forzar el vaciado del búfer
            return 2;
            break;
        case 0:
            switch (pidHijo[0] = fork()) { // Proceso 39
                case -1:
                    fprintf(stderr, "main:proceso39:fork");
                    fflush(stdout); // Forzar el vaciado del búfer
                    return 3;
                    break;
                case 0:
                    switch(pidHijo[0] = fork()) { // Proceso 40
                        case -1:
                            fprintf(stderr, "main:proceso40:fork");
                            fflush(stdout); // Forzar el vaciado del búfer
                            return 4;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 42
                                case -1:
                                    fprintf(stderr, "main:proceso42:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return 6;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 46
                                        case -1:
                                            fprintf(stderr, "main:proceso46:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 50
                                                case -1:
                                                    fprintf(stderr, "main:proceso50:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return 9;
                                                    break;
                                                case 0:
                                                    // escribir_pid(pidYo, 0);
                                                    switch (pidHijo[0] = fork()) { // Proceso 54
                                                        case -1:
                                                            fprintf(stderr, "main:proceso54:fork");
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 2);
                                                            switch (pidHijo[0] = fork()) { // Proceso 56
                                                                case -1:
                                                                    fprintf(stderr, "main:proceso56:fork");
                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                    return 9;
                                                                    break;
                                                                case 0:
                                                                    pidYo=getpid();
                                                                    escribir_pid(pidYo, 4);
                                                                    switch (pidHijo[0] = fork()) { // Proceso 57
                                                                        case -1:
                                                                            fprintf(stderr, "main:proceso57:fork");
                                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                                            return 9;
                                                                            break;
                                                                        case 0:
                                                                            switch (pidHijo[0] = fork()) { // Proceso 58
                                                                                case -1:
                                                                                    fprintf(stderr, "main:proceso58:fork");
                                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                                    return 9;
                                                                                    break;
                                                                                case 0:
                                                                                    pidHijo[0] = -1;
                                                                                    pidHijo[1] = -1;
                                                                                    pidYo=getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pidYo);
                                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                                    pause();
                                                                                    exit(0);
                                                                            }
                                                                            pidHijo[1] = -1;
                                                                            pidYo=getpid();
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pidYo);
                                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                                            pause();
                                                                            exit(0);
                                                                            break;
                                                                    }
                                                                    pidHijo[1] = -1;
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pidYo);
                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                    pause();
                                                                    exit(0);
                                                                    break;
                                                            }
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pidYo);
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 42(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 43
                                case -1:
                                    fprintf(stderr, "main:proceso43:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return 7;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 47
                                        case -1:
                                            fprintf(stderr, "main:proceso47:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 51
                                                case -1:
                                                    fprintf(stderr, "main:proceso51:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 0);
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    fprintf(stdout, "Soy el proceso 51(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 47(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 43(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 40(pid=%d)\n", pidYo);
                            fflush(stdout); // Forzar el vaciado del búfer
                            pause();
                            exit(0);
                            break;
                    }
                    switch (pidHijo[1] = fork()) { // Proceso 41
                        case -1:
                            fprintf(stderr, "main:proceso41:fork");
                            fflush(stdout); // Forzar el vaciado del búfer
                            return 5;
                            break;
                        case 0:
                            switch (pidHijo[0] = fork()) { // Proceso 44
                                case -1:
                                    fprintf(stderr, "main:proceso44:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return 6;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 48
                                        case -1:
                                            fprintf(stderr, "main:proceso48:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 52
                                                case -1:
                                                    fprintf(stderr, "main:proceso52:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return 9;
                                                    break;
                                                case 0:
                                                    // escribir_pid(pidYo, 2);
                                                    switch (pidHijo[0] = fork()) { // Proceso 55
                                                        case -1:
                                                            fprintf(stderr, "main:proceso55:fork");
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(pidYo, 3);
                                                            pidHijo[0] = -1;
                                                            pidHijo[1] = -1;
                                                            fprintf(stdout, "Soy el proceso 55(pid=%d)\n", pidYo);
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 52(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 48(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 44(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            switch (pidHijo[1] = fork()) { // Proceso 45
                                case -1:
                                    fprintf(stderr, "main:proceso45:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return 7;
                                    break;
                                case 0:
                                    switch (pidHijo[0] = fork()) { // Proceso 49
                                        case -1:
                                            fprintf(stderr, "main:proceso49:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo[0] = fork()) { // Proceso 53
                                                case -1:
                                                    fprintf(stderr, "main:proceso53:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(pidYo, 1);
                                                    pidHijo[0] = -1;
                                                    pidHijo[1] = -1;
                                                    fprintf(stdout, "Soy el proceso 53(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            pidHijo[1] = -1;
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 49(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    pidHijo[1] = -1;
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 45(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 41(pid=%d)\n", pidYo);
                            fflush(stdout); // Forzar el vaciado del búfer
                            pause();
                            exit(0);
                            break;
                    }
                    pidYo=getpid();
                    fprintf(stdout, "Soy el proceso 39(pid=%d)\n", pidYo);
                    fflush(stdout); // Forzar el vaciado del búfer
                    pause();
                    exit(0);
                    break;
            }
            pidHijo[1] = -1;
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pidYo);
            fflush(stdout); // Forzar el vaciado del búfer
            pause();
            exit(0);
            break;
        default:
            pidHijo[1] = -1;
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 37(pid=%d)\n", pidYo);
            fflush(stdout); // Forzar el vaciado del búfer
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
        fprintf(stderr, "Error al establecer el manejador de señales");
        fflush(stdout); // Forzar el vaciado del búfer
        exit(EXIT_FAILURE);
    }
}

void manejador(int sig) {
    pid_t pidYo;
    pidYo = getpid();
    printf("Proceso %d recibió la señal %d\n", pidYo, sig);
    if (sig == SIGTERM) {
        fprintf(stdout, "Proceso %d entra en señal\n", pidYo);
        fflush(stdout); // Forzar el vaciado del búfer
        if (pidYo == pidPrincipal) {
            return;
        }
        fprintf(stdout, "Proceso %d continua 1\n", pidYo);
        fflush(stdout); // Forzar el vaciado del búfer

        if (pids == MAP_FAILED) {
            fprintf(stderr, "Error en mmap");
            fflush(stdout); // Forzar el vaciado del búfer
            exit(EXIT_FAILURE);
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

        // Enviar señal SIGTERM a todos los hijos
        fprintf(stdout, "Proceso %d envía señal SIGTERM a %d y %d\n", pidYo, pidHijo[0], pidHijo[1]);
        fflush(stdout); // Forzar el vaciado del búfer
        if(pidHijo[0] != -1) {
            kill(pidHijo[0], SIGTERM);
            fprintf(stdout, "Proceso %d envía señal SIGTERM a %d\n", pidYo, pidHijo[0]);
            fflush(stdout); // Forzar el vaciado del búfer
        }

        if (pidHijo[1] != -1) {
            kill(pidHijo[1], SIGTERM);
            fprintf(stdout, "Proceso %d envía señal SIGTERM a %d\n", pidYo, pidHijo[1]);
            fflush(stdout); // Forzar el vaciado del búfer
        }

        if(pidHijo[0] != -1) {
            waitpid(pidHijo[0], NULL, 0);
        }
        if (pidHijo[1] != -1) {
            waitpid(pidHijo[1], NULL, 0);
        }
        exit(0); // Terminar el proceso
    }
}

void escribir_pid(pid_t pid, int index) {
    fprintf(stdout, "Proceso %d entra en escribir pid en %d\n", pid, index);
    fflush(stdout); // Forzar el vaciado del búfer
    pids[index] = pid;
    msync((void*)pids, NUM_PROCESOS * PID_SIZE, MS_SYNC); // Sincronizar los cambios con el archivo
}

pid_t leer_pid(int index) {
    fprintf(stdout, "Proceso entra en leer pid\n");
    fflush(stdout); // Forzar el vaciado del búfer
    fprintf(stdout, "Proceso lee pid %d\n", pids[index]);
    fflush(stdout); // Forzar el vaciado del búfer
    return pids[index];
}

void proyectar_archivo() {
    file=open(PID_FILE, O_RDWR);

    if (file == -1) {
        fprintf(stderr, "Error al abrir el archivo");
        fflush(stdout); // Forzar el vaciado del búfer
        exit(EXIT_FAILURE);
    }

    // Desplazar el puntero del archivo para que entren 7 PIDs
    if (lseek(file, NUM_PROCESOS * PID_SIZE - 1, SEEK_SET) == -1) {
        fprintf(stderr, "Error en lseek");
        fflush(stdout); // Forzar el vaciado del búfer
        close(file);
        exit(EXIT_FAILURE);
    }

    // Escribir un byte vacío para extender el archivo
    if (write(file, "", 1) != 1) {
        fprintf(stderr, "Error en write");
        fflush(stdout); // Forzar el vaciado del búfer
        close(file);
        exit(EXIT_FAILURE);
    }

    
    pids= (pid_t *) mmap(NULL, NUM_PROCESOS * PID_SIZE, PROT_WRITE, MAP_SHARED, file, 0);
    if (pids == MAP_FAILED) {
        fprintf(stderr, "Error en mmap");
        fflush(stdout); // Forzar el vaciado del búfer
        close(file);
        exit(EXIT_FAILURE);
    }
}

void desproyectar_archivo() {
    // Desmapear la memoria y cerrar el archivo
    if (munmap((void*)pids, NUM_PROCESOS * PID_SIZE) == -1) {
        fprintf(stderr, "Error en munmap");
        fflush(stdout); // Forzar el vaciado del búfer
    }

    close(file);
}
