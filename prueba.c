#define _HPUX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>

#define NUM_PROCESOS 22
#define FILE_NAME "pids.dat"
#define FILE_SIZE (NUM_PROCESOS * sizeof(pid_t))

pid_t *pids;

void crear_archivo();
void eliminar_archivo();
pid_t crea_jerarquia();
void configurar_manejador();
void manejador(int sig);
void escribir_pid(pid_t pid, int index);
pid_t leer_pid(int index);
void imprimir_arbol(const char *mensaje);

int main() {
    crear_archivo();
    configurar_manejador();

    pid_t pidHijo = crea_jerarquia();
    imprimir_arbol("Árbol de procesos al inicio:");
    pause();
    waitpid(pidHijo, NULL, 0);

    imprimir_arbol("Árbol de procesos al final:");
    eliminar_archivo();

    return 0;
}

void crear_archivo() {
    int fd = open(FILE_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error al crear el archivo");
        exit(EXIT_FAILURE);
    }
    if (ftruncate(fd, FILE_SIZE) == -1) {
        perror("Error al ajustar el tamaño del archivo");
        exit(EXIT_FAILURE);
    }
    pids = (pid_t *)mmap(0, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (pids == MAP_FAILED) {
        perror("Error al mapear el archivo");
        exit(EXIT_FAILURE);
    }
    close(fd);
}

void eliminar_archivo() {
    if (munmap((void *)pids, FILE_SIZE) == -1) {
        perror("Error al desmapear el archivo");
    }
    if (remove(FILE_NAME) == -1) {
        perror("Error al eliminar el archivo");
    } else {
        printf("Archivo eliminado correctamente.\n");
    }
}

pid_t crea_jerarquia() {
    pid_t pidHijo[NUM_PROCESOS];
    pid_t pidYo;
    int index = 0;

    // Proceso 38
    if ((pidHijo[index] = fork()) == 0) {
        escribir_pid(getpid(), index);
        printf("Proceso 38 creado y escrito en memoria\n");
        index++;
        // Proceso 39
        if ((pidHijo[index] = fork()) == 0) {
            escribir_pid(getpid(), index);
            printf("Proceso 39 creado y escrito en memoria\n");
            index++;
            // Proceso 40
            if ((pidHijo[index] = fork()) == 0) {
                escribir_pid(getpid(), index);
                printf("Proceso 40 creado y escrito en memoria\n");
                index++;
                // Proceso 43
                if ((pidHijo[index] = fork()) == 0) {
                    escribir_pid(getpid(), index);
                    printf("Proceso 43 creado y escrito en memoria\n");
                    index++;
                    // Proceso 47
                    if ((pidHijo[index] = fork()) == 0) {
                        escribir_pid(getpid(), index);
                        printf("Proceso 47 creado y escrito en memoria\n");
                        index++;
                        // Proceso 51
                        if ((pidHijo[index] = fork()) == 0) {
                            escribir_pid(getpid(), index);
                            printf("Proceso 51 creado y escrito en memoria\n");
                            index++;
                            pause();
                            exit(0);
                        }
                        pause();
                        exit(0);
                    }
                    pause();
                    exit(0);
                }
                // Proceso 42
                if ((pidHijo[index] = fork()) == 0) {
                    escribir_pid(getpid(), index);
                    printf("Proceso 42 creado y escrito en memoria\n");
                    index++;
                    // Proceso 46
                    if ((pidHijo[index] = fork()) == 0) {
                        escribir_pid(getpid(), index);
                        printf("Proceso 46 creado y escrito en memoria\n");
                        index++;
                        // Proceso 50
                        if ((pidHijo[index] = fork()) == 0) {
                            escribir_pid(getpid(), index);
                            printf("Proceso 50 creado y escrito en memoria\n");
                            index++;
                            // Proceso 54
                            if ((pidHijo[index] = fork()) == 0) {
                                escribir_pid(getpid(), index);
                                printf("Proceso 54 creado y escrito en memoria\n");
                                index++;
                                // Proceso 56
                                if ((pidHijo[index] = fork()) == 0) {
                                    escribir_pid(getpid(), index);
                                    printf("Proceso 56 creado y escrito en memoria\n");
                                    index++;
                                    // Proceso 57
                                    if ((pidHijo[index] = fork()) == 0) {
                                        escribir_pid(getpid(), index);
                                        printf("Proceso 57 creado y escrito en memoria\n");
                                        index++;
                                        // Proceso 58
                                        if ((pidHijo[index] = fork()) == 0) {
                                            escribir_pid(getpid(), index);
                                            printf("Proceso 58 creado y escrito en memoria\n");
                                            index++;
                                            pause();
                                            exit(0);
                                        }
                                        pause();
                                        exit(0);
                                    }
                                    pause();
                                    exit(0);
                                }
                                pause();
                                exit(0);
                            }
                            pause();
                            exit(0);
                        }
                        pause();
                        exit(0);
                    }
                    pause();
                    exit(0);
                }
                pause();
                exit(0);
            }
            // Proceso 41
            if ((pidHijo[index] = fork()) == 0) {
                escribir_pid(getpid(), index);
                printf("Proceso 41 creado y escrito en memoria\n");
                index++;
                // Proceso 44
                if ((pidHijo[index] = fork()) == 0) {
                    escribir_pid(getpid(), index);
                    printf("Proceso 44 creado y escrito en memoria\n");
                    index++;
                    // Proceso 48
                    if ((pidHijo[index] = fork()) == 0) {
                        escribir_pid(getpid(), index);
                        printf("Proceso 48 creado y escrito en memoria\n");
                        index++;
                        // Proceso 52
                        if ((pidHijo[index] = fork()) == 0) {
                            escribir_pid(getpid(), index);
                            printf("Proceso 52 creado y escrito en memoria\n");
                            index++;
                            // Proceso 55
                            if ((pidHijo[index] = fork()) == 0) {
                                escribir_pid(getpid(), index);
                                printf("Proceso 55 creado y escrito en memoria\n");
                                index++;
                                pause();
                                exit(0);
                            }
                            pause();
                            exit(0);
                        }
                        pause();
                        exit(0);
                    }
                    pause();
                    exit(0);
                }
                // Proceso 45
                if ((pidHijo[index] = fork()) == 0) {
                    escribir_pid(getpid(), index);
                    printf("Proceso 45 creado y escrito en memoria\n");
                    index++;
                    // Proceso 49
                    if ((pidHijo[index] = fork()) == 0) {
                        escribir_pid(getpid(), index);
                        printf("Proceso 49 creado y escrito en memoria\n");
                        index++;
                        // Proceso 53
                        if ((pidHijo[index] = fork()) == 0) {
                            escribir_pid(getpid(), index);
                            printf("Proceso 53 creado y escrito en memoria\n");
                            index++;
                            pause();
                            exit(0);
                        }
                        pause();
                        exit(0);
                    }
                    pause();
                    exit(0);
                }
                pause();
                exit(0);
            }
            pause();
            exit(0);
        }
        pause();
        exit(0);
    }
    escribir_pid(getpid(), index);
    printf("Proceso 37 (main) creado y escrito en memoria\n");
    index++;
    return pidHijo[0];
}

void configurar_manejador() {
    struct sigaction sa;
    sa.sa_handler = manejador;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error al establecer el manejador de señales");
        exit(EXIT_FAILURE);
    }
}

void manejador(int sig) {
    printf("Proceso %d recibió la señal %d\n", getpid(), sig);
    if (sig == SIGTERM) {
        pid_t pidYo = getpid();
        int index = -1;

        // Encontrar el índice del proceso actual en el archivo mapeado
        for (int i = 0; i < NUM_PROCESOS; i++) {
            if (pids[i] == pidYo) {
                index = i;
                break;
            }
        }

        // Verificar si se encontró el índice
        if (index == -1) {
            printf("Proceso %d no encontró su índice en el archivo mapeado\n", pidYo);
        } else {
            // Imprimir mensaje antes de enviar la señal al siguiente proceso
            if (index + 1 < NUM_PROCESOS) {
                printf("Proceso %d enviando señal SIGTERM al proceso %d\n", pidYo, pids[index + 1]);
                kill(pids[index + 1], SIGTERM);
                waitpid(pids[index + 1], NULL, 0);
            }
        }

        // Imprimir mensaje antes de que el proceso termine
        printf("Proceso %d terminando\n", pidYo);
        exit(0);
    }
}

void escribir_pid(pid_t pid, int index) {
    pids[index] = pid;
    printf("Se escribió el PID %d en la posición %d\n", pid, index);
}

pid_t leer_pid(int index) {
    return pids[index];
}

void imprimir_arbol(const char *mensaje) {
    printf("%s\n", mensaje);
    system("pstree -p");
}

int crea_jerarquia();
void configurar_manejador();
void manejador(int sig);
void escribir_pid(pid_t pid, int index);
pid_t leer_pid(int index);
void crear_memoria_compartida();
void eliminar_memoria_compartida();

int main() {
    crear_memoria_compartida();
    configurar_manejador();

    pid_t pidHijo = crea_jerarquia();
    system("pstree | grep 'main'");
    pause();
    waitpid(pidHijo, NULL, 0);

    eliminar_memoria_compartida();

    return 0;
}

pid_t crea_jerarquia() {
    pid_t pidHijo[2];
    pid_t pidYo;
    switch(pidHijo[0] = fork()) {
        case -1:
            perror("main:proceso38:fork");
            return 2;
        case 0:
            pidYo = getppid();
            escribir_pid(pidYo, 0);
             pidYo = getpid();
            switch (pidHijo[0] = fork()) {
                case -1:
                    perror("main:proceso39:fork");
                    return 3;
                case 0:
                    pidYo = getppid();
                    escribir_pid(pidYo, 1);
                     pidYo = getpid();
                    switch(pidHijo[0] = fork()) {
                        case -1:
                            perror("main:proceso40:fork");
                            return 4;
                        case 0:
                            pidYo = getppid();
                            escribir_pid(pidYo, 2);
                             pidYo = getpid();
                            switch (pidHijo[0] = fork()) {
                                case -1:
                                    perror("main:proceso42:fork");
                                    return 6;
                                case 0:
                                    pidYo = getppid();
                                    escribir_pid(pidYo, 3);
                                     pidYo = getpid();
                                    switch (pidHijo[0] = fork()) {
                                        case -1:
                                            perror("main:proceso46:fork");
                                            return 8;
                                        case 0:
                                            pidYo = getppid();
                                            escribir_pid(pidYo, 4);
                                             pidYo = getpid();
                                            switch (pidHijo[0] = fork()) {
                                                case -1:
                                                    perror("main:proceso50:fork");
                                                    return 9;
                                                case 0:
                                                    pidYo = getppid();
                                                    escribir_pid(pidYo, 5);
                                                     pidYo = getpid();
                                                    switch (pidHijo[0] = fork()) {
                                                        case -1:
                                                            perror("main:proceso54:fork");
                                                            return 9;
                                                        case 0:
                                                            pidYo = getppid();
                                                            escribir_pid(pidYo, 6);
                                                             pidYo = getpid();
                                                            switch (pidHijo[0] = fork()) {
                                                                case -1:
                                                                    perror("main:proceso56:fork");
                                                                    return 9;
                                                                case 0:
                                                                    pidYo = getppid();
                                                                    escribir_pid(pidYo, 7);
                                                                     pidYo = getpid();
                                                                    switch (pidHijo[0] = fork()) {
                                                                        case -1:
                                                                            perror("main:proceso57:fork");
                                                                            return 9;
                                                                        case 0:
                                                                            pidYo = getppid();
                                                                            escribir_pid(pidYo, 8);
                                                                             pidYo = getpid();
                                                                            switch (pidHijo[0] = fork()) {
                                                                                case -1:
                                                                                    perror("main:proceso58:fork");
                                                                                    return 9;
                                                                                case 0:
                                                                                    pidYo = getppid();
                                                                                    escribir_pid(pidYo, 9);
                                                                                     pidYo = getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pidYo);
                                                                                    pause();
                                                                                    exit(0);
                                                                            }
                                                                            pidYo = getpid();
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pidYo);
                                                                            pause();
                                                                            exit(0);
                                                                    }
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pidYo);
                                                                    pause();
                                                                    exit(0);
                                                            }
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pidYo);
                                                            pause();
                                                            exit(0);
                                                    }
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pidYo);
                                                    pause();
                                                    exit(0);
                                            }
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pidYo);
                                            pause();
                                            exit(0);
                                    }
                                    fprintf(stdout, "Soy el proceso 42(pid=%d)\n", pidYo);
                                    pause();
                                    exit(0);
                            }
                            fprintf(stdout, "Soy el proceso 40(pid=%d)\n", pidYo);
                            pause();
                            exit(0);
                    }
                    fprintf(stdout, "Soy el proceso 39(pid=%d)\n", pidYo);
                    pause();
                    exit(0);
            }
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pidYo);
            pause();
            exit(0);
    default:
        pidYo = getpid();
        fprintf(stdout, "Soy el proceso 37(pid=%d)\n", pidYo);
        break;
    }

    return pidHijo[0];
}

void configurar_manejador() {
    struct sigaction sa;
    sa.sa_handler = manejador;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("Error al establecer el manejador de señales");
        exit(EXIT_FAILURE);
    }
}

void manejador(int sig) {
    printf("Proceso %d recibió la señal %d\n", getpid(), sig);
    if (sig == SIGTERM) {
        pid_t pidYo = getpid();
        int index = -1;

        // Encontrar el índice del proceso actual en la memoria compartida
        for (int i = 0; i < NUM_PROCESOS; i++) {
            printf("Verificando índice %d: PID en memoria %d\n", i, shm_pids[i]);
            if (shm_pids[i] == pidYo) {
                index = i;
                break;
            }
        }

        // Verificar si se encontró el índice
        if (index == -1) {
            printf("Proceso %d no encontró su índice en la memoria compartida\n", pidYo);
        } else {
            // Imprimir mensaje antes de enviar la señal al siguiente proceso
            if (index + 1 < NUM_PROCESOS) {
                printf("Proceso %d enviando señal SIGTERM al proceso %d\n", pidYo, shm_pids[index + 1]);
                kill(shm_pids[index + 1], SIGTERM);
                waitpid(shm_pids[index + 1], NULL, 0);
            }
        }

        // Imprimir mensaje antes de que el proceso termine
        printf("Proceso %d terminando\n", pidYo);
        exit(0);
    }
}

void escribir_pid(pid_t pid, int index) {
    shm_pids[index] = pid;
    printf("Se escribió el PID %d en la posición %d\n", pid, index);
}

pid_t leer_pid(int index) {
    return shm_pids[index];
}