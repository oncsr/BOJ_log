#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q;
	int dp[20][200001]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> dp[0][i];
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
	for (cin >> Q; Q--;) {
		int a, b;
		cin >> a >> b;
		int ans = b, g = 0;
		while (a > 0) {
			if (a % 2)	ans = dp[g][ans];
			a >>= 1;
			g++;
		}
		cout << ans << '\n';
	}
}