// ACTIVITY 8
// Irune Guinea Zufiaurre

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main (){
    pid_t pid,pid2;
    int fd1[2],fd2[2];
    char buffer[30];
    char saludoabuelo[] = "Saludo del abuelo";      //variables to make it easier to mantain
    char saludopadre[] = "Saludo del abuelo";
    char saludohijo[] = "Saludo del abuelo";
    char saludonieto[] = "Saludo del nieto";



    pipe(fd1);
    pipe(fd2);
    pid = fork();       // creating the child
    if(pid==-1){
        printf("Error al crear hijo");
    }
    if(pid == 0){
        // hijo
        pid2 = fork();          // creating the grandchild
        if(pid2==-1){
        printf("Error al crear nieto");
         }   
         if(pid2 == 0){
            // nieto
            close(fd2[1]); 
            close(fd1[0]); 
            read (fd2[0], buffer, 20);
            printf("\t\tEl NIETO recibe mensaje del padre %s..\n",buffer);            
            printf("\t\tEl NIETO envia un mensaje al HIJO.......\n");
            write (fd1[1], saludonieto, 20);
         }
         else{
            // hijo
            close(fd1[1]); 
            close(fd2[0]);
            read (fd1[0], buffer, 20);
            printf("\tEl HIJO recibe mensaje del abuelo %s...\n",buffer);            
            printf("\tEl HIJO envia un mensaje al NIETO.......\n");
            write (fd2[1], saludopadre, 20);
            wait (NULL);
            read (fd1[0], buffer, 20);
            printf("\tEl HIJO recibe mensaje de su hijo %s...\n",buffer);
            printf("\tEl HIJO envia un mensaje al ABUELO........\n");
            write (fd2[1], saludohijo, 20);
         }


    }
    else{
        // abuelo
        close(fd2[1]); 
        close(fd1[0]);
        printf("El ABUELO le envia un mensaje al hijo.....\n");
        write (fd1[1], saludoabuelo, 20);
        wait (NULL);
        read (fd2[0], buffer, 20);
        printf("El ABUELO recibe mensaje del hijo %s...",buffer);
    }
    


}