#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
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
	exit(0);
}
