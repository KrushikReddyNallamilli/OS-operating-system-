#include<stdio.h>
main()
{
	int p[20],pri[20],bt[20],wt[20],tat[20],i,k,n,temp;
	float avgwt,avgtat;
	printf("Enter the number of processes -");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("\n Enter the Burst Time & priority for process %d -",i);
		scanf("%d%d",&bt[i],&pri[i]);
	}
	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(pri[i]>pri[k])
	{
		temp=pri[i];
		pri[i]=pri[k];
		pri[k]=temp;
		
		temp=bt[i];
		bt[i]=bt[k];
		bt[k]=temp;
		
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
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
	printf("\t PROCESS	PRIORITY	BURST TIME	WAITING TIME	TURNAROUND TIME");
	for(i=0;i<n;i++)
	printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t %d",p[i],pri[i],bt[i],wt[i],tat[i]);
	printf("\n Average Waiting time -- %f",avgwt/n);
	printf("\n Average TurnAround time -- %f",avgtat/n);
}
