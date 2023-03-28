#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int dp[32][100001]{};
	int N, K, M;
	cin >> N >> K >> M;
	int order[100001]{};
	for (int i = 1; i <= N; i++)	cin >> order[i];
	for (int i = 1; i <= K; i++)	cin >> dp[0][i];
	for (int i = 1; i < 32; i++)
		for (int j = 1; j <= K; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
	vector<int> V;
	int g = 0;
	M--;
	while (M > 0) {
		if (M % 2)	V.push_back(g);
		M >>= 1;
		g++;
	}
	for (int i = 1; i <= N; i++) {
		int ans = order[i];
		for (int o : V)	ans = dp[o][ans];
		cout << ans << ' ';
	}
}