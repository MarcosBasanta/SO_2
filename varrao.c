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
#define SHM_NAME "/shm_pids"
#define SHM_SIZE (NUM_PROCESOS * sizeof(pid_t))

int shm_fd;
pid_t *shm_pids;

void crear_memoria_compartida();
void eliminar_memoria_compartida();
pid_t crea_jerarquia();
void configurar_manejador();
void manejador(int sig);
void escribir_pid(pid_t pid, int index);
pid_t leer_pid(int index);
void imprimir_arbol(const char *mensaje);

int main() {
    crear_memoria_compartida();
    configurar_manejador();

    pid_t pidHijo = crea_jerarquia();
    imprimir_arbol("Árbol de procesos al inicio:");
    pause();
    waitpid(pidHijo, NULL, 0);

    imprimir_arbol("Árbol de procesos al final:");
    eliminar_memoria_compartida();

    return 0;
}

void crear_memoria_compartida() {
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Error al crear la memoria compartida");
        exit(EXIT_FAILURE);
    }
    if (ftruncate(shm_fd, SHM_SIZE) == -1) {
        perror("Error al ajustar el tamaño de la memoria compartida");
        exit(EXIT_FAILURE);
    }
    shm_pids = (pid_t *)mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_pids == MAP_FAILED) {
        perror("Error al mapear la memoria compartida");
        exit(EXIT_FAILURE);
    }
}

void eliminar_memoria_compartida() {
    if (munmap((void *)shm_pids, SHM_SIZE) == -1) {
        perror("Error al desmapear la memoria compartida");
    }
    if (shm_unlink(SHM_NAME) == -1) {
        perror("Error al eliminar la memoria compartida");
    } else {
        printf("Memoria compartida eliminada correctamente.\n");
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

        // Encontrar el índice del proceso actual en la memoria compartida
        int i;
        for (i = 0; i < NUM_PROCESOS; i++) {
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

void imprimir_arbol(const char *mensaje) {
    printf("%s\n", mensaje);
    system("pstree -p");
}