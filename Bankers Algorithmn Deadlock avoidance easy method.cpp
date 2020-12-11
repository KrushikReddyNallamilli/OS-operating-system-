#include<stdio.h>
main()
{
	int curr[20][20],maxclaim[20][20],avl[20];
	int alloc[5]={0,0,0,0,0};
	int maxres[20],running[20],safe=0;
	int count=0,i,j,exec,r,p,k=1,pronum[20],c=0;
	printf("\n Enter the number of processess: ");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		running[i]=1;
		count++;
	}
	printf("\n enter the number of resources: ");
	scanf("%d",&r);
	for(i=0;i<r;i++)
	{
		printf("\n Enter the instances of resource %d",k++);
		scanf("%d",&maxres[i]);
	}
	printf("\n Enter maximum resource table: ");
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
		scanf("%d",&maxclaim[i][j]);
	printf("\n Enter allocated resource table: ");
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
		scanf("%d",&curr[i][j]);
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
		alloc[j]+=curr[i][j];
	for(i=0;i<r;i++)
		avl[i]=maxres[i]-alloc[i];
	while(count!=0)
	{
		safe=0;
		for(i=0;i<p;i++)
		{
			if(running[i])
			{
				exec=1;
				for(j=0;j<r;j++)
				{
					if(maxclaim[i][j]-curr[i][j]>avl[j])
					{
						exec=0;
						break;
					}
				}
				if(exec)
				{
					running[i]=0;
					count--;
					safe=1;
					pronum[c++]=i+1;
					for(j=0;j<r;j++)
						avl[j]+=curr[i][j];
					break;
				}
			}
		}
	}
	if(!safe)
		printf("\n the processes are in unsafe state");
	printf("\n the safe sequence of process is: ");
		for(i=0;i<p;i++)
			printf("\t P%d",pronum[i]);
}
