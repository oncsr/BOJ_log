#include <stdio.h>

int main(void)
{
	int n;	scanf("%d", &n);
	
	int i=1, result=0;
	while(i<=n)
	{
		if(i==1000)	break;
		int nn[3];
		for(int k=2,j=1 ; i/j > 0 ; k--,j=j*10)
			nn[k] = (i/j) % 10;
		
		if(nn[0] == '\0')	result++;
		else if(nn[0] - nn[1] == nn[1] - nn[2])	result++;
		
		i++;
	}
	printf("%d\n", result);
	return 0;
}