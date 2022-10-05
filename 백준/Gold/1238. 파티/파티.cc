#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, X, a, b, c, start, mx = 0, g[1001]{};
	cin >> N >> M >> X;
	vector<vector<ii> > Graph(1001);
	for (; M--;) {
		cin >> a >> b >> c;
		Graph[a].push_back({ b,c });
	}
	for (int i = 1; i <= N; i++) {
		if (i == X) {
			g[i] = 0;
			continue;
		}
		start = i;
		int d[1001]{};
		for (int j = 1; j <= N; j++) {
			d[j] = -1;
			if (start == j)	d[j] = 0;
		}
		priority_queue<ii, vector<ii>, greater<> > Q;
		Q.push({ 0,start });
		while (!Q.empty()) {
			int dist = Q.top().first;
			int node = Q.top().second;
			Q.pop();
			if (dist > d[node])	continue;
			for (ii next : Graph[node]) {
				if (d[next.first] == -1 || d[next.first] > dist + next.second) {
					d[next.first] = dist + next.second;
					Q.push({ d[next.first], next.first });
				}
			}
		}
		g[i] = d[X];
	}
	int d[1001]{};
	for (int i = 1; i <= N; i++) {
		d[i] = -1;
		if (i == X)	d[i] = 0;
	}
	priority_queue<ii, vector<ii>, greater<> > Q;
	Q.push({ 0,X });
	while (!Q.empty()) {
		int dist = Q.top().first;
		int node = Q.top().second;
		Q.pop();
		if (dist > d[node])	continue;
		for (ii next : Graph[node]) {
			if (d[next.first] == -1 || d[next.first] > dist + next.second) {
				d[next.first] = dist + next.second;
				Q.push({ d[next.first], next.first });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		mx = max(mx, g[i] + d[i]);
	}
	cout << mx;
}