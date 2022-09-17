#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int b=n;
	for(int j=0;j<2*n-1;j++)
	{
		for(int k=n;k>b;k--)
			printf(" ");
		for(int i=0;i<2*b-1;i++)
			printf("*");
		b--;
		printf("\n");
	}
	return 0;
}