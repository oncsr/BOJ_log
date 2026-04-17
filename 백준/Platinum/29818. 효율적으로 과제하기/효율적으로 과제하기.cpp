#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[i] = 과제 집합 i를 해결한 경우의 최대 점수
int dp[1 << 20]{}, N;
int take[1 << 20]{};
int T[20]{}, D[20]{}, P[20]{};

void tim(int pos, int state, int v) {
	if (pos == N) { take[state] = v; return; }
	tim(pos + 1, state, v);
	tim(pos + 1, state | (1 << pos), v + T[pos]);
}

int sol(int k) {
	if (!k)	return dp[k] = 0;
	if (dp[k] != -1)	return dp[k];
	for (int i = 0; i < N; i++) {
		if (!(k & (1 << i)))	continue;
		int cur = take[k ^ (1 << i)], need = T[i], dead = D[i];
		int res = sol(k ^ (1 << i));
		if (cur + need <= dead)	dp[k] = max(dp[k], res + P[i]);
		else if (cur + need <= dead + 24)	dp[k] = max(dp[k], res + P[i] / 2);
		else	dp[k] = max(dp[k], res);
	}
	return dp[k];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	fill(dp, dp + (1 << 20), -1);
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> T[i] >> D[i] >> P[i];
	tim(0, 0, 0);
	sol((1 << N) - 1);

	int mx = -100;
	int ans = 0;
	for (int i = 0; i < (1 << N); i++) {
		if (dp[i] > mx || (dp[i] == mx && take[i] < ans))	mx = dp[i], ans = take[i];
	}
	cout << mx << ' ' << ans;

}