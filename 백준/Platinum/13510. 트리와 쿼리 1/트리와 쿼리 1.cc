#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int> > > V(100001);
int depth[100001]{};
int parent[100001]{};
int sz[100001]{};
pair<int, int> edge[100001]{};	// {자식 번호, 가중치}
vector<vector<int> > chain(100001);
int chain_num[100001]{};
int chain_index[100001]{};
int order[100001]{};

int N, M, a, b, c, id = 0;
int seg[262145]{};

void dfs(int node, int par) {
	parent[node] = par;
	sz[node] = 1;
	for (pair<int, int> next : V[node]) {
		if (next.first != par) {
			dfs(next.first, node);
			sz[node] += sz[next.first];
		}
	}
}

void upt(int s, int e, int idx, int val, int n) {
	if (s == e) {
		seg[n] = val;
		return;
	}
	int m = (s + e) / 2;
	if (idx <= m)	upt(s, m, idx, val, n * 2);
	else	upt(m + 1, e, idx, val, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

void HLD(int node, int par, int start, int dep) {
	depth[node] = dep;
	chain_num[node] = start;
	chain_index[node] = chain[start].size();
	chain[start].push_back(node);

	int heavy = -1;
	order[node] = ++id;
	int w = 0;
	for (pair<int, int> next : V[node]) {
		if (next.first != par && (heavy == -1 || sz[next.first] > sz[heavy])) {
			heavy = next.first;
			w = next.second;
		}
	}
	if (heavy != -1) {
		upt(1, N, id + 1, w, 1);
		HLD(heavy, node, start, dep);
	}
	for (pair<int, int> next : V[node]) {
		if (next.first != par && next.first != heavy) {
			upt(1, N, id + 1, next.second, 1);
			HLD(next.first, node, next.first, dep + 1);
		}
	}
}

int LCA(int a, int b) {
	while (chain_num[a] != chain_num[b]) {
		if (depth[a] > depth[b])	a = parent[chain_num[a]];
		else	b = parent[chain_num[b]];
	}
	return chain_index[a] > chain_index[b] ? b : a;
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
		edge[i] = { a,b };
	}
	dfs(1, 0);
	HLD(1, 0, 1, 0);
	for (cin >> M; M--;) {
		cin >> a >> b >> c;
		if (a == 1) {
			int u = edge[b].first, v = edge[b].second;
			if (parent[u] == v)
				upt(1, N, order[u], c, 1);
			else
				upt(1, N, order[v], c, 1);
		}
		else {
			int g = LCA(b, c);
			int mx = 0;
			while (chain_num[b] != chain_num[g]) {
				mx = max(mx, find(1, N, order[chain_num[b]], order[b], 1));
				b = parent[chain_num[b]];
			}
			mx = max(mx, find(1, N, order[g] + 1, order[b], 1));
			while (chain_num[c] != chain_num[g]) {
				mx = max(mx, find(1, N, order[chain_num[c]], order[c], 1));
				c = parent[chain_num[c]];
			}
			mx = max(mx, find(1, N, order[g] + 1, order[c], 1));
			cout << mx << '\n';

		}
	}
}