#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> > > V(100001);
int s = 0, mn = 0;
int N, S, E;
vector<int> way;

bool dfs(int n, int p, int d) {
	if (n == E) {
		mn = s = d;
		return true;
	}
	for (pair<int, int> i : V[n]) {
		int next = i.first, cost = i.second;
		bool f = 0;
		if (next != p) {
			f |= dfs(next, n, d + cost);
			if (f) {
				way.push_back(next);
				return true;
			}
		}
	}
	return false;
}

void dfs2(int n, int p, int id, int tar) {
	for (pair<int, int> i : V[n]) {
		int next = i.first, cost = i.second;
		if (next == tar) {
			mn = min(mn, s - cost);
			if (id < way.size() - 1)	dfs2(next, n, id + 1, way[id + 1]);
			else	return;
		}
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> S >> E;
	for (int i = 1; i < N; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		V[u].push_back({ v,d });
		V[v].push_back({ u,d });
	}
	dfs(S, 0, 0);
	way.push_back(S);
	int id = 0;
	dfs2(way[id], 0, id + 1, way[id + 1]);
	cout << mn;
}