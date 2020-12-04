#include<stdio.h>
main()
{
	int ms,mp[10],i,temp,n=0;
	char ch='y';
	printf("\n Wnter the total memory acailable (in Bytes)--");
	scanf("%d",&ms);
	temp=ms;
	for(i=0;ch=='y';i++,n++)
	{
		printf("\n Enter memory required for process %d (in Bytes)--",i+1);
		scanf("%d",&mp[i]);
		if(mp[i]<=temp)
		{
			printf("\n Memory is allocated for process %d",i+1);
			temp=temp-mp[i];
		}
		else
		{
			printf("\n Memory is FULL");
			break;
		}
		printf("\n Do you want to continue (y/n)--");
		scanf(" %c",&ch);
	}
	printf("\n \nPROCESS \t\t MEMORY ALLOCATED");
	for(i=0;i<n;i++)
	printf("\n	%d\t\t %d",i+1,mp[i]);
	printf("\n Total memory allocated is %d",ms-temp);
	printf("\n total External Fragmentation is %d ",temp);
}
