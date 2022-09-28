#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


void main() {

    pid_t hijo1 = fork(); // fork a child

if(hijo1 == 0)  //first child
{
    printf("yo soy el hijo 1, mi padre es PID=%d, yo soy PID=%d\n",getppid(),getpid());
   
    exit(1);
}
else    //child and grandchild
{
    pid_t hijo2 = fork(); // fork a child
    if (hijo2 == 0)
    {
         printf("yo soy el hijo 2, mi padre es PID=%d, yo soy PID=%d\n",getppid(),getpid());;
        pid_t grandchild = fork(); // fork a grandchild
        if (grandchild == 0)
        {
             printf("yo soy el hijo 3, mi padre es PID=%d, yo soy PID=%d\n",getppid(),getpid());
           
            exit(3);
        }
        else
        {
            
            grandchild = wait(NULL);
        }
        exit(2);
    }
    else
    {
 
    //wait for the 2 children to finish
     hijo1 = wait(NULL);
     hijo2 = wait(NULL);
    }
}

}
