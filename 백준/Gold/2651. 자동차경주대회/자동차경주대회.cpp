#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll dist[102]{};	// dist[i] = i에서 i+1로 가는 거리
	ll rep[102]{};		// rep[i] = i번 정비소에서 정비하는 시간

	ll R;
	cin >> R;
	vector<ll> dp(102, 1e18);	// dp[i] = i번 정비소에서 정비를 받을 경우
	vector<vector<int>> way(102);
	int N;
	cin >> N >> dist[0];
	ll S = dist[0];
	for (int i = 1; i <= N; i++)	cin >> dist[i], S += dist[i];
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> rep[i];
		ll sum = 0;
		for (int j = i - 1; j >= 0; j--) {
			sum += dist[j];
			if (sum <= R) {
				if (dp[j] + rep[i] < dp[i]) {
					dp[i] = min(dp[i], dp[j] + rep[i]);
					way[i] = way[j];
					way[i].push_back(i);
				}
			}
			else	break;
		}
	}
	ll sum = 0;
	for (int j = N; j >= 0; j--) {
		sum += dist[j];
		if (sum <= R) {
			if (dp[j] < dp[N + 1]) {
				dp[N + 1] = min(dp[N + 1], dp[j]);
				way[N + 1] = way[j];
			}
		}
		else	break;
	}
	if (S <= R) { cout << "0\n0\n"; return 0; }
	cout << dp[N + 1] << '\n';
	cout << way[N + 1].size() << '\n';
	for (int i : way[N + 1])	cout << i << ' ';
}