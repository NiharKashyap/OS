#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/ipc.h>
int main()
{
  int sem1,i;
  struct sembuf sem_op;
  
  sem1=semget(1212,1,IPC_CREAT|0666);//creating semaphore
  if(sem1<0)
  {
  	printf("Could not create semaphore");	
  }
  semctl(sem1,0,SETVAL,1); 			//setting value to semaphore
  
	for(i=0;i<5;i++) 				//File will be locked and read five times
	{
		FILE *fd;
	    fd=fopen("file.txt","a");
	 
	    sem_op.sem_num=0;
	    sem_op.sem_op=-1;
	    sem_op.sem_flg=0;
	   	semop(sem1,&sem_op,1);		//lock applied  
		
		printf("Reading file for %d time\n", i+1);
		printf("Press enter to unlock: ");
		getchar (); 				//Wait till Enter is pressed. Release when pressed
		fclose(fd);
		sem_op.sem_num=0;
		sem_op.sem_op=1;
		sem_op.sem_flg=0;
		semop(sem1,&sem_op,1);		//lock released 
	} 
	
}
