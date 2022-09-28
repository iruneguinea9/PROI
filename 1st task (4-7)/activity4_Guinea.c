#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  

void main()
{
    pid_t pid,hijo_pid,padre;
    padre = getpid();      // I store the fathers pid to be able to print it later
for(int i=1;i<4;i++)    //loop for making children
    {
   
        pid = fork();
        if(pid == -1){
            printf("Error al crear proceso");
        }
        if(pid == 0)        //this is the children process
        {
            printf("Soy el hijo %d mi padre es %d y  mi pid es %d\n",i,getppid(),getpid());
            exit(0);
            
        }
    }
    printf("Proceso padre %d",padre);
    for(int i=1;i<4;i++) {
        hijo_pid =  wait("NULL"); //waiting for the children to finish
    }
    
}
