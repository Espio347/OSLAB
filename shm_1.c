#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

int main()
{
 void* shared_memory;
 char buff[100];
 int shmid;
 shmid = shmget((key_t) 1123,1024,0666|IPC_CREAT);
 printf("Key of Shared Memory is: %d\n",shmid);
 shared_memory = shmat(shmid,NULL,0);
 printf("Shared Memory attached at: %p\n",shared_memory);
 printf("Enter Some Data to Write:\n");
 read(0,buff,100);
 strcpy(shared_memory,buff);
 printf("Your data is %s\n",(char*)shared_memory);
 return 0;
}

 
 
