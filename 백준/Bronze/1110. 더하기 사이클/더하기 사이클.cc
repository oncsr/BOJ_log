#include <stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	const int fir = n;
	int i=0;
	int num, temp;
	do{
		temp = n/10 + n%10;
		if(temp > 9)	temp-=10;
		num = (n%10)*10 + temp;
		n = num;	i++;
	}while(fir != n);
	printf("%d\n", i);
}