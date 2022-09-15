#include <stdio.h>
#include <string.h>

int main() {
	char a[51], c[51];
	scanf("%s", a, 51);
	int s = strlen(a);
	bool no = true;
	for (int i = 1; i < s - 1; i++) {
		for (int j = i + 1; j < s; j++) {
			char b[51]{};
			int k = 0, n;
			for (n = i - 1; n >= 0; n--)	b[k++] = a[n];
			for (n = j - 1; n >= i; n--)	b[k++] = a[n];
			for (n = s - 1; n >= j; n--)	b[k++] = a[n];
			if (no) {
				strcpy(c, b);
				no = false;
				continue;
			}
			bool big = false;
			for (int g = 0; g < s; g++) {
				if (b[g] == c[g])	continue;
				else if (b[g] > c[g])	break;
				else {
					big = true;
					break;
				}
			}
			if (big)	strcpy(c, b);
		}
	}
	printf("%s", c);
}