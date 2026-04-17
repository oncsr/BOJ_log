#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll ans = -1e18, N, arr[9][9]{};
	cin >> N;
	for (int i = 0; i < N; i++)	for (int j = 0; j < N; j++)	cin >> arr[i][j];
	for (int i = 1; i < (1 << N); i++) {
		ll mn = 1e18;
		for (int j = 0; j < (1 << N); j++) {
			ll score = 0;
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					bool a = i & (1 << x), b = j & (1 << y);
					if (a ^ b)	score += arr[x][y];
				}
			}
			mn = min(mn, score);
		}
		ans = max(ans, mn);
	}
	cout << ans;
}