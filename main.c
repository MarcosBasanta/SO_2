#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_process(int num) {
    pid_t pid = fork();
    switch (pid) {
        case 0:
            // Proceso hijo
            printf("Proceso %d creado\n", num);
            exit(0);
            break;
        case -1:
            // Error al crear el proceso
            perror("fork");
            exit(1);
            break;
        default:
            // Proceso padre
            waitpid(pid, NULL, 0); // Espera a que el proceso hijo termine
            break;
    }
}

void create_hierarchy() {
    create_process(37);
    if (fork() == 0) {
        create_process(38);
        if (fork() == 0) {
            create_process(39);
            if (fork() == 0) {
                create_process(40);
                if (fork() == 0) {
                    create_process(42);
                    if (fork() == 0) {
                        create_process(46);
                        create_process(50);
                        create_process(54);
                        create_process(56);
                        create_process(57);
                        create_process(58);
                    }
                } else {
                    create_process(43);
                    if (fork() == 0) {
                        create_process(47);
                        create_process(51);
                    }
                }
            } else {
                create_process(41);
                if (fork() == 0) {
                    create_process(44);
                    if (fork() == 0) {
                        create_process(48);
                        create_process(52);
                        create_process(55);
                    }
                } else {
                    create_process(45);
                    if (fork() == 0) {
                        create_process(49);
                        create_process(53);
                    }
                }
            }
        }
    }
}

int main() {
    create_hierarchy();
    return 0;
}