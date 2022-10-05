#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
long long N, M, a[100001]{}, u, v, w;
vector<vector<ii> > V(100001);

long long dijkstra(int start, int end) {
	long long d[100001]{};
	for (int i = 0; i < N; i++)	d[i] = -1;
	d[start] = 0;
	priority_queue<ii, vector<ii>, greater<> > Q;
	Q.push({ 0,start });
	while (!Q.empty()) {
		long long dist = Q.top().first;
		long long node = Q.top().second;
		Q.pop();
		if (dist > d[node])	continue;
		for (ii next : V[node]) {
			if (a[next.first] && (next.first != N - 1))	continue;
			if (d[next.first] == -1 || d[next.first] > dist + next.second) {
				d[next.first] = dist + next.second;
				Q.push({ d[next.first],next.first });
			}
		}
	}
	return d[end];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> a[i];
	for (; M--;) {
		cin >> u >> v >> w;
		V[u].push_back({ v,w });
		V[v].push_back({ u,w });
	}
	cout << dijkstra(0, N - 1);
}