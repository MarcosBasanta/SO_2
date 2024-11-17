#define _HPUX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int crea_jerarquia();
void espera();

int main() {
    crea_jerarquia();
    return 0;
}

int crea_jerarquia() {
    pid_t pid;
    switch(fork()) { // Proceso 38
        case -1:
            perror("main:proceso38:fork");
            return 2;
            break;
        case 0:
            switch (fork()) { // Proceso 39
                case -1:
                    perror("main:proceso39:fork");
                    return 3;
                    break;
                case 0:
                    switch(fork()) { // Proceso 40
                        case -1:
                            perror("main:proceso40:fork");
                            return 4;
                            break;
                        case 0:
                            switch (fork()) { // Proceso 42
                                case -1:
                                    perror("main:proceso42:fork");
                                    return 6;
                                    break;
                                case 0:
                                    switch (fork()) { // Proceso 46
                                        case -1:
                                            perror("main:proceso46:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (fork()) { // Proceso 50
                                                case -1:
                                                    perror("main:proceso50:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    switch (fork()) { // Proceso 54
                                                        case -1:
                                                            perror("main:proceso54:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            switch (fork()) { // Proceso 56
                                                                case -1:
                                                                    perror("main:proceso56:fork");
                                                                    return 9;
                                                                    break;
                                                                case 0:
                                                                    switch (fork()) { // Proceso 57
                                                                        case -1:
                                                                            perror("main:proceso57:fork");
                                                                            return 9;
                                                                            break;
                                                                        case 0:
                                                                            switch (fork()) { // Proceso 58
                                                                                case -1:
                                                                                    perror("main:proceso58:fork");
                                                                                    return 9;
                                                                                    break;
                                                                                case 0:
                                                                                    pid=getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pid);
                                                                                    espera();
                                                                            }
                                                                            pid=getpid();
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pid);
                                                                            espera();
                                                                            break;
                                                                    }
                                                                    pid=getpid();
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pid);
                                                                    espera();
                                                                    break;
                                                            }
                                                            pid=getpid();
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pid);
                                                            espera();
                                                            break;
                                                    }
                                                    pid=getpid();
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pid);
                                                    espera();
                                                    break;
                                            }
                                            pid=getpid();
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pid);
                                            espera();
                                            break;
                                    }
                                    pid=getpid();
                                    fprintf(stdout, "Soy el proceso 42(pid=%d)\n", pid);
                                    espera();
                                    break;
                            }
                            switch (fork()) { // Proceso 43
                                case -1:
                                    perror("main:proceso43:fork");
                                    return 7;
                                    break;
                                case 0:
                                    switch (fork()) { // Proceso 47
                                        case -1:
                                            perror("main:proceso47:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (fork()) { // Proceso 51
                                                case -1:
                                                    perror("main:proceso51:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pid=getpid();
                                                    fprintf(stdout, "Soy el proceso 51(pid=%d)\n", pid);
                                                    espera();
                                                    break;
                                            }
                                            pid=getpid();
                                            fprintf(stdout, "Soy el proceso 47(pid=%d)\n", pid);
                                            espera();
                                            break;
                                    }
                                    pid=getpid();
                                    fprintf(stdout, "Soy el proceso 43(pid=%d)\n", pid);
                                    espera();
                                    break;
                            }
                            pid=getpid();
                            fprintf(stdout, "Soy el proceso 40(pid=%d)\n", pid);
                            espera();
                            break;
                    }
                    switch (fork()) { // Proceso 41
                        case -1:
                            perror("main:proceso41:fork");
                            return 5;
                            break;
                        case 0:
                            switch (fork()) { // Proceso 44
                                case -1:
                                    perror("main:proceso44:fork");
                                    return 6;
                                    break;
                                case 0:
                                    switch (fork()) { // Proceso 48
                                        case -1:
                                            perror("main:proceso48:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (fork()) { // Proceso 52
                                                case -1:
                                                    perror("main:proceso52:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    switch (fork()) { // Proceso 55
                                                        case -1:
                                                            perror("main:proceso55:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pid=getpid();
                                                            fprintf(stdout, "Soy el proceso 55(pid=%d)\n", pid);
                                                            espera();
                                                            break;
                                                    }
                                                    pid=getpid();
                                                    fprintf(stdout, "Soy el proceso 52(pid=%d)\n", pid);
                                                    espera();
                                                    break;
                                            }
                                            pid=getpid();
                                            fprintf(stdout, "Soy el proceso 48(pid=%d)\n", pid);
                                            espera();
                                            break;
                                    }
                                    pid=getpid();
                                    fprintf(stdout, "Soy el proceso 44(pid=%d)\n", pid);
                                    espera();
                                    break;
                            }
                            switch (fork()) { // Proceso 45
                                case -1:
                                    perror("main:proceso45:fork");
                                    return 7;
                                    break;
                                case 0:
                                    switch (fork()) { // Proceso 49
                                        case -1:
                                            perror("main:proceso49:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (fork()) { // Proceso 53
                                                case -1:
                                                    perror("main:proceso53:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pid=getpid();
                                                    fprintf(stdout, "Soy el proceso 53(pid=%d)\n", pid);
                                                    espera();
                                                    break;
                                            }
                                            pid=getpid();
                                            fprintf(stdout, "Soy el proceso 49(pid=%d)\n", pid);
                                            espera();
                                            break;
                                    }
                                    pid=getpid();
                                    fprintf(stdout, "Soy el proceso 45(pid=%d)\n", pid);
                                    espera();
                                    break;
                            }
                            pid=getpid();
                            fprintf(stdout, "Soy el proceso 41(pid=%d)\n", pid);
                            espera();
                            break;
                    }
                    pid=getpid();
                    fprintf(stdout, "Soy el proceso 39(pid=%d)\n", pid);
                    espera();
                    break;
            }
            pid=getpid();
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pid);
            espera();
            break;
        default:
            pid=getpid();
            if(pid==-1) {
                perror("main:getpid");
                exit(1);
            }
            fprintf(stdout, "Soy el proceso 37(pid=%d)\n", pid);
            system("pstree | grep 'main'");
            break;
    }
    return 0;
}

void espera() {
    pid_t pid;

    sleep(40);

    pid=getpid();
    if(pid==-1) {
        perror("main:getpid");
        exit(1);
    }
    exit(0);
}