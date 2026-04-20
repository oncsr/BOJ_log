#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define MAX 100002

int par[MAX]{}, sz[MAX]{}, dep[MAX]{}, ci[MAX]{}, cn[MAX]{};
int seg[4 * MAX]{}, ord[MAX]{}, cnt = 0;
vector<vector<int>> V(MAX), C(MAX);

void dfs(int n, int p) {
	par[n] = p, sz[n] = 1;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
		sz[n] += sz[i];
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size();
	C[s].push_back(n);
	ord[n] = ++cnt;
	int h = -1;
	for (int i : V[n])	if (i != p && (h == -1 || sz[i] > sz[h]))	h = i;
	if (h != -1)	hld(h, n, s, d);
	for (int i : V[n])	if (i != p && i != h)	hld(i, n, i, d + 1);
}

int lca(int a, int b) {
	while (cn[a] != cn[b]) {
		if (dep[a] > dep[b])	a = par[cn[a]];
		else	b = par[cn[b]];
	}
	return ci[a] < ci[b] ? a : b;
}

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	ii arr[MAX]{};
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		arr[i] = { a,i };
	}
	sort(arr + 1, arr + N + 1);
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);
	hld(1, 0, 1, 0);

	vector<tuple<int, int, int, int>> query;
	vector<int> ans(M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		query.push_back({ c,a,b,i });
	}
	int pos = 1;
	sort(query.begin(), query.end());
	for (auto [c, a, b, i] : query) {
		while (pos <= N && arr[pos].first <= c) {
			upt(1, N, ord[arr[pos].second], arr[pos].first, 1);
			pos++;
		}
		int g = lca(a, b), mx = 0;
		while (cn[g] != cn[a]) {
			mx = max(mx, find(1, N, ord[cn[a]], ord[a], 1));
			a = par[cn[a]];
		}
		mx = max(mx, find(1, N, ord[g], ord[a], 1));
		while (cn[g] != cn[b]) {
			mx = max(mx, find(1, N, ord[cn[b]], ord[b], 1));
			b = par[cn[b]];
		}
		mx = max(mx, find(1, N, ord[g], ord[b], 1));
		ans[i] = mx == c ? 1 : 0;
	}

	for (int i : ans)	cout << i;


}