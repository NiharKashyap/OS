//Fork
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t p = fork();
	
	if(p==0)
	{
		//child
		getpid()
		getppid()
	}
	else if(p>0)
	{
		//parent
	}
	else
	{
		//error
	}
}

//Fork wait
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	pid_t p = fork();
	if(p==0)
	{
		//child
		getpid
		getppid
	}
	else if (p>0)
	{
		//parent
		wait(NULL);
		getpid
		getppid
	}
	else
	{
		//error
	}
}

//Changing interrupts
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#inlcude<stdlib.h>


void SIGINT_handler(int signal)
{
	//Logic for new interrupt
}
int main()
{
	signal(SIGINT, SIGINT_handler); //changing signal handler
	
	int count=0;
	
	while(1)
	{
		sleep(1);
		count++;
		if(count==5)
		{
			signal(SIGINT, SIG_DFL);
		}
	}
}

//Pthread
#inlcude<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<thread.h>

void* hello_world(void* arg)
{
	//Some printfs
	pthread_exit(NULL);
}
int main()
{
	pthread_t p;
	
	pthread_create(&p, NULL, &hello_world, NULL);
	//some printf
	pthread_exit(NULL);
	return 0;	
} 


