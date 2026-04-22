#include <stdio.h>
using namespace std;

int main() {
	int N, W, u, v, L = 0;
	scanf("%d%d", &N, &W);
	int A[500001] = {};
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &u, &v);
		A[u]++; A[v]++;
	}
	for (int i = 2; i <= N; i++)	L += A[i] == 1;
	printf("%.6f", (double)W / L);
}