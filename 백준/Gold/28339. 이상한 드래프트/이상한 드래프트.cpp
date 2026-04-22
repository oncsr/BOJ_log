#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int N, K;
		cin >> N >> K;
		priority_queue<ii> Q[10]{};
		int mx = 0;
		for (int i = 1; i <= N; i++) {
			int p, a;
			cin >> p >> a;
			Q[p].push({ a,i });
			if (i < K)	continue;
			for (int j = 1; j < 10; j++) {
				while (!Q[j].empty() && Q[j].top().second + K <= i)	Q[j].pop();
			}
			int ok = 0;
			for (int j = 1; j < 10; j++)	ok += (!Q[j].empty());
			if (ok < 9)	continue;
			int s = 0;
			for (int j = 1; j < 10; j++)	s += Q[j].top().first;
			mx = max(mx, s);
		}
		cout << mx << '\n';
	}
}