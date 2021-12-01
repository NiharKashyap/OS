#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{    
        pid_t p = fork();
        char *args[]={"./exb",argv[0],NULL};
        int status;
        
		if(p==0)
		{
			printf("Chid process\n");
			execv(args[0],args);
			printf("Chid Process Id: %d\n",getpid());
			printf("Chid Parent Id: %d\n",getppid());
		}
		else if(p>0)
		{
			wait(&status);
			printf("Parent process\n");
			printf("Returned status of the child process is %d\n", WIFEXITED(status));
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
