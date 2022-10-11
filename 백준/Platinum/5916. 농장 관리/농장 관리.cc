#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int> > V(100001);
int parent[100001]{};
int sz[100001]{};

vector<vector<int> > C(100001);
int depth[100001]{};
int C_idx[100001]{};
int C_num[100001]{};

ll seg[262145]{};
ll lazy[262145]{};
int order[100001]{};

int N, M, a, b, cnt = 0;
char op;

void dfs(int node, int par) {
	parent[node] = par;
	sz[node] = 1;
	for (int next : V[node]) {
		if (next != par) {
			dfs(next, node);
			sz[node] += sz[next];
		}
	}
}

void HLD(int node, int par, int start, int dep) {
	depth[node] = dep;
	C_num[node] = start;
	C_idx[node] = C[start].size();
	C[start].push_back(node);

	order[node] = ++cnt;
	int heavy = -1;
	for (int next : V[node])
		if (next != par && (heavy == -1 || sz[next] > sz[heavy]))
			heavy = next;
	if (heavy != -1)
		HLD(heavy, node, start, dep);
	for (int next : V[node])
		if (next != par && next != heavy)
			HLD(next, node, next, dep + 1);
}

int LCA(int a, int b) {
	while (C_num[a] != C_num[b]) {
		if (depth[a] > depth[b])	a = parent[C_num[a]];
		else	b = parent[C_num[b]];
	}
	return C_idx[a] > C_idx[b] ? b : a;
}

void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n] += lazy[n] * ((ll)e - s + 1);
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void upt(int s, int e, int l, int r, int n) {
	if (l > r)	return;
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] += ((ll)e - s + 1);
		if (s != e) {
			lazy[n * 2]++;
			lazy[n * 2 + 1]++;
		}
		return;
	}
	int m = (s + e) / 2;
	upt(s, m, l, r, n * 2);
	upt(m + 1, e, l, r, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

ll find(int s, int e, int l, int r, int n) {
	if (l > r)	return 0;
	prop(s, e, n);
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);	HLD(1, 0, 1, 0);
	for (; M--;) {
		cin >> op >> a >> b;
		int G = LCA(a, b);
		if (op == 'P') {
			while (C_num[a] != C_num[G]) {
				upt(1, N, order[C_num[a]], order[a], 1);
				a = parent[C_num[a]];
			}
			upt(1, N, order[G] + 1, order[a], 1);
			while (C_num[b] != C_num[G]) {
				upt(1, N, order[C_num[b]], order[b], 1);
				b = parent[C_num[b]];
			}
			upt(1, N, order[G] + 1, order[b], 1);
		}
		else {
			int G = LCA(a, b);
			ll ans = 0;
			while (C_num[a] != C_num[G]) {
				ans += find(1, N, order[C_num[a]], order[a], 1);
				a = parent[C_num[a]];
			}
			ans += find(1, N, order[G] + 1, order[a], 1);
			while (C_num[b] != C_num[G]) {
				ans += find(1, N, order[C_num[b]], order[b], 1);
				b = parent[C_num[b]];
			}
			ans += find(1, N, order[G] + 1, order[b], 1);
			cout << ans << '\n';
		}
	}
}