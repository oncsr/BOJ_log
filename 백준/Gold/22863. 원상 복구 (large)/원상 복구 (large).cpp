#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int dp[64][1000001]{};
	int N;
	ll K;
	cin >> N >> K;
	int order[1000001]{};
	for (int i = 1; i <= N; i++)	cin >> order[i];
	for (int i = 1; i <= N; i++)	cin >> dp[0][i];
	for (int i = 1; i < 64; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];

	int ans[1000001]{};
	int perform[65]{}, id = 0;
	int g = 0;
	while (K > 0) {
		if (K % 2)	perform[id++] = g;
		K >>= 1;
		g++;
	}
	for (int i = 1; i <= N; i++) {
		int s = i;
		for (int j = 0; j < id; j++)	s = dp[perform[j]][s];
		ans[s] = order[i];
	}
	for (int i = 1; i <= N; i++)	cout << ans[i] << ' ';

}