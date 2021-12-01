#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include<unistd.h>
#include <stdlib.h>


int main()
{

pid_t p = fork();

FILE *fptr;

fptr = fopen("file.txt","w");

if(p==0)
{
	time_t begin = time(NULL);
 	
 	printf("Chid process\n");
	printf("Chid Process Id: %d\n",getpid());
	printf("Chid Parent Id: %d\n",getppid());
    sleep(3);
    time_t end = time(NULL);
	
	fprintf(fptr,"Submission time ");
	fprintf(fptr,"%ld",begin);  //Writing Submission time to file
	fprintf(fptr,"\n");
	fprintf(fptr,"Finish time ");
	fprintf(fptr,"%ld",end);	//Writing finished time to file
   	fclose(fptr);
	
    printf("Submission time is %ld seconds: ", begin);  //printing submission time
	printf("Finished time is %ld seconds: ", end);		//printing end time
	
}
exit(0);
}
