#include <stdio.h>

int main(void)
{
	int b, smallest=100, sum=0;
	for(int a=1;a<=7;a++)
	{
		scanf("%d ", &b);
		if(b%2==1)
		{
			sum+=b;
			if(b<smallest)
				smallest=b;
		}
	}
	if(sum==0)
		printf("-1");
	else
		printf("%d\n%d", sum, smallest);
	return 0;
}