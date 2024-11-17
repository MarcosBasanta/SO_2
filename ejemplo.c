#define _HPUX_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void espera(int,char *,int);

int main(int argc,char *argv[]) {
   int pid,retorno,retorno2,i,devolver=0;
   
    if(argc != 1) {
        fprintf(stderr,"Uso: %s\n\n",argv[0]);
        return 1;
    }
   
   /* Observad cómo el sangrado reproduce el árbol genealógico. */
   switch(fork())/*primer hijo*/ {
      case -1:
        perror("pract4:fork");
        return 2;
        break;
      case 0:
        espera(0,"primer hijo",0);
        break;
    }
   switch(fork())/*segundo hijo*/ {
      case -1: 
        perror("pract4:fork");
        return 3;
      case 0:
        switch(fork())/*primer nieto*/ {
            case -1:
                perror("pract4:fork");
                return 4;
            case 0:espera(0,"primer nieto",0);
        }
        switch(fork())/*segundo nieto*/ {
            case -1:
                perror("pract4:fork");
                return 5;
            case 0:
                switch(fork())/*bisnieto*/ {
                    case -1:
                        perror("pract4:fork");
                        return 6;
                    case 0: 
                        espera(0,"bisnieto",0);
                }
                espera(1,"segundo nieto",1);
        }
        espera(2,"segundo hijo",1);
    }
    espera(2,"padre",1);
}

void espera (int i,char *parentesco,int dormir) {
   int pid,retorno,retorno2,j;

    if(dormir) {
        sleep(5);
    }
    pid=getpid();

    if(pid==-1) {
        perror("pract5:getpid");
        exit(1);
    }

    retorno=pid%10;

    for(j=0;j<i;j++) {
        if(wait(&retorno2)==-1) {
            perror("pract4:wait");
            exit(1);
        }     
        if(WIFEXITED(retorno2)) {
            retorno=retorno+WEXITSTATUS(retorno2);
        } else {
            perror("pract4:WIFEXITED");
            exit(0);
        }
    }
    printf("Soy el %s(pid=%d)y mi suma es: %d \n",parentesco,pid,retorno);
    exit(retorno);
}