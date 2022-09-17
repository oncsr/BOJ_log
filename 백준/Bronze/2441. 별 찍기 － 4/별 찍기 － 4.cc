#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int b=n;
	for(int j=0;j<n;j++)
	{
		for(int k=n;k>b;k--)
			printf(" ");
		for(int i=0;i<b;i++)
			printf("*");
		b--;
		printf("\n");
	}
	return 0;
}