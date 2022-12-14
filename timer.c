/* timer.c */
//https://www.tutorialspoint.com/c_standard_library/c_function_difftime.htm
//Zoe Carter, Kyndall Jones, Julian Forbes
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

bool sig =true;
time_t start_t, end_t;
int alarm_cnt;
void handler(int signum){
  printf("Hello World!\n");
  alarm_cnt++;
  sig = false;
  alarm(1);
}

void secondhandler(int signum){
  time(&end_t);
  double diff_t = difftime(end_t,start_t);
  printf("Alarm Count: %d\n\bTotal Time: %f\n", alarm_cnt, diff_t);
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler);
  signal(SIGALRM,secondhandler);
  alarm(1);
  time(&start_t);
  while(1){ // while true
    while (sig);
    printf("Turing was right!\n");
  // exit(1);
} //busy wait for signal to be delivered
return 0; //never reached
}