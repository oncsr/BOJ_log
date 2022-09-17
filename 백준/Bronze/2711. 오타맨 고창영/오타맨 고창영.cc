#include <stdio.h>
#include <string.h>

int main(void)
{
	int t;
	scanf("%d",&t);
	int p;
	char s[80];
	for(int i=0;i<t;i++)
	{
		scanf("%d %s",&p,s);
		for(int j=0;j<strlen(s);j++)
			if(j+1==p)
				continue;
			else
				printf("%c",s[j]);
		printf("\n");
	}
	return 0;
}