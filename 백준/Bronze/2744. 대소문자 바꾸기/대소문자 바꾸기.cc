#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[100];
	scanf("%s", s);
	for(int i=0;i<strlen(s);i++)
		if(s[i]>=97)
			s[i] -= 32;
		else
			s[i] += 32;
	printf("%s\n", s);
	return 0;
}