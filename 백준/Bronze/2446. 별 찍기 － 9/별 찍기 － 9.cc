#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int w, x, y;
	int i, a, b;
	for(w=0;w<n;w++)
	{
		for(x=0;x<w;x++)
			printf(" ");
		for(y=0;y<2*(n-w)-1;y++)
			printf("*");
		printf("\n");
	}
	for(i=n-1;i>0;i--)
	{
		for(a=i-1;a>0;a--)
			printf(" ");
		for(b=0;b<2*(n-i+1)-1;b++)
			printf("*");
		printf("\n");
	}
	return 0;
}