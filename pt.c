#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *mythreadfun()
{
	printf(" Executing worker thread \n");
	sleep(3);
	return NULL;
}
int main()
{
	pthread_t thread_id;
	printf("Iam in Master Thread.\n");
	pthread_create(&thread_id,NULL,mythreadfun,NULL);
	pthread_join(thread_id,NULL);
	printf("Now Iam in Master thread.\n ");
	exit(0);
}
