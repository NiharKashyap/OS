#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

    
    char * path = "/tmp/path"; // FIFO file path

    
    mkfifo(path, 0666); //Creating FIFO

    
    char str1[80]; //character array to store input string
	char str2[]="ACKNOWLEDGEMENT"; //Ack message
	while (1)
    {
    
        fd1 = open(path,O_RDONLY); //Reading from FIFO
        read(fd1, str1, 80);

        
        printf("Program 2 says: %s\n", str1); //Print input string from program 2
        close(fd1);

        fd1 = open(path,O_WRONLY); //Open and write Acknowledgement message
        write(fd1, str2, 20);
        close(fd1);
    }
    return 0;
}
