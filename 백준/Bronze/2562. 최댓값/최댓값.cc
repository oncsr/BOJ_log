#include <stdio.h>

int main(void)
{
	int max=0, n=9, a, b;
	while(n>0)
	{
		scanf("%d", &a);
		if(a>max)
		{
			max=a;
			b=10-n;
		}
		n--;
	}
	printf("%d\n%d\n", max, b);
}