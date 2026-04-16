#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll L, N, K;
	cin >> L >> N >> K;

	map<ll, int> vis;	// 방문 표시를 위한 map
	queue<pair<ll, int>> Q;	// BFS를 수행할 queue
	ll cnt = K;			// 출력 횟수를 카운트할 변수

	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		vis[a] = 1;
		if (cnt) {
			Q.emplace(a, 1);
			cnt--;
		}
	}

	// 출력 횟수가 K를 넘지 않을 동안만 BFS 수행
	while (!Q.empty()) {
		auto [n, t] = Q.front();
		Q.pop();
		cout << t - 1 << '\n';

		// 양 옆 위치에 전파
		if (cnt && vis.find(n - 1) == vis.end() && n - 1 >= 0) {
			vis[n - 1] = t + 1;
			Q.emplace(n - 1, t + 1);
			cnt--;
		}
		if (cnt && vis.find(n + 1) == vis.end() && n + 1 <= L) {
			vis[n + 1] = t + 1;
			Q.emplace(n + 1, t + 1);
			cnt--;
		}
	}

}