#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int start = 0, end = 0;
	for (int i = 0; i < 16; i++) {
		char a;
		cin >> a;
		if (a == 'L')	start |= (1 << i);
	}
	for (int i = 0; i < 16; i++) {
		char a;
		cin >> a;
		if (a == 'L')	end |= (1 << i);
	}

	int vis[1 << 16]{};
	vis[start]++;
	queue<pair<int, int>> Q;
	Q.emplace(start, 0);
	while (!Q.empty()) {
		auto [now, time] = Q.front();
		Q.pop();
		if (now == end) {
			cout << time;
			return 0;
		}
		for (int i = 0; i < 16; i++) {
			if (i < 12) {
				bool up = now & (1 << i);
				bool down = now & (1 << (i + 4));
				if (up ^ down) {
					int next = now ^ (1 << i) ^ (1 << (i + 4));
					if (!vis[next]) {
						vis[next]++;
						Q.emplace(next, time + 1);
					}
				}
			}
			if (i % 4 != 3) {
				bool left = now & (1 << i);
				bool right = now & (1 << (i + 1));
				if (left ^ right) {
					int next = now ^ (1 << i) ^ (1 << (i + 1));
					if (!vis[next]) {
						vis[next]++;
						Q.emplace(next, time + 1);
					}
				}
			}
		}
	}

}