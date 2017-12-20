#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int main()
{
	int orate,drop=0,cap,x,count=0,
	inp[10]={0},i=0,nsec,ch;
	printf("\nenter bucket size : ");
	scanf("%d",&cap);
	printf("\nenter output rate :");
	scanf("%d",&orate);
	do
	{
		printf("\nenter number of packets coming at second %d : ",i+1);
		scanf("%d",&inp[i]);
		i++;
		printf("\nenter 1 to contiue or 0 to quit\n");
		scanf("%d",&ch);
	}while(ch);
	nsec=i;
	printf("\nsecond\trecieved\tsent\tdropped\tremained \n");
	for(i=0;count || i<nsec;i++)
	{
		printf("%d\t",i+1);
		printf("%d\t\t",inp[i]);
		printf("%d\t",MIN((inp[i]+count),orate));
		if((x=inp[i]+count-orate)>0)
		{
			if(x>cap)
			{
				count=cap;
				drop=x-cap;
			}
			else
			{
				count=x;
				drop=0;
			}
		}
		else
		{
			drop=0;
			count=0;
		}
		printf("%d\t%d\n",drop,count);
	}
	return 0;
}

