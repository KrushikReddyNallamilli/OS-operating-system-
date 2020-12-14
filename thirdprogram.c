#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	int pid;
	pid=fork();
	if(pid<0)
	{
		printf("\n Fork failed");
		exit(0);
	}
	else if(pid==0)
	{
		execlp("/bin/ls","ls","-l",NULL);
	}
	else
	{
		wait(NULL);
		printf("\n Child complete \n");
	}
}
