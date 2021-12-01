#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
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
	int n1 = 0, n2 = 1, i, number;
	int n3;
	int terms,N;
	int p[3], pid;

	if (pipe(p) < 0)
		exit(1);

	pid_t p_id = fork();
	pid_t id;
	if (p_id == 0)
	{

		id = getpid();
		write(p[1], &id, sizeof(n3)); //Sending child id to parent
		printf("Enter number of terms: ");
		scanf("%d", &terms);
		N=terms;
		write(p[1], &N, sizeof(N));
		
		write(p[1], &signal, sizeof(signal));
		//Fibonacci logic
		for (i = 2; i < terms; i++) //loop starts from 2 because 0 and 1 are already printed
		{
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
			write(p[1], &n3, sizeof(n3)); //Sending fibonacci term to parent process
		}
	}
	else if (p_id > 0)
	{
		sleep(2);
		read(p[0], &id, sizeof(id)); //Read and print child id received
		printf("Child process id: %d\n", id);
		int count = 2;
		read(p[0], &N, sizeof(N));
		printf("Fibonacci Series : ");
		printf("0\t");
		printf("1\t");
		while (1) //While child process keeps communicating print the fib term
		{

			read(p[0], &n3, sizeof(n3));
			printf("%d\t", n3);
			count++;
			
			if (count >= N)
			{
				break;
			}
			
		}
		
		read(p[0], &signal, sizeof(signal));
		printf("\nSignal id: %d\n", signal);
		exit(1);
	}
	else
	{
		printf("Could not fork");
		exit(1);
	}
}

int main()
{

	signal(SIGINT, SIGINT_handler); //Changing signal handler

	int count = 0;
	while (1) //Infinite loop so that the process keeps on executing
	{
		sleep(1);
		count++;
		if (count == 5)
		{
			signal(SIGINT, SIG_DFL); //After 5 seconds ctrl + C will close the program
		}
	}
}
