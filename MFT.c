#include<stdio.h>
main()
{
	int ms,bs,nob,ef,n,mp[10],tif=0,i,p=0;
	printf("Enter the total memory available(in Bytes)--");
	scanf("%d",&ms);
	printf("\n Enter the block size (in Bytes)--");
	scanf("%d",&bs);
	nob=ms/bs;
	ef=ms-nob*bs;  //1000-3*300=>100
	printf("\n Enter the number of processes --");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter memory required for process %d (in Bytes)--",i+1);
		scanf("%d",&mp[i]);
	}
	printf("\n No of Blocks available in memory --%d",nob);
	printf("\n PROCESS \t MEMORTY REQUIRED \t ALLOCATED \t INTERNAL FRAGMENTATION");
	for(i=0;i<n && p<nob ;i++)
	{
		printf("\n P%d \t\t	%d",i+1,mp[i]);
		if(mp[i]>bs)
		printf("\t\t\t NO \t\t\t---");
		else
		{
			printf("\t\t\t YES \t\t\t %d",bs-mp[i]);
			tif +=bs-mp[i];
			p++;
		}
	}
	if(i<n)
	printf("\n Memory is FULL ,Remaining processes can't be allocated.");
	printf("\n Total Internal Fragmentation is %d",tif);
	printf("\n Total External Fragmentation is %d",ef);
}
