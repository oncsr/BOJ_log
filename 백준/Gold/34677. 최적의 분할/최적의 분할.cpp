#include <bits/stdc++.h>
using namespace std;

int N;
int a[3000]{}, b[3000]{}, dp[3000]{};
bool poss[3000][3000]{};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];

	for (int i = 0; i < N; i++) {
		int aMin = 12345, aIdx = i;
		int bMin = 12345, bIdx = i;
		for (int j = i; j < N; j++) {
			if (a[j] < aMin) aMin = a[j], aIdx = j;
			if (b[j] < bMin) bMin = b[j], bIdx = j;
			poss[i][j] = aIdx == bIdx;
		}
	}
	for (int i = 0; i < N; i++) {
		dp[i] = poss[0][i] ? 1 : 12345;
		for (int j = 0; j < i; j++) if (poss[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
	}

	cout << dp[N - 1];

}