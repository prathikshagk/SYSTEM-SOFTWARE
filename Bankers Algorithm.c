#include<stdio.h>
#include<stdlib.h>
int main()
{
	int max[10][10],alloc[10][10],need[10][10],avail[10],completed[10],safeSequence[10];
	int p,r,i,j,process,count;
	count=0;
	printf("Enter number of processes\n");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	completed[i]=0;
	printf("Enter number of resources\n");
	scanf("%d",&r);
	printf("Enter Maximum matrix\n");
	for(i=0;i<p;i++)
	{
		printf("For process %d\n",i+1);
		for(j=0;j<r;j++)
		scanf("%d",&max[i][j]);
	}
    printf("Enter Allocation matrix\n");
	for(i=0;i<p;i++)
	{
		printf("For process %d\n",i+1);
		for(j=0;j<r;j++)
		scanf("%d",&alloc[i][j]);
	}
	printf("Enter Available resources\n");
	for(i=0;i<r;i++)
	scanf("%d",&avail[i]);
	for(i=0;i<p;i++)
	for(j=0;j<r;j++)
	need[i][j]=max[i][j]-alloc[i][j];
	do
	{
		printf("\nMax Matrix\tAllocation Matrix\n");
		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
			printf("%d",max[i][j]);
			printf("\t\t");
			for(j=0;j<r;j++)
			printf("%d",alloc[i][j]);
			printf("\n");
		}
		process=-1;
		for(i=0;i<p;i++)
		{
			if(completed[i]==0)
			{
				process=i;
				for(j=0;j<r;j++)
				{
					if(avail[j]<need[i][j])
					{
						process=-1;
						break;
					}
				}
			}
			if(process!=-1)
			break;
		}
		if(process!=-1)
		{
			safeSequence[count]=process+1;
			count++;
			for(j=0;j<r;j++)
			{
				avail[j]+=alloc[process][j];
				alloc[process][j]=0;
				max[process][j]=0;
				completed[process]=1;
			}
		}
	}while(count!=p && process!=-1);
	if(count==p)
	{
		printf("Safe state\n");
		printf("safe sequence\n");
		for(i=0;i<p;i++)
		printf("%d",safeSequence[i]);
	}
	else
	printf("Unsafe state");
}
