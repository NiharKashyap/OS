#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
   long msg_type;
   char msg[100];
} message;

int main() 
{
   int msg_id;
   msg_id = msgget(1212, 0666 | IPC_CREAT); //create message queue and return id

   if(msg_id<0)
   {
      perror("Error creating queue");
   }

   if(msgrcv(msg_id, &message, sizeof(message), 1, 0)<0) //used to receive message
   {
      perror("Error in reading data");
      return 1;
   }
   printf("Message received by Client : %s \n", message.msg); // display received message
   msgctl(msg_id, IPC_RMID, NULL); //destroy the message queue
   
   return 0;
}
