#include<stdio.h>
int main()
{
	int i,j,n,m,a[50],f[10],k,avail,pf=0;
	printf("Enter the number of pages: ");
	scanf("%d",&n);
	printf("\n Enter the page numbers: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n enter number of frames: ");
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
		f[i]=-1;
	
	printf("PAGE\t	FRAME\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		avail=0;
		for(k=0;k<m;k++)
		{
			if(f[k]==a[i])
				avail=1;
		}
	if(avail==1)
		printf("No page fault");
	else
	{
		f[j]=a[i];
		j=(j+1)%m;
		pf++;
		for(k=0;k<m;k++)
			printf("%d\t",f[k]);
	}
	printf("\n");
	}
	printf("\n Total number of page faults: %d",pf);
}
