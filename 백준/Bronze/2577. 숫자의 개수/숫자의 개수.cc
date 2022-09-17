#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int result = a * b * c;
	int ans[10] = {0};
	
	for(int j=1 ; result/j > 0 ; j=j*10)
		ans[(result/j)%10]++;
		
	for(int i=0;i<10;i++)
		printf("%d\n", ans[i]);
	
	return 0;
}