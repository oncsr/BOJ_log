#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> V(10001);
	vector<vector<int>> P(10001);
	int dp[10001]{}, in[10001]{};
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		in[b]++;
		V[a].emplace_back(b, c);
	}

	int s, e;
	cin >> s >> e;

	queue<int> Q;
	Q.emplace(s);

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (auto [i, c] : V[now]) {
			int res = dp[now] + c;
			if (res > dp[i]) {
				P[i] = { now };
				dp[i] = res;
			}
			else if (res == dp[i])	P[i].push_back(now);
			if (!(--in[i]))	Q.push(i);
		}
	}

	cout << dp[e] << '\n';
	int vis[10001]{}, cnt = 0;

	vis[e]++;
	Q.push(e);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i : P[now]) {
			cnt++;
			if (vis[i])	continue;
			Q.push(i);
			vis[i]++;
		}
	}
	cout << cnt;

}