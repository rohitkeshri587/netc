//Dijkstra's 

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
	int visited[10];
	printf("\nEnter the Source Node: ");
	scanf("%d",&s);
	for(int i=0;i<n;i++)
	{
		d[i]=a[s][i];
		visited[i]=0;
	}
	visited[s]=1;

	for(int i=1;i<n;i++)
	{
		int min=999,u;
		for(int j=0;j<n;j++)
			if(visited[j]==0 && d[j]<min)
			{
				min=d[j];
				u=j;
			}

		for(int k=0;k<n;k++)
			if(visited[k]==0 && d[k]>d[u]+a[u][k])
				d[k]=d[u]+a[u][k];

		visited[u]=1;
	}

	for(int i=0;i<n;i++)
		printf("Distance to Node %d = %d\n",i,d[i]);
}
