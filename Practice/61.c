#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<string.h>
  
//Practice program  
int main()
{
	char *str;
	char *buff;
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
  
    // shmat to attach to shared memory
    str = (char *) shmat(shmid,(void*)0,0);
  	
  	printf("Write Data\n");
  	
	fgets(buff,10,stdin);
	
	strcpy(str, buff);
	
    printf("Data written in memory: %c\n",buff);
      
    //detach from shared memory 
    shmdt(str);
  
    return 0;
}
