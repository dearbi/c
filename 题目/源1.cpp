#include <stdio.h>
int main()
{
	int n=0;
	int isprime=1;
	int count=0;
	scanf("%d",&n);
	for(int i=2;i<n;i++)
	{
		isprime=1;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				isprime=0;
				break;
			}
		}
		if(isprime)
		{
			printf("%d ",i);
			count++;
			if(count%10==0)
			{
				printf("\n");
			}
		}
	}

	
	return 0;
}