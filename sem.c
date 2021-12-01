#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/ipc.h>
int main()
{
  int sem1;

char a='5';
   sem1=semget(1212,1,IPC_CREAT|0666);/* creating semaphore */
  if(sem1<0)
  {
  	printf("not created semaphore");	
  }
  
   	semctl(sem1,0,SETVAL,6); /* setting value to semaphore */
   	struct sembuf sem_op;
   	FILE *fd;
    fd=fopen("file.txt","a");
 
    sem_op.sem_num=0;
    sem_op.sem_op=-1;
    sem_op.sem_flg=0;
   	semop(sem1,&sem_op,1);/* lock applied */    

	putc('\n',fd);  /*trying to place data into file akr */
	putc(a,fd);     /*trying to place data into file akr */
 	fclose(fd);

	sem_op.sem_num=0;
	sem_op.sem_op=1;
	sem_op.sem_flg=0;
	semop(sem1,&sem_op,1);/*lock released */
}
