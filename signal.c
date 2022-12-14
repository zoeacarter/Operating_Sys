/* hello_signal.c */
//Zoe Carter - Collaboration with: Kyndall Jones, Julian Forbes
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
bool sig = true;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sig = false;
 //exit after printing
   
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){ // while true
    while (sig);
    printf("Turing was right!\n");
    exit(1);
  } //busy wait for signal to be delivered
  return 0; //never reached
}