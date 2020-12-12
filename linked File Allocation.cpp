#include<stdio.h>
main()
{
	int f[50],i,p,a,n,k,st,len,c;
	for(i=0;i<50;i++)
	    f[i]=0;
	printf("Enter how many blocks that are already allocated: ");
	scanf("%d",&p);  
	printf("\n Enter the block numbers that are already allocated:");
	for(i=0;i<p;i++)
	{
		scanf("%d",&a);
	    f[a]=1;
	}    
	START:
	    printf("\n Enter the starting block and length of the file: ");
		scanf("%d%d",&st,&len);
		k=len;
		for(i=st;i<(st+k);i++)
		if(f[i]==0)
		{
			f[i]=1;
			printf("\n %d ->  %d",i,f[i]);
		}
		else
		{
			printf("\n %d -> Block already allocated",f[i]);
			k++;
		}
		printf("\n press 1 to enter new file or 0 to exit:");
		scanf("%d",&c);
		if(c==1)
		    goto START;
}
//OUTPUT
//Enter how many blocks that are already allocated: 3
//
// Enter the block numbers that are already allocated:4 7 9
//
// Enter the starting block and length of the file: 3 7
//
// 3 ->  1
// 1 -> Block already allocated
// 5 ->  1
// 6 ->  1
// 1 -> Block already allocated
// 8 ->  1
// 1 -> Block already allocated
// 10 ->  1
// 11 ->  1
// 12 ->  1
// press 1 to enter new file or 0 to exit:1
//
// Enter the starting block and length of the file: 8 4
//
// 1 -> Block already allocated
// 1 -> Block already allocated
// 1 -> Block already allocated
// 1 -> Block already allocated
// 1 -> Block already allocated
// 13 ->  1
// 14 ->  1
// 15 ->  1
// 16 ->  1
// press 1 to enter new file or 0 to exit:0
//
//--------------------------------
//Process exited after 45.09 seconds with return value 0
//Press any key to continue . . .

