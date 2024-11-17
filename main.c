#define _HPUX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int crea_jerarquia();
void espera(int,char *,int);

int main() {
    crea_jerarquia();
    return 0;
}

int crea_jerarquia() {
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
                                                                                    espera(0,"proceso 58",0);
                                                                            }
                                                                            espera(1, "proceso 57", 1);
                                                                            break;
                                                                    }
                                                                    espera(1, "proceso 56", 1);
                                                                    break;
                                                            }
                                                            espera(1, "proceso 54", 1);
                                                            break;
                                                    }
                                                    espera(1, "proceso 50", 1);
                                                    break;
                                            }
                                            espera(1, "proceso 46", 1);
                                            break;
                                    }
                                    espera(1, "proceso 42", 1);
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
                                                    espera(0, "proceso 51", 0);
                                                    break;
                                            }
                                            espera(1, "proceso 47", 1);
                                            break;
                                    }
                                    espera(1, "proceso 43", 1);
                                    break;
                            }
                            espera(2, "proceso 40", 1);
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
                                                            espera(0, "proceso 55", 0);
                                                            break;
                                                    }
                                                    espera(1, "proceso 52", 1);
                                                    break;
                                            }
                                            espera(1, "proceso 48", 1);
                                            break;
                                    }
                                    espera(1, "proceso 44", 1);
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
                                                    espera(0, "proceso 53", 0);
                                                    break;
                                            }
                                            espera(1, "proceso 49", 1);
                                            break;
                                    }
                                    espera(1, "proceso 45", 1);
                                    break;
                            }
                            espera(2, "proceso 41", 1);
                            break;
                    }
                    espera(2, "proceso 39", 1);
                    break;
            }
            espera(1, "proceso 38", 1);
            break;
        default:
            printf("Proceso 37 padre\n");
            break;
    }
    return 0;
}

void espera (int i,char *parentesco,int dormir) {
   int pid, retorno, j;

    if(dormir) {
        sleep(5);
    }

    pid=getpid();
    if(pid==-1) {
        perror("main:getpid");
        exit(1);
    }

    for(j=0; j<i; j++) {
        if(wait(&retorno)==-1) {
            perror("main:wait");
            exit(1);
        }
        if(!WIFEXITED(retorno)) {
            perror("main:WIFEXITED");
            exit(0);
        }
    }
    printf("Soy el %s(pid=%d)\n", parentesco, pid);
    exit(0);
}