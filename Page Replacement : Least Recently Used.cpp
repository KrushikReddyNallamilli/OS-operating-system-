#include<stdio.h>
int main()
{
	int f[20],p[50],pf=0,c,d,i,j,n,m,k=0,r,t,b[20],c1[20];
	printf("Enter the number of pages: ");
	scanf("%d",&n);
	printf("\n enter the page numbers:" );
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	printf("\n enter number of frames: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
		f[i]=-1;
	printf("PAGE\t      FRAME\n");
	for(i=0;i<n;i++)
	{
		c=0;
		for(j=0;j<m;j++)
		{
			if(p[i]!=f[j])
				c++;
		}
		if(c!=m)
		{
			printf("%d\t",p[i]);
			printf("No page fault\n");
		}
		if(c==m)
		{
			pf++;
			if(k<m)
			{
				f[k]=p[i];
				k++;
				printf("%d\t",p[i]);
				for(j=0;j<m;j++)
					printf("%d\t",f[j]);
				printf("\n");
			}
			
		else
		{
			for(r=0;r<m;r++)
			{
				c1[r]=0;
				for(j=i-1;j<n;j--)
				{
					if(f[r]!=p[j])
						c1[r]++;
					else
						break;
				}
			}
			for(r=0;r<m;r++)
				b[r]=c1[r];
			for(r=0;r<m;r++)
			for(j=r;j<m;j++)
				if(b[r]<b[j])
				{
					t=b[r];
					b[r]=b[j];
					b[j]=t;
				}
			printf("%d\t",p[i]);
			for(r=0;r<m;r++)
			{
				if(c1[r]==b[0])
					f[r]=p[i];
				printf("%d\t",f[r]);
			}
			printf("\n");
			}
			
		}
	}
	      printf("\n total number of page faults %d",pf);
}

// Output:
// Enter the number of pages: 12

//  Enter the page numbers: 4 3 2 1 4 3 5 4 3 2 1 5

//  enter number of frames: 3
// PAGE            FRAME
// 4       4       -1      -1
// 3       4       3       -1
// 2       4       3       2
// 1       1       3       2
// 4       1       4       2
// 3       1       4       3
// 5       5       4       3
// 4       No page fault
// 3       No page fault
// 2       2       4       3
// 1       2       1       3
// 5       2       1       5

//  Total no of page faults id :10
