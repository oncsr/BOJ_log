#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int, int>;

vector<vector<ii> > V(100001);
int par[100001]{}, sz[100001]{};
vector<vector<int> > C(100001);
int dep[100001]{}, cn[100001]{}, ci[100001]{}, order[100001]{};
int order2[100001]{};
int tree[100001]{}, cnt = 0;
ii seg[262145]{};

ii mrg(ii a, ii b) {
	return { min(a.first, b.first), max(a.second, b.second) };
}
void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = { tree[order[s]], tree[order[s]] };
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

void dfs(int n, int p) {
	par[n] = p;
	sz[n] = 1;
	for (ii i : V[n]) {
		if (i.first != p) {
			dfs(i.first, n);
			tree[i.first] = i.second;
			sz[n] += sz[i.first];
		}
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size();
	C[s].push_back(n);
	int h = -1;
	int w;
	order[++cnt] = n;
	order2[n] = cnt;
	for (ii i : V[n]) {
		if (i.first != p && (h == -1 || sz[i.first] > sz[h])) {
			h = i.first;
			w = i.second;
		}
	}
	if (h != -1) {
		hld(h, n, s, d);
	}
	for (ii i : V[n]) {
		if (i.first != p && i.first != h) {
			hld(i.first, n, i.first, d + 1);
		}
	}
}

int lca(int a, int b) {
	while (cn[a] != cn[b]) {
		if (dep[a] > dep[b])	a = par[cn[a]];
		else	b = par[cn[b]];
	}
	return ci[a] > ci[b] ? b : a;
}

ii find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { 1000001, 0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return mrg(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K, a, b, c;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		V[a].push_back({ b,c });
		V[b].push_back({ a,c });
	}
	dfs(1, 0); hld(1, 0, 1, 0);
	init(1, N, 1);

	for (cin >> K; K--;) {
		cin >> a >> b;
		int G = lca(a, b);
		int mx = 0, mn = 1000001;
		while (cn[G] != cn[a]) {
			ii t = find(1, N, order2[cn[a]], order2[a], 1);
			mn = min(mn, t.first);
			mx = max(mx, t.second);
			a = par[cn[a]];
		}
		ii t = find(1, N, order2[G] + 1, order2[a], 1);
		mn = min(mn, t.first);
		mx = max(mx, t.second);
		while (cn[G] != cn[b]) {
			t = find(1, N, order2[cn[b]], order2[b], 1);
			mn = min(mn, t.first);
			mx = max(mx, t.second);
			b = par[cn[b]];
		}
		t = find(1, N, order2[G] + 1, order2[b], 1);
		mn = min(mn, t.first);
		mx = max(mx, t.second);
		cout << mn << ' ' << mx << '\n';
	}
}