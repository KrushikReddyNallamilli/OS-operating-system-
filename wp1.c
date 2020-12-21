#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
	Key_t Key=ftok("shmfile",65);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char*str=(char *)shmat(shmid,(void*)0,0);
	printf("Write data into shared memory: ");
	scanf(" %[^\n]*%c",str);
	printf("Data written in memory: %s\n",str);
	shmdt(str);
	return 0;
}
