#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int N, K, A[10001];
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 2; i <= N; i++) {
		int loc = i - 1;
		int newItem = A[i];

		while (1 <= loc && newItem < A[loc]) {
			K--;
			if (K == 0) {
				printf("%d", A[loc]);
				return 0;
			}
			A[loc + 1] = A[loc];
			loc--;
		}
		if (loc + 1 != i) {
			K--;
			if (K == 0) {
				printf("%d", newItem);
				return 0;
			}
			A[loc + 1] = newItem;
		}
	}

	printf("-1");

}