#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	char s[9];
	int j, k;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		j = (s[0]-65)*26*26 + (s[1]-65)*26 + (s[2]-65);
		k = 1000*(s[4]-48) + 100*(s[5]-48) + 10*(s[6]-48) + s[7]-48;
		if(j>k)
			if(j-k<=100)
				printf("nice\n");
			else
				printf("not nice\n");
		else
			if(k-j<=100)
				printf("nice\n");
			else
				printf("not nice\n");
		j=0, k=0;
	}
	return 0;
}