#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
int main()
{
	Key_t Key=ftok("shmfile",65);
	int shmid=shmget(Key,1024,0666|IPC_CREAT);
	char*str(char*) shmat(shmid,(void *)0,0);
	printf(" data read fom memory: %s\n",str);
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
