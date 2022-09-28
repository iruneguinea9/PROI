#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#define N 4         //a constant defined to be changed as needed
void main()
{


    printf("Proceso padre: PID %d \n",getpid());        //the parent
    pid_t pid;
    for (int i = 1; i < N; i++)
    {
        int pid = fork();
        if (pid == -1)
        {
            printf("Error al crear proceso hijo");
           exit(-1);
        }
        if (pid == 0) //child process
        {
            printf("hijo %d PID = %d, padre PID = %d\n", i,getpid(), getppid());
        }
        else{
            wait(NULL);
            exit(0);
        }
    }   
        pid = wait(NULL);

}
