#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void* hello_world(void* arg)
{
    printf("Hello World from new thread\n");
    pthread_exit(NULL);
} 

int main()
{
	
	pthread_t ptid;
  
    pthread_create(&ptid, NULL, &hello_world, NULL);
    printf("Printing from main\n");
    pthread_exit(NULL);
    return 0;
}
