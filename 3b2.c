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

int main()
{
	int SigID;
	pid_t id;
	printf("Enter process ID: ");
	scanf("%d", &id);
	printf("Enter Signal ID: ");
	scanf("%d", &SigID);
	kill(id, SIGQUIT);
}
