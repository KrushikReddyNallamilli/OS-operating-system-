#include<stdio.h>
main()
{
	int f[50],i,st,len,c;
	for(i=0;i<50;i++)
	    f[i]=0;
	START:
	    printf("\n Enter the starting block and length of the file: ");
		scanf("%d%d",&st,&len);
		for(i=st;i<(st+len);i++)
		if(f[i]==0)
		{
			f[i]=1;
			printf("\n %d ->  %d",i,f[i]);
			}
		else
		{
			printf("Block already allocated");
			break;
		}
		if(i==(st+len))
		    printf("\n The file is allocated to disk");
		printf("\n press 1 to enter new file or 0 to exit:");
		scanf("%d",&c);
		if(c==1)
		    goto START;
			 	 	     
}
// OUTPUT
// Enter the starting block and length of the file: 7 6
//
// 7 ->  1
// 8 ->  1
// 9 ->  1
// 10 ->  1
// 11 ->  1
// 12 ->  1
// The file is allocated to disk
// press 1 to enter new file or 0 to exit:1
//
// Enter the starting block and length of the file: 10 5
//Block already allocated
// press 1 to enter new file or 0 to exit:
