#include<stdio.h>
#define MAX 10000

typedef struct 
{
	int p,w,id;
	float ratio;
	float x;
}item;

int main()
{
	item i[MAX],temp;
	int n,M,j,k;
	float cp=0,	cw=0;
	
	printf("\nEnter no. of items: ");
	scanf("%d",&n);
	printf("\nEnter sack capacity: ");
	scanf("%d",&M);

	for(j=0;j<n;j++)
	{
     	printf("Enter Profit & Weight: ");
        scanf("%d%d", &i[j].p,&i[j].w);
        i[j].ratio = i[j].p*1.0/i[j].w ;
        i[j].id = j;
        i[j].x=0;
    }
    
    for(j=0;j<n-1;j++)
	{
		for(k=0;k<n-1;k++)
		{
			if(i[k].ratio<i[k+1].ratio)
			{
				temp=i[k];
				i[k]=i[k+1];
				i[k+1]=temp;
			}
		}	
	}
	
	for(j=0;j<n;j++)
	{
		if(cw+i[j].w<M)
		{
			i[j].x=1;
			cp+=i[j].p;
			cw+=i[j].w;
		}
		
		else
		{
			i[j].x=(M-cw)*1.0/i[j].w;
			cp+=i[j].p*i[j].x;
			cw=M;
		}
	}
    
    for(j=0;j<n-1;j++)
	{
		for(k=0;k<n-1;k++)
		{
			if(i[k].id>i[k+1].id)
			{
				temp=i[k];
				i[k]=i[k+1];
				i[k+1]=temp;
			}
		}	
	}
    
    printf("\nItem_no.\tProfit\t\tWeight\t\tRatio\t\tSelected\n");
    
    for(k=0;k<n;k++)
	{
		printf("%d\t\t%d\t\t%d\t\t%f\t%f\n",(i[k].id+1),i[k].p,i[k].w,i[k].ratio,i[k].x);
	}
    
    printf("\nTotal Profit: %f\tTotal Weight: %f\n",cp,cw);
	
	return 0;
}
