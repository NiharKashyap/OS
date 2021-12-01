#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
   long msg_type;
   char msg[100];
} message;
int main() {
   
   int msg_id;
   msg_id = msgget(1212, 0666 | IPC_CREAT); //creating message queue

   if (msg_id < 0)
   {
      perror("Error creating queue");
      return 1;
   }
        
   message.msg_type = 1;
   printf("Message Queue ID: %d\n", msg_id);
   printf("Type Message : ");
   fgets(message.msg, 100, stdin);
   
   if(msgsnd(msg_id, &message, sizeof(message), 0)<0) //send message
   {
      perror("Error to write data");
      return 1;
   }
   
   printf("Message sent from Server : %s \n", message.msg); // display sent message

   return 0;
}
