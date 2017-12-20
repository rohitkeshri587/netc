//Bellman-Ford

#include<stdio.h>
#include<stdlib.h>

void main()
{

	int a[10][10],n,s;
	printf("\nEnter Number of Vertices:");
	scanf("%d",&n);
	printf("\nEnter the Adjacency Matrix:-\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(i!=j && a[i][j]==0)
				a[i][j]=999;
		}

	int d[10];
	for(int i=0;i<n;i++)
		d[i]=999;
	int p[10]={-1};
	printf("\nEnter the Source Node: ");
	scanf("%d",&s);
	d[s]=0;
		
	for(int k=1;k<n;k++)
	{	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(d[j]>d[i]+a[i][j])
				{
					d[j]=d[i]+a[i][j];
					p[j]=i;
				}
				
			}	
		}	
	}
	

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[j]>d[i]+a[i][j])
			{
				printf("\nThe Graph contains Negative Cycles!\n");
				exit(0);
			}
		}	
	}

	for(int i=0;i<n;i++)
		printf("Distance to Node %d = %d\n",i,d[i]);
	

}
	
