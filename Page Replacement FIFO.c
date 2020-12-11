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


// Output:
// Enter the number of pages: 18

//  Enter the page numbers: 5 0 2 1 0 3 0 2 4 3 0 3 2 1 3 0 1 5

//  enter number of frames: 3
// PAGE            FRAME
// 5       -1      5       -1
// 0       -1      5       0
// 2       2       5       0
// 1       2       1       0
// 0       No page fault
// 3       2       1       3
// 0       0       1       3
// 2       0       2       3
// 4       0       2       4
// 3       3       2       4
// 0       3       0       4
// 3       No page fault
// 2       3       0       2
// 1       1       0       2
// 3       1       3       2
// 0       1       3       0
// 1       No page fault
// 5       5       3       0

//  Total number of page faults: 15

