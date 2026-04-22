#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

vector<vector<pair<ll, int>>> V(200001);
int root[200001]{}, N, M;

ll seg[524289]{}, arr[200001]{};

vector<vector<int>> C(200001);
int par[200001]{}, sz[200001]{};
int CN[200001]{}, CI[200001]{}, dep[200001]{};
int ord[200001]{}, rev[200001]{}, cnt = 0;

void dfs(int n, int p) {
	sz[n] = 1, par[n] = p;
	for (auto i : V[n]) {
		if (i.second == p)	continue;
		arr[i.second] = i.first;
		dfs(i.second, n);
		sz[n] += sz[i.second];
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, CN[n] = s, CI[n] = C[s].size();
	C[s].push_back(n);
	ord[n] = ++cnt;
	rev[cnt] = n;
	int h = -1;
	for (auto i : V[n]) {
		if (i.second != p && (h == -1 || sz[i.second] > sz[h])) {
			h = i.second;
		}
	}
	if (h != -1)	hld(h, n, s, d);
	for (auto i : V[n])
		if (i.second != h && i.second != p)
			hld(i.second, n, i.second, d + 1);
}

int lca(int a, int b) {
	while (CN[a] != CN[b]) {
		if (dep[a] > dep[b])	a = par[CN[a]];
		else	b = par[CN[b]];
	}
	return CI[a] > CI[b] ? b : a;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[rev[s]];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

ll find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return max(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

void print(int s, int e, int n) {
	if (s == e) {
		cout << seg[n] << ' ';
		return;
	}
	int m = (s + e) >> 1;
	print(s, m, n * 2);	print(m + 1, e, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	vector<pair<pair<ll, int>, ii>> E;
	for (int i = 1; i <= N; i++)	root[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		E.push_back({ {c, i}, {a,b} });
	}
	sort(E.begin(), E.end());
	ll sum = 0, ans[200001]{};
	int used[200001]{};
	for (auto e : E) {
		int a = e.second.first, b = e.second.second, edge = e.first.second;
		ll cost = e.first.first;
		int x = find(a), y = find(b);
		if (x == y)	continue;
		used[edge]++;
		root[x] = y;
		sum += cost;
		V[a].push_back({ cost, b });
		V[b].push_back({ cost, a });
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	init(1, N, 1);

	for (auto e : E) {
		int a = e.second.first, b = e.second.second, edge = e.first.second;
		ll cost = e.first.first;
		if (used[edge]) {
			ans[edge] = sum;
			continue;
		}
		
		int g = lca(a, b);
		ll mx = 0;
		while (CN[a] != CN[g]) {
			ll Q = find(1, N, ord[CN[a]], ord[a], 1);
			mx = max(mx, Q);
			a = par[CN[a]];
		}
		mx = max(mx, find(1, N, ord[g] + 1, ord[a], 1));
		while (CN[b] != CN[g]) {
			ll Q = find(1, N, ord[CN[b]], ord[b], 1);
			mx = max(mx, Q);
			b = par[CN[b]];
		}
		mx = max(mx, find(1, N, ord[g] + 1, ord[b], 1));
		ans[edge] = sum - mx + cost;
	}
	for (int i = 0; i < M; i++)	cout << ans[i] << '\n';
}