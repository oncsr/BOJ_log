#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	while(a>0)
	{
		if(a>100000)
			break;
		printf("%d\n", a);
		a--;
	}
	return 0;
}