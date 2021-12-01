#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<unistd.h>
#include <stdlib.h>
#include<wait.h>

#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */

void SIGINT_handler(int signal)
{
  	pid_t p = fork();
	if(p==0)
	{
		printf("Chid process\n");
		printf("Chid Process Id: %d\n",getpid());
		printf("Chid Parent Id: %d\n",getppid());
	}
	else if (p>0)
	{
		printf("Parent process\n");
		printf("Parent Process Id: %d\n",getpid());
		printf("Parent Parent Id: %d\n",getppid());
	}
	else
	{
		printf("Could not fork");
		exit(1);
	}

}

void  SIGQUIT_handler(int sig)
{
	int stat;
	printf("Signal number %d: Quit\n", sig);
	exit(0);
}

int main()
{
  
  signal(SIGINT,  SIGINT_handler);   //signal handler for SIGINT
  signal(SIGQUIT,  SIGQUIT_handler); //signal handler for SIGQUIT

  
  int count = 0;
  while(1) //Infinite loop so that the process keeps on executing
  {
  	
    printf("Count: %d\n", count); //Printing the count
    sleep(1);
    count++;
    if (count == 5) {
      signal(SIGINT, SIG_DFL); // After 5 seconds, switch the signal handler back to the default one
    }
  }
}
