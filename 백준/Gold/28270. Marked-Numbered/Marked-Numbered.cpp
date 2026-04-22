#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	vector<vector<int> > T(1000001);
	int prev = 0;
	int level_last[1000001]{};
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (a - prev > 1) {
			// impossible case
			cout << -1;
			return 0;
		}
		T[level_last[a - 1]].push_back(i);
		T[i].push_back(level_last[a - 1]);
		level_last[a] = i;
		prev = a;
	}
	int ans[1000001]{};
	int visit[1000001]{};
	queue<ii> Q;
	Q.push({ 0,1 });
	visit[0]++;
	while (!Q.empty()) {
		int now = Q.front().first;
		int val = Q.front().second;
		ans[now] = val;
		Q.pop();
		int v = 1;
		for (int next : T[now]) {
			if (!visit[next]) {
				Q.push({ next, v++ });
				visit[next]++;
			}
		}
	}
	for (int i = 1; i <= N; i++)	cout << ans[i] << ' ';
}