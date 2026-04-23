#include <stdio.h>

int main(void) {
	char a[4]{};
	char b[4]{};
	scanf("%s", a);
	scanf("%s", b);
	
	char* pa = a + 2;
	char* pb = b + 2;
	
	int aa = (*pa - '0') * 100;
	pa--;
	aa += (*pa - '0') * 10;
	pa--;
	aa += (*pa - '0') * 1;

	int bb = (*pb - '0') * 100;
	pb--;
	bb += (*pb - '0') * 10;
	pb--;
	bb += (*pb - '0') * 1;

	if (aa > bb)
		printf("%d", aa);
	else
		printf("%d", bb);

	return 0;
}