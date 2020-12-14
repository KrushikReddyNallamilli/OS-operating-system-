#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd[2];
	if(pipe(fd)==-1)
	{
		printf("Error in creating a pipe \n");
		exit(0);
	}
	if(!fork())
	{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		execlp("ls","ls","-l",NULL);
	}
	else
	{
		close(0);
		dup(fd[0]);
		close(fd[1]);
		execlp("sort","sort",NULL);
	}
	return (0);
}
