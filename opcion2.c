// Instrucciones de uso en el README.md
// Falta limpiar el codigo, salidas de comprobacion, printf, etc
// Podriamos incluir un struct para almacenar los datos de los procesos
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
#define NUM_PROCESOS 22
#define PROCESO_INICIO 37

typedef struct {
    int numero;
    pid_t pid;
} proceso;

const PID_SIZE = sizeof(proceso) * NUM_PROCESOS;
const FILE_SIZE = PID_SIZE * NUM_PROCESOS;

proceso *pids;

void crea_jerarquia();
void configurar_manejador();
void manejador(int sig);
void escribir_pid(int num, pid_t pid);
pid_t leer_pid(int index);
int obtenerNum(pid_t pid);
void proyectar_archivo(int file);
void desproyectar_archivo(int file);

int main() {
    int i, file;
    pid_t pidYo;

    proyectar_archivo(file);
    configurar_manejador();

    escribir_pid(37, getpid());
    crea_jerarquia();

    pause();

    pidYo = getpid();
    if (pidYo == leer_pid(58)) {
        fprintf(stdout, "Soy el ultimo proceso (pid=%d)\n", pidYo);
        waitpid(leer_pid(50), NULL, 0);
        waitpid(leer_pid(52), NULL, 0);
        waitpid(leer_pid(54), NULL, 0);
        waitpid(leer_pid(57), NULL, 0);

        desproyectar_archivo(file);

        exit(0);
    }

    return 0;
}

void crea_jerarquia() {
    pid_t pidYo;
    switch(fork()) { // Proceso 38
        case -1:
            fprintf(stderr, "main:proceso38:fork");
            fflush(stdout); // Forzar el vaciado del búfer
            return;
            break;
        case 0:
            pidYo=getpid();
            escribir_pid(38, pidYo);
            switch (fork()) { // Proceso 39
                case -1:
                    fprintf(stderr, "main:proceso39:fork");
                    fflush(stdout); // Forzar el vaciado del búfer
                    return;
                    break;
                case 0:
                    pidYo=getpid();
                    escribir_pid(39, pidYo);
                    switch(fork()) { // Proceso 40
                        case -1:
                            fprintf(stderr, "main:proceso40:fork");
                            fflush(stdout); // Forzar el vaciado del búfer
                            return;
                            break;
                        case 0:
                            pidYo=getpid();
                            escribir_pid(40, pidYo);
                            switch (fork()) { // Proceso 42
                                case -1:
                                    fprintf(stderr, "main:proceso42:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    pidYo=getpid();
                                    escribir_pid(42, pidYo);
                                    switch (fork()) { // Proceso 46
                                        case -1:
                                            fprintf(stderr, "main:proceso46:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            pidYo=getpid();
                                            escribir_pid(46, pidYo);
                                            switch (fork()) { // Proceso 50
                                                case -1:
                                                    fprintf(stderr, "main:proceso50:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(50, pidYo);
                                                    switch (fork()) { // Proceso 54
                                                        case -1:
                                                            fprintf(stderr, "main:proceso54:fork");
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            return;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(54, pidYo);
                                                            switch (fork()) { // Proceso 56
                                                                case -1:
                                                                    fprintf(stderr, "main:proceso56:fork");
                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                    return;
                                                                    break;
                                                                case 0:
                                                                    pidYo=getpid();
                                                                    escribir_pid(56, pidYo);
                                                                    switch (fork()) { // Proceso 57
                                                                        case -1:
                                                                            fprintf(stderr, "main:proceso57:fork");
                                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                                            return;
                                                                            break;
                                                                        case 0:
                                                                            pidYo=getpid();
                                                                            escribir_pid(57, pidYo);
                                                                            switch (fork()) { // Proceso 58
                                                                                case -1:
                                                                                    fprintf(stderr, "main:proceso58:fork");
                                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                                    return;
                                                                                    break;
                                                                                case 0:
                                                                                    pidYo=getpid();
                                                                                    escribir_pid(58, pidYo);
                                                        
                                                                                    
                                                                                    pidYo=getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pidYo);
                                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                                    pause();
                                                                                    exit(0);
                                                                            }
                                                                            
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pidYo);
                                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                                            pause();
                                                                            exit(0);
                                                                            break;
                                                                    }
                                                                    
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pidYo);
                                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                                    pause();
                                                                    exit(0);
                                                                    break;
                                                            }
                                
                                                            
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pidYo);
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                        
                                                    
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    
                                    fprintf(stdout, "Soy el proceso 42(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            switch (fork()) { // Proceso 43
                                case -1:
                                    fprintf(stderr, "main:proceso43:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    pidYo=getpid();
                                    escribir_pid(43, pidYo);
                                    switch (fork()) { // Proceso 47
                                        case -1:
                                            fprintf(stderr, "main:proceso47:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            pidYo=getpid();
                                            escribir_pid(47, pidYo);
                                            switch (fork()) { // Proceso 51
                                                case -1:
                                                    fprintf(stderr, "main:proceso51:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(51, pidYo);
                        
                                                    
                                                    fprintf(stdout, "Soy el proceso 51(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            
                                            fprintf(stdout, "Soy el proceso 47(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    
                                    fprintf(stdout, "Soy el proceso 43(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            fprintf(stdout, "Soy el proceso 40(pid=%d)\n", pidYo);
                            fflush(stdout); // Forzar el vaciado del búfer
                            pause();
                            exit(0);
                            break;
                    }
                    switch (fork()) { // Proceso 41
                        case -1:
                            fprintf(stderr, "main:proceso41:fork");
                            fflush(stdout); // Forzar el vaciado del búfer
                            return;
                            break;
                        case 0:
                            pidYo=getpid();
                            escribir_pid(41, pidYo);
                            switch (fork()) { // Proceso 44
                                case -1:
                                    fprintf(stderr, "main:proceso44:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    pidYo=getpid();
                                    escribir_pid(44, pidYo);
                                    switch (fork()) { // Proceso 48
                                        case -1:
                                            fprintf(stderr, "main:proceso48:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            pidYo=getpid();
                                            escribir_pid(48, pidYo);
                                            switch (fork()) { // Proceso 52
                                                case -1:
                                                    fprintf(stderr, "main:proceso52:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(52, pidYo);
                                                    switch (fork()) { // Proceso 55
                                                        case -1:
                                                            fprintf(stderr, "main:proceso55:fork");
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            return;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            escribir_pid(55, pidYo);
                                
                                                            
                                                            fprintf(stdout, "Soy el proceso 55(pid=%d)\n", pidYo);
                                                            fflush(stdout); // Forzar el vaciado del búfer
                                                            pause();
                                                            exit(0);
                                                            break;
                                                    }
                        
                                                    
                                                    fprintf(stdout, "Soy el proceso 52(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            
                                            fprintf(stdout, "Soy el proceso 48(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    
                                    fprintf(stdout, "Soy el proceso 44(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            switch (fork()) { // Proceso 45
                                case -1:
                                    fprintf(stderr, "main:proceso45:fork");
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    return;
                                    break;
                                case 0:
                                    pidYo=getpid();
                                    escribir_pid(45, pidYo);
                                    switch (fork()) { // Proceso 49
                                        case -1:
                                            fprintf(stderr, "main:proceso49:fork");
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            return;
                                            break;
                                        case 0:
                                            pidYo=getpid();
                                            escribir_pid(49, pidYo);
                                            switch (fork()) { // Proceso 53
                                                case -1:
                                                    fprintf(stderr, "main:proceso53:fork");
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    return;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    escribir_pid(53, pidYo);
                        
                                                    
                                                    fprintf(stdout, "Soy el proceso 53(pid=%d)\n", pidYo);
                                                    fflush(stdout); // Forzar el vaciado del búfer
                                                    pause();
                                                    exit(0);
                                                    break;
                                            }
                                            
                                            fprintf(stdout, "Soy el proceso 49(pid=%d)\n", pidYo);
                                            fflush(stdout); // Forzar el vaciado del búfer
                                            pause();
                                            exit(0);
                                            break;
                                    }
                                    
                                    fprintf(stdout, "Soy el proceso 45(pid=%d)\n", pidYo);
                                    fflush(stdout); // Forzar el vaciado del búfer
                                    pause();
                                    exit(0);
                                    break;
                            }
                            fprintf(stdout, "Soy el proceso 41(pid=%d)\n", pidYo);
                            fflush(stdout); // Forzar el vaciado del búfer
                            pause();
                            exit(0);
                            break;
                    }
                    fprintf(stdout, "Soy el proceso 39(pid=%d)\n", pidYo);
                    fflush(stdout); // Forzar el vaciado del búfer
                    pause();
                    exit(0);
                    break;
            }
            
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pidYo);
            fflush(stdout); // Forzar el vaciado del búfer
            pause();
            exit(0);
            break;
        default:
            
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
    pid_t pidYo, pidPadre;
    pid_t pidHijo[2] = {-1, -1};
    int numProceso;
    pidYo = getpid();
    numProceso = obtenerNum(pidYo);
    fprintf(stdout, "Proceso %d recibió la señal %d\n", pidYo, sig);
    if (sig == SIGTERM) {

        switch (numProceso) {
            case 37:
                pidHijo[0] = leer_pid(numProceso+1);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                break;
            case 38:
                pidPadre = leer_pid(numProceso-1);
                pidHijo[0] = leer_pid(numProceso+1);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 39:
                pidPadre = leer_pid(numProceso-1);
                pidHijo[0] = leer_pid(40);
                pidHijo[1] = leer_pid(41);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                kill(pidHijo[1], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[1]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 40:
                pidPadre = leer_pid(numProceso-1);
                pidHijo[0] = leer_pid(42);
                pidHijo[1] = leer_pid(43);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                kill(pidHijo[1], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[1]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 41:
                pidPadre = leer_pid(numProceso-2);
                pidHijo[0] = leer_pid(44);
                pidHijo[1] = leer_pid(45);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                kill(pidHijo[1], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[1]);
                fflush(stdout); // Forzar el vaciado del búfer
                break;
            case 42:
                pidPadre = leer_pid(40);
                pidHijo[0] = leer_pid(numProceso+4);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 43:
                pidPadre = leer_pid(40);
                pidHijo[0] = leer_pid(numProceso+4);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                break;
            case 44:
                pidPadre = leer_pid(41);
                pidHijo[0] = leer_pid(numProceso+4);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 45:
                pidPadre = leer_pid(41);
                pidHijo[0] = leer_pid(numProceso+4);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                break;
            case 46:
            case 47:
            case 48:
            case 49:
                pidPadre = leer_pid(numProceso-4);
                pidHijo[0] = leer_pid(numProceso+4);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 50:
                pidPadre = leer_pid(numProceso-4);
                waitpid(pidPadre, NULL, 0);
                break;
            case 51:
                pidPadre = leer_pid(numProceso-4);
                pidHijo[0] = leer_pid(54);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 52:
                pidPadre = leer_pid(numProceso-4);
                waitpid(pidPadre, NULL, 0);
                break;
            case 53:
                pidPadre = leer_pid(numProceso-4);
                pidHijo[0] = leer_pid(55);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 54:
                pidPadre = leer_pid(numProceso-3);
                waitpid(pidPadre, NULL, 0);
                break;
            case 55:
                pidPadre = leer_pid(numProceso-2);
                pidHijo[0] = leer_pid(56);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 56:
            case 57:
                pidPadre = leer_pid(numProceso-1);
                pidHijo[0] = leer_pid(numProceso+1);
                kill(pidHijo[0], SIGTERM);
                fprintf(stdout, "Soy el proceso %d y envio mi señal a %d\n", pidYo, pidHijo[0]);
                fflush(stdout); // Forzar el vaciado del búfer
                waitpid(pidPadre, NULL, 0);
                break;
            case 58:
                return;
                break;

            default:
                fprintf(stderr, "Error: Proceso %d no encontrado\n", numProceso);
                fflush(stdout);
                break;
        }
        exit(0);
    }
}

void escribir_pid(int num, pid_t pid) {
    int index = num - PROCESO_INICIO;
    pids[index].numero = num;
    pids[index].pid = pid;
}

pid_t leer_pid(int num) {
    int index = num - PROCESO_INICIO;
    return pids[index].pid;
}

int obtenerNum(pid_t pid) {
    int i;
    for (i = 0; i < NUM_PROCESOS; i++) {
        if (pids[i].pid == pid) {
            return pids[i].numero;
        }
    }
    return -1;
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
    pids = (proceso *)mmap(0, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
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
