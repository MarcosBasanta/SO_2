#define _HPUX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int crea_jerarquia();

int main() {
    crea_jerarquia();
    return 0;
}

int crea_jerarquia() {
    pid_t pidHijo, pidYo;
    switch(pidHijo = fork()) { // Proceso 38
        case -1:
            perror("main:proceso38:fork");
            return 2;
            break;
        case 0:
            switch (pidHijo = fork()) { // Proceso 39
                case -1:
                    perror("main:proceso39:fork");
                    return 3;
                    break;
                case 0:
                    switch(pidHijo = fork()) { // Proceso 40
                        case -1:
                            perror("main:proceso40:fork");
                            return 4;
                            break;
                        case 0:
                            switch (pidHijo = fork()) { // Proceso 42
                                case -1:
                                    perror("main:proceso42:fork");
                                    return 6;
                                    break;
                                case 0:
                                    switch (pidHijo = fork()) { // Proceso 46
                                        case -1:
                                            perror("main:proceso46:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo = fork()) { // Proceso 50
                                                case -1:
                                                    perror("main:proceso50:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    switch (pidHijo = fork()) { // Proceso 54
                                                        case -1:
                                                            perror("main:proceso54:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            switch (pidHijo = fork()) { // Proceso 56
                                                                case -1:
                                                                    perror("main:proceso56:fork");
                                                                    return 9;
                                                                    break;
                                                                case 0:
                                                                    switch (pidHijo = fork()) { // Proceso 57
                                                                        case -1:
                                                                            perror("main:proceso57:fork");
                                                                            return 9;
                                                                            break;
                                                                        case 0:
                                                                            switch (pidHijo = fork()) { // Proceso 58
                                                                                case -1:
                                                                                    perror("main:proceso58:fork");
                                                                                    return 9;
                                                                                    break;
                                                                                case 0:
                                                                                    pidYo=getpid();
                                                                                    fprintf(stdout, "Soy el proceso 58(pid=%d)\n", pidYo);
                                                                                    sleep(20);
                                                                                    exit(0);
                                                                            }
                                                                            pidYo=getpid();
                                                                            fprintf(stdout, "Soy el proceso 57(pid=%d)\n", pidYo);
                                                                            waitpid(pidHijo, NULL, 0);
                                                                            exit(0);
                                                                            break;
                                                                    }
                                                                    pidYo=getpid();
                                                                    fprintf(stdout, "Soy el proceso 56(pid=%d)\n", pidYo);
                                                                    waitpid(pidHijo, NULL, 0);
                                                                    exit(0);
                                                                    break;
                                                            }
                                                            pidYo=getpid();
                                                            fprintf(stdout, "Soy el proceso 54(pid=%d)\n", pidYo);
                                                            waitpid(pidHijo, NULL, 0);
                                                            exit(0);
                                                            break;
                                                    }
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 50(pid=%d)\n", pidYo);
                                                    waitpid(pidHijo, NULL, 0);
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 46(pid=%d)\n", pidYo);
                                            waitpid(pidHijo, NULL, 0);
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 42(pid=%d)\n", pidYo);
                                    waitpid(pidHijo, NULL, 0);
                                    exit(0);
                                    break;
                            }
                            switch (pidHijo = fork()) { // Proceso 43
                                case -1:
                                    perror("main:proceso43:fork");
                                    return 7;
                                    break;
                                case 0:
                                    switch (pidHijo = fork()) { // Proceso 47
                                        case -1:
                                            perror("main:proceso47:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo = fork()) { // Proceso 51
                                                case -1:
                                                    perror("main:proceso51:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 51(pid=%d)\n", pidYo);
                                                    waitpid(pidHijo, NULL, 0);
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 47(pid=%d)\n", pidYo);
                                            waitpid(pidHijo, NULL, 0);
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 43(pid=%d)\n", pidYo);
                                    waitpid(pidHijo, NULL, 0);
                                    exit(0);
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 40(pid=%d)\n", pidYo);
                            waitpid(pidHijo, NULL, 0);
                            exit(0);
                            break;
                    }
                    switch (pidHijo = fork()) { // Proceso 41
                        case -1:
                            perror("main:proceso41:fork");
                            return 5;
                            break;
                        case 0:
                            switch (pidHijo = fork()) { // Proceso 44
                                case -1:
                                    perror("main:proceso44:fork");
                                    return 6;
                                    break;
                                case 0:
                                    switch (pidHijo = fork()) { // Proceso 48
                                        case -1:
                                            perror("main:proceso48:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo = fork()) { // Proceso 52
                                                case -1:
                                                    perror("main:proceso52:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    switch (pidHijo = fork()) { // Proceso 55
                                                        case -1:
                                                            perror("main:proceso55:fork");
                                                            return 9;
                                                            break;
                                                        case 0:
                                                            pidYo=getpid();
                                                            fprintf(stdout, "Soy el proceso 55(pid=%d)\n", pidYo);
                                                            waitpid(pidHijo, NULL, 0);
                                                            exit(0);
                                                            break;
                                                    }
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 52(pid=%d)\n", pidYo);
                                                    waitpid(pidHijo, NULL, 0);
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 48(pid=%d)\n", pidYo);
                                            waitpid(pidHijo, NULL, 0);
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 44(pid=%d)\n", pidYo);
                                    waitpid(pidHijo, NULL, 0);
                                    exit(0);
                                    break;
                            }
                            switch (pidHijo = fork()) { // Proceso 45
                                case -1:
                                    perror("main:proceso45:fork");
                                    return 7;
                                    break;
                                case 0:
                                    switch (pidHijo = fork()) { // Proceso 49
                                        case -1:
                                            perror("main:proceso49:fork");
                                            return 8;
                                            break;
                                        case 0:
                                            switch (pidHijo = fork()) { // Proceso 53
                                                case -1:
                                                    perror("main:proceso53:fork");
                                                    return 9;
                                                    break;
                                                case 0:
                                                    pidYo=getpid();
                                                    fprintf(stdout, "Soy el proceso 53(pid=%d)\n", pidYo);
                                                    waitpid(pidHijo, NULL, 0);
                                                    exit(0);
                                                    break;
                                            }
                                            pidYo=getpid();
                                            fprintf(stdout, "Soy el proceso 49(pid=%d)\n", pidYo);
                                            waitpid(pidHijo, NULL, 0);
                                            exit(0);
                                            break;
                                    }
                                    pidYo=getpid();
                                    fprintf(stdout, "Soy el proceso 45(pid=%d)\n", pidYo);
                                    waitpid(pidHijo, NULL, 0);
                                    exit(0);
                                    break;
                            }
                            pidYo=getpid();
                            fprintf(stdout, "Soy el proceso 41(pid=%d)\n", pidYo);
                            waitpid(pidHijo, NULL, 0);
                            exit(0);
                            break;
                    }
                    pidYo=getpid();
                    fprintf(stdout, "Soy el proceso 39(pid=%d)\n", pidYo);
                    waitpid(pidHijo, NULL, 0);
                    exit(0);
                    break;
            }
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 38(pid=%d)\n", pidYo);
            waitpid(pidHijo, NULL, 0);
            exit(0);
            break;
        default:
            pidYo=getpid();
            fprintf(stdout, "Soy el proceso 37(pid=%d)\n", pidYo);
            system("pstree | grep 'main'");
            waitpid(pidHijo, NULL, 0);
            exit(0);
            break;
    }
    
    return 0;
}