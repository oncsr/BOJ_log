#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int V, E, start;
	vector<vector<ii> > Graph(20001);	// { 비용,도착점 }
	cin >> V >> E >> start;
	for (; E--;) {
		int u, v, w;
		cin >> u >> v >> w;
		Graph[u].push_back({ w,v });
	}
	priority_queue<ii, vector<ii>, greater<> > PQ;
	vector<int> dist(V + 1, -1);
	dist[start] = 0;
	PQ.push({ 0,start });
	while (!PQ.empty()) {
		int distance = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();
		if (distance > dist[node])	continue;
		for (ii next : Graph[node]) {
			if (dist[next.second] == -1 || dist[next.second] > next.first + dist[node]) {
				dist[next.second] = next.first + dist[node];
				PQ.push({ dist[next.second], next.second });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == -1)	cout << "INF\n";
		else	cout << dist[i] << '\n';
	}
}