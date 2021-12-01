#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;

    
    char * path = "/tmp/path"; // FIFO file path

    
    
    mkfifo(path, 0666); // Creating FIFO

    char arr1[80], arr2[80];
    while (1)
    {
        
        fd = open(path, O_WRONLY);
        printf("Enter String: \n");  //Take user input and write to FIFO
        fgets(arr2, 80, stdin);
        write(fd, arr2, strlen(arr2)+1);
        close(fd);

        
        fd = open(path, O_RDONLY);

        
        read(fd, arr1, sizeof(arr1)); //Read Ack from FIFO

        printf("Reply from Program 2: %s\n", arr1);
        close(fd);
    }
    return 0;
}
