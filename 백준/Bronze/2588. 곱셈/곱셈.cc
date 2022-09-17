#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	
	int x, y, z;
	x = b / 100; // x = 3
	y = (b - x * 100) / 10; // y = 8
	z = b - x * 100 - y * 10;
	
	printf("%d\n%d\n%d\n%d\n", a*z, a*y, a*x, a*b);
}