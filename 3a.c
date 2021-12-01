#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include <stdlib.h>


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

int main()
{
  
  signal(SIGINT,  SIGINT_handler); //Changing signal handler

  int count = 0;
  while(1) //Infinite loop so that the process keeps on executing
  {
    printf("Count: %d\n", count); //Printing the count
    sleep(1);
    count++;
    if (count == 5) {
      signal(SIGINT, SIG_DFL); //After 5 seconds ctrl + C will close the program
    }
  }
}
