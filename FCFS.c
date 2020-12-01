#include<stdio.h>
main()
{
	int bt[20],wt[20],tat[20],i,n;
	float avgwt,avgtat;
	printf("Enter the number of processes -");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the Burst Time for process %d -",i);
		scanf("%d",&bt[i]);
	}
	wt[0]=avgwt=0;
	tat[0]=avgtat=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		avgwt +=wt[i];
		avgtat +=tat[i];
	}
	printf("\t PROCESS	BURST TIME	WAITING TIME	TURNAROUND TIME");
	for(i=0;i<n;i++)
	printf("\n\t P%d \t\t %d \t\t %d \t\t %d",i,bt[i],wt[i],tat[i]);
	printf("\n Average Waiting time -- %f",avgwt/n);
	printf("\n Average TurnAround time -- %f",avgtat/n);
}
