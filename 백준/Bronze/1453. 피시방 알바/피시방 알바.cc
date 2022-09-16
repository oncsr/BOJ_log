#include <stdio.h>

int main(void)
{
	int n, a=0;
	int arr[100];
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		for(int j=0;j<n;j++)
		{
			if(i<j)
				break;
			else if(i==j)
				continue;
			else if(arr[i]==arr[j])
			{
				a++;
				break;
			}
			else
				continue;
		}
	}
	printf("%d\n", a);
	return 0;
}