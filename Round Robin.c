#include<stdio.h>
main()
{
	int ct[20],bt[20],wt[20],tat[20],i,j,n,t,max;
	float avgwt,avgtat,temp=0;
	printf("Enter the number of processes -");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the Burst Time for process %d -",i);
		scanf("%d",&bt[i]);
		ct[i]=bt[i];
	}
	printf("Enter the size of time slice -");
	scanf("%d",&t);
	max=bt[0];
	for(i=1;i<n;i++)
	if(max<bt[i])
		max=bt[i];
	for(j=0;j<(max/t)+1;j++)
	for(i=0;i<n;i++)
	if(bt[i]!=0)
	if(bt[i]<=t)
	{
		tat[i]=temp+bt[i];
		temp=temp+bt[i];
		bt[i]=0;
	}
	else
	{
		bt[i]=bt[i]-t;
		temp=temp+t;
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-ct[i];
		avgwt+=wt[i];
		avgtat += tat[i];
	}
	printf("\t PROCESS	BURST TIME	WAITING TIME	TURNAROUND TIME");
	for(i=0;i<n;i++)
	printf("\n\t P%d \t\t %d \t\t %d \t\t %d",i,bt[i],wt[i],tat[i]);
	printf("\n Average Waiting time -- %f",avgwt/n);
	printf("\n Average TurnAround time -- %f",avgtat/n);
}
