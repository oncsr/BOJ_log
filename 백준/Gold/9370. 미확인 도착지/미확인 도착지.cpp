#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		vector<vector<ii> > V(2001);
		vector<int> des;
		int n, m, t, s, g, h;
		for (cin >> n >> m >> t >> s >> g >> h; m--;) {
			int a, b, d;
			cin >> a >> b >> d;
			if (!((a == g && b == h) || (a == h && b == g)))	d *= 10;
			else	d *= 9;
			V[a].push_back({ d,b });
			V[b].push_back({ d,a });
		}
		for (int i = 0; i < t; i++) {
			int a;
			cin >> a;
			des.push_back(a);
		}
		sort(des.begin(), des.end());

		vector<ii> dist(2001, { -1,0 });
		priority_queue<ii, vector<ii>, greater<> > PQ;
		PQ.push({ 0,s });
		dist[s].first = 0;
		while (!PQ.empty()) {
			int d = PQ.top().first;
			int node = PQ.top().second;
			PQ.pop();
			if (d > dist[node].first)	continue;
			for (ii next : V[node]) {
				int spec = dist[node].second;
				if ((node == g && next.second == h) || (node == h && next.second == g))	spec = 1;
				if (dist[next.second].first == -1 || dist[next.second].first > next.first + dist[node].first) {
					dist[next.second] = { dist[node].first + next.first, spec };
					PQ.push({ dist[next.second].first, next.second });
				}
			}
		}
		for (int i : des) {
			if (dist[i].second)	cout << i << ' ';
		}
		cout << '\n';
	}
}