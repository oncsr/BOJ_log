#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;
	if (N == K) { cout << 0; return 0; }
	vector<vector<int>> vis(500001, vector<int>(2, -1));
	vector<int> pos(500001);
	vis[N][0] = 0;
	int T = 0;
	for (; K + T <= 500000; T++) {
		K += T;
		pos[T] = K;
	}
	queue<pair<int, int>> Q;
	Q.emplace(N, 0);
	while (!Q.empty()) {
		auto [now, time] = Q.front();
		Q.pop();
		if (time >= T)	break;
		if (now + 1 <= 500000 && vis[now + 1][(time + 1) & 1] == -1) {
			Q.emplace(now + 1, time + 1);
			vis[now + 1][(time + 1) & 1] = time + 1;
		}
		if (now - 1 >= 0 && vis[now - 1][(time + 1) & 1] == -1) {
			Q.emplace(now - 1, time + 1);
			vis[now - 1][(time + 1) & 1] = time + 1;
		}
		if (now * 2 <= 500000 && vis[now * 2][(time + 1) & 1] == -1) {
			Q.emplace(now * 2, time + 1);
			vis[now * 2][(time + 1) & 1] = time + 1;
		}
	}
	for (int t = 0; t < T; t++) {
		int P = vis[pos[t]][t & 1];
		if (P == -1)	continue;
		if (((P & 1) == (t & 1)) && P <= t) { cout << t; return 0; }
	}
	cout << -1;
}