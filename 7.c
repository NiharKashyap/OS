#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/types.h>

int main (int argc, char* argv[])
{

 char* file = argv[1];  //File name passed as command line argument
 int fd;
 struct flock lock;

 printf("Run by Process ID: %d\n", getpid());
 fd = open (file, O_WRONLY); //Opening file in write mode
 printf ("Opening file: %s\n", file); //Opening file to lock
 memset (&lock, 0, sizeof(lock)); //Initialize Lock
 lock.l_type = F_WRLCK; //Lock type is write lock
 printf ("Trying to acquire lock\n");
 fcntl (fd, F_SETLKW, &lock); //Trying to set lock SETLKW will wait till a lock is acquired
 printf ("Acquired Lock\n");
 printf("Press Enter to unlock file: ");
 getchar (); //Wait till Enter is pressed
 lock.l_type = F_UNLCK;  //Setting lock to unlock
 fcntl (fd, F_SETLKW, &lock);
 printf ("File has been Unlocked\n");  //Successfully unlocked file
 close (fd); //Close file

 return 0;
}




