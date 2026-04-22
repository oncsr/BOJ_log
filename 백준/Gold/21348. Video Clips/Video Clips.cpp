#include "videoclips.h"

int dp[32][100000]{};
int perform[33]{}, id = 0;
void videos(int K, int M, int S[]) {
	M--;
	int g = 0;
	while (M > 0) {
		if (M % 2)	perform[id++] = g;
		M >>= 1;
		g++;
	}
	for (int i = 0; i < K; i++)	dp[0][i] = S[i];
	for (int i = 1; i < 32; i++)
		for (int j = 0; j < K; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
}

int clip(int I) {
	for (int i = 0; i < id; i++)	I = dp[perform[i]][I];
	return I;
}
