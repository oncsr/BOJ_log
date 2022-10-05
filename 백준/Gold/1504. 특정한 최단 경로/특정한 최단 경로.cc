#include <iostream>
#include <queue>
using namespace std;
using ii = pair<int, int>;
int N, M, a, b, c, v1, v2, s = 0, q = 2, ans;
vector<vector<ii> > V(801);

int dijkstra(int start, int end) {
	int d[801]{};
	for (int i = 1; i <= N; i++)	d[i] = -1;
	d[start] = 0;
	priority_queue<ii, vector<ii>, greater<> > Q;
	Q.push({ 0,start });
	while (!Q.empty()) {
		int dist = Q.top().first;
		int node = Q.top().second;
		Q.pop();
		if (dist > d[node])	continue;
		for (ii next : V[node]) {
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
	cin >> N;
	for (cin >> M; M--;) {
		cin >> a >> b >> c;
		V[b].push_back({ a,c });
		V[a].push_back({ b,c });
	}
	cin >> v1 >> v2;
	int vv = dijkstra(v1, v2);
	int p1 = dijkstra(1, v1);
	int p2 = dijkstra(v1, N);
	int p3 = dijkstra(1, v2);
	int p4 = dijkstra(v2, N);
	if ((p1 == -1 && p2 == -1) || (p3 == -1 && p4 == -1))	cout << -1;
	else if ((p1 == -1 && p3 == -1) || (p2 == -1 && p4 == -1))	cout << -1;
	else {
		if (p1 == -1 && p4 == -1)	cout << vv + p2 + p3;
		else if (p2 == -1 && p3 == -1)	cout << vv + p1 + p4;
		else if (p1 == -1 || p4 == -1)	cout << vv + p2 + p3;
		else if (p2 == -1 || p3 == -1)	cout << vv + p1 + p4;
		else	cout << min(vv + p1 + p4, vv + p2 + p3);
	}
}