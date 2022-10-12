#include <stdio.h>

int main(void)
{
	int arr[30];
	int sum=465, ch=0, a, b;
	for(int i=0;i<28;i++)
	{
		scanf("%d", &arr[i]);
		sum-=arr[i];
	}
	for(int j=1;j<=30;j++)
	{
		for(int k=0;k<28;k++)
		{
			if(arr[k]!=j)
				ch++;
			if(ch==28)
				a=j;
		}
        ch=0;
	}
	b=sum-a;
	if(b>a)
		printf("%d\n%d\n", a, b);
	else
		printf("%d\n%d\n", b, a);
	return 0;
}