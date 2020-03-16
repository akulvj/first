#include<stdio.h>
#define MAX 999

void all_pairs(int c[50][50],int A[50][50],int n,int D[50][50])
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			A[i][j]=c[i][j];
		
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				{
					if(A[i][j]>A[i][k]+A[k][j])
					{
						A[i][j]=A[i][k]+A[k][j];
						D[i][j]=k+1;
					}
				}
}

void hid_path(int v1,int v2,int A[50][50],int n,int D[50][50],int c[50][50])
{
	int i,j=0,count=0;
	int path[50],pv;

	i=v2;
	path[0]=v2;
	pv=v2;

	while(pv!=v1)
	{
		count++;
		path[++j]=D[v1-1][i-1];
		pv=D[v1-1][i-1];
		if(pv!=v1)
		{
			i=path[j];
		}
	}

	printf("\nHidden Path present from vertex %d to %d :\t",v1,v2);
	for(i=count;i>=0;i--)
	{
		printf("%d  ",path[i]);
	}
	printf("\n");
}

void find_path(int v1,int v2,int A[50][50],int n,int D[50][50],int c[50][50])
{
	int i,j=0,count=0;
	int path[50],pv;
	int length;
	i=v2;
	path[0]=v2;
	pv=v2;

	while(pv!=v1)
	{
		count++;
		path[++j]=D[v1-1][i-1];
		pv=D[v1-1][i-1];
		if(pv!=v1)
		{
			i=path[j];
		}
	}

	printf("\nPath from vertex %d to %d :\t",v1,v2);
	for(i=count;i>=0;i--)
	{
		printf("%d  ",path[i]);
	}
	
	printf("\n");
	for(i=count;i>0;i--)
	{
		if(c[path[i]-1][path[i-1]-1]>=MAX)
		{
			hid_path(path[i],path[i-1],A,n,D,c);
		}	
	}
	
	length=A[v1-1][v2-1];
	printf("Length: %d\n",length);
}

int main()
{
	int n,i,j,ch,v1,v2;
	printf("Enter no. of verices: ");
	scanf("%d",&n);
	
	int c[50][50],A[50][50],D[50][50];
	printf("Enter cost matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&c[i][j]);
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)	
		{
			if(i==j)
				D[i][j]=-1;
			else if(c[i][j]>=MAX)
				D[i][j]=-1;
			else
			{
				D[i][j]=i+1;
			}
		}
			
	all_pairs(c,A,n,D);
	
	printf("\nAdjacency Matrix: ");
	for(i=0;i<n;i++)
	{	printf("\n");
		for(j=0;j<n;j++)
			printf("%d ",A[i][j]);
	}
	
	printf("\n\nDecision Matrix: ");
	for(i=0;i<n;i++)
	{	printf("\n");
		for(j=0;j<n;j++)
			printf("%d ",D[i][j]);
	}
	printf("\n");

	while(1)
	{
		printf("\n1.Find Path\n2.Exit\n");
		printf("Enter choice: ");
		scanf("%d",&ch);
		if(ch==2)
		break;

		else 
		{
			switch(ch)
			{
				case 1 :
				{
					printf("\nEnter start and end vertex to find path: ");
					scanf("%d%d",&v1,&v2);
					if(v1==v2)
					printf("Same start and end vertex\n");
					else if(A[v1-1][v2-1]==MAX)
					printf("No path \n");
					else
					find_path(v1,v2,A,n,D,c);
				}
				break;
				default:
				{
					printf("\nInvalid Choice\n");
				}
			}
		}

	}

	return 0;
}
