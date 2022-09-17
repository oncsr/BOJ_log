#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d", &a);
	b=a;
	while(a>0)
	{
		if(a>100000)
			break;
		printf("%d\n", b-a+1);
		a--;
	}
	return 0;
}