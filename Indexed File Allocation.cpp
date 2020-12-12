#include<stdio.h>
main()
{
	int f[50],i,index[50],n,c,p;
	for(i=0;i<50;i++)
	   f[i]=0;
	START:
	    printf("\n Enter index block:");
		scanf("%d",&p);
		if(f[p]==0)
		{
			f[p]=1;
			printf("\n Enter number of blocks of file to store on index:");
			scanf("%d",&n);
		}
		else
		{
			printf("\n Index block is already allocated\n");
			goto START;
		}
		printf("\n Enter the block numbers to store file:");
		for(i=0;i<n;i++)
		    scanf("%d",&index[i]);
		for(i=0;i<n;i++)
		    if(f[index[i]]==1)
			{
				printf("\nBlock alredy allocated");
				goto START;
			}
			for(i=0;i<n;i++)
			    f[index[i]]=1;
			printf("\n file indexed is allocated");
			for(i=0;i<n;i++)
			    printf("\n %d -> : %d",p,index[i],f[index[i]]);
			printf("\n press 1 to enter new file or 0 to exit:");
		scanf("%d",&c);
		if(c==1)
		    goto START;	    
}
//OUTPUT
//Enter index block:1
//
// Enter number of blocks of file to store on index:4
//
// Enter the block numbers to store file:0 4 6 10
//
// file indexed is allocated
// 1 -> : 0
// 1 -> : 4
// 1 -> : 6
// 1 -> : 10
// press 1 to enter new file or 0 to exit:

