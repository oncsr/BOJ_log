#include <stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	int sum = 0, i;
	for(i=1;sum<n;i++)
		sum += i;
	sum = sum - i + 1;
	if(i%2==0)
		printf("%d/%d\n", i-n+sum, n-sum);
	else
		printf("%d/%d\n", n-sum, i-n+sum);
}