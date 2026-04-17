#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int vis[1024]{};
	bitset<10> a, b;
	cin >> a >> b;
	int L = a.to_ulong(), K = b.to_ulong();
	vis[L]++;
	queue<pair<int, int>> Q;
	Q.emplace(L, 0);
	while (!Q.empty()) {
		auto [now, t] = Q.front();
		Q.pop();
		if (now == K) {
			cout << t;
			return 0;
		}
		if (now + 1 < 1024 && !vis[now+1]) {
			vis[now + 1]++;
			Q.emplace(now + 1, t + 1);
		}
		if (now - 1 >= 0 && !vis[now - 1]) {
			vis[now - 1]++;
			Q.emplace(now - 1, t + 1);
		}
		for (int i = 0; i < 10; i++) {
			if ((1 << i) > (now >> 1))	break;
			int next = now ^ (1 << i);
			if (!vis[next]) {
				vis[next]++;
				Q.emplace(next, t + 1);
			}
		}
	}

}