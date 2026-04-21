#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int sales[301][10001]{}, N, M, K, Q;
int king[10001]{};	// 각 매장의 매출왕
int cnt[301]{};		// 각 직원의 매출왕 수 (K와 같아지면 영업왕이 됨)
int ans = 0;
// L[i] = i번 매장에서의 { 매출액, 직원 }
vector<vector<ii>> L(10001);

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < K; j++) {
			int a, b;
			cin >> a >> b;
			sales[i][a] = b;
			L[a].push_back({ b,i });
		}
	}

	for (int j = 1; j <= M; j++) {
		if (L[j].empty())	continue;
		sort(L[j].begin(), L[j].end());
		int G = L[j].back().second;
		king[j] = G;
		cnt[G]++;
		if (cnt[G] == K)	ans++;
	}

	for (cin >> Q; Q--;) {
		int i, j, v;
		cin >> i >> j >> v;
		int s = sales[i][j] + v;
		sales[i][j] = s;
		if (s > L[j].back().first) {
			int fail = L[j].back().second;
			if (cnt[fail] == K)	ans--;
			cnt[fail]--;
			L[j].push_back({ s, i });
			cnt[i]++;
			if (cnt[i] == K)	ans++;
		}
		cout << ans << '\n';
	}
}