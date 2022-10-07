#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int main(){
    pid_t child_pid, child_pid2, child_pid3, parent_pid;
    parent_pid=(int) getpid();
    int count =0;
    child_pid=fork();
    child_pid2=fork();
    child_pid3=fork();
    while(1)
    {

        if(child_pid!=0){
            fprintf(stdout, "Parent: %i\n", (int) getpid());
            usleep(100000);
            //count++;
            //if(count>10)
               // kill(parent_pid,SIGTERM);
        }
        else{
            fprintf(stdout, "Child: %i\n", (int) getpid());
            usleep(100000);
        }
    }

    return 0;
}
