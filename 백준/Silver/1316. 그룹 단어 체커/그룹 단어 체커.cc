#include <stdio.h>

int main(void) {
	char a[100][101] = {};
	int count = 0;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", a + i);

		int alphabet[26] = {};
		bool success = true;
		char temp = '0';

		for (int j = 0; *(*(a + i) + j) != NULL; j++) {

			char now = *(*(a + i) + j) - 'a';
			if (alphabet[now] != 0) {
				if (now != temp) {
					success = false;
					break;
				}
			}
			temp = *(*(a + i) + j) - 'a';
			alphabet[*(*(a + i) + j) - 'a']++;
		}
		if (success == true)
			count++;
	}
	printf("%d", count);
	return 0;
}