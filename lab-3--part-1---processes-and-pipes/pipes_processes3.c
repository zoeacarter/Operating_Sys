#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdlib.h> 
#include<string.h> 
#include<sys/wait.h>

int main(int argc, char **argv)
{
  int pipefd[2], sec_pipe[2];
  int pid, sec_pid;
  char* cat_args[] = {"cat", "scores", NULL};
  char* sort_arg[] = {"sort", NULL};
  char* grep_args[] = {"grep", argv[1], NULL};

  pipe(pipefd);
  pipe(sec_pid);
  pid = fork();
  if (pid < 0){
    printf("Failing");
  }
  if (pid == 0){
    sec_pid = fork();
    if (sec_pid == 0){
      dup2(sec_pip[0], 0);
      close(sec_pid[1]);
      close(pipefd[1]);
      close(pipefd[0]);
      execvp("sort", sort_args);
    }
    else {
      dup2(sec_pip[1], 1);
      dup2(pipefd[0], 0);
      close(pipefd[1]);
      close(sec_pipe[0]);
      execvp("grep",grep_args);

    }
    else{
      dup2(pipefd[1], 1);
      close(pipefd[0]);
      execvp("cat", cat_args);
    }
  }
}