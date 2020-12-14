#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	int mypid,parentpid,childpid,status,s,id;
	mypid=getpid();
	parentpid=getppid();
	printf("\n Parent: mypid is %d \n",mypid);
	printf("\n Parent: my parrent's pid is %d \n",parentpid);
	
	childpid=fork();
	if(childpid<0)
	{
		printf("Fork Failure");
	}
	if(childpid==0)
	{
		printf("\n child: I an a new born process \n");
		mypid=getpid();
		parentpid=getppid();
		printf("\n Child: mypid is %d \n",mypid);
		printf("\n Child: my parrent's pid is %d \n",parentpid);
		printf("\n Child: I am executing date command \n");
		execl("/bin/date","date",NULL);
		exit(0);
	}
	else
	{
		printf("\n Parent: I created a child process");
		printf("\n Parent: My child's pid is %d \n",childpid);
		id=wait(&status);
		s=WEXITSTATUS(status);
		printf("\n Parent: my child is dead with pid %d and exit status %d, I am going to leave, bye. \n",id,s);
	}
}
