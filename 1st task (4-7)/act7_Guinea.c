#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
    pid_t pid;
    int num = 6;
    printf("Valor inicial de la variable %d\n",num);
    pid = fork();
    
    if(pid==-1){
        printf("Error creating the child");
    }
    if (pid ==0){       //child
        num = num -5;
        printf("Variable en proceso hijo %d\n",num);
    } 
    else{       //parent proccess
        num = num +5;
        printf("Variable en proceso padre %d\n",num);
    }
 }
