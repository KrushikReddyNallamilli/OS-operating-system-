#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int f1,f2,n;
	char buff[1024];
	f1=open(argv[1],O_RDONLY);
	if(f1==-1)
	{
		printf("File error");
		return 1;
	}
	f2=open(argv[2],O_WRONLY | O_EXCL | O_CREAT, S_IRWXU);
	if(f2==-1)
	{
		printf("File error");
		return 1;
	}
	while((n=read(f1,buff,1024))>0);
	{
		write(f2,buff,n);
	}
	close(f1);
	close(f2);
	return 0;
}

