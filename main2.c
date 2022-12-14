// <Author - Zoe Carter>
// https://www.javatpoint.com/random-function-in-c
#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <time.h>

#define   MAX_COUNT  200

void  ChildProcess(int);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     int i;
     for (i = 1; i <= 3; i++){
          pid = fork();
          if (pid == 0){
          ChildProcess(i);
          } 
          else if (pid < 0){
               printf("Error: Fork Op \n");
          }
          ParentProcess();
     }        
}

void  ChildProcess(int child)
{
     int  i, rand_num, sleep_num;
     //usinng time as seed
     srand(time(0));
     // Random num no more than 30
     rand_num = rand()%30+1;
     
     for (i = 1; i <= rand_num; i++){
          printf("Child Pid: %d is going to sleep!\n", getpid());
          //Sleep num no more than 10
          sleep_num = rand()%10 + 1;
          sleep(sleep_num);
          printf("Child Pid: is awake!\n Where is my Parent: %d ?", getppid());
     }
     exit(0);
}

void  ParentProcess(void)
{
     int i, pid, stat;
     for (i = 1; i <= 3; i++){
          pid = wait(&stat);
          printf("Child Pid: %d has completed",pid);
     }
}