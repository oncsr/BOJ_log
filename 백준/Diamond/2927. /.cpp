#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> root(30001);
int arr[30001]{};
int seg[65537]{};
int par[30001]{};
int CN[30001]{}, CI[30001]{}, sz[30001]{}, dep[30001]{};
int ord[30001]{}, rev[30001]{}, cnt = 0;
vector<int> vis(30001);
vector<vector<int>> C(30001);
vector<vector<int>> V(30001);
vector<pair<string, pair<int, int>>> query;

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[rev[s]];
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void dfs(int n, int p) {
	sz[n] = 1, par[n] = p, vis[n]++;
	for (int i : V[n]) {
		if (i != p) {
			dfs(i, n);
			sz[n] += sz[i];
		}
	}
}

void hld(int n, int p, int s, int d) {
	CN[n] = s;
	CI[n] = C[s].size();
	dep[n] = d;
	C[s].push_back(n);
	vis[n]++;
	ord[n] = ++cnt;
	rev[cnt] = n;
	int h = -1;
	for (int i : V[n])
		if (i != p && (h == -1 || sz[i] > sz[h]))
			h = i;
	if (h != -1)	hld(h, n, s, d);
	for (int i : V[n])
		if (i != p && i != h)
			hld(i, n, i, d + 1);
}

void change(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	change(s, m, i, v, n * 2);
	else	change(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int lca(int a, int b) {
	while (CN[a] != CN[b]) {
		if (dep[a] > dep[b])	a = par[CN[a]];
		else	b = par[CN[b]];
	}
	return CI[a] > CI[b] ? b : a;
}

int cal(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return cal(s, m, l, r, n * 2) + cal(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i], root[i] = i;
	for (cin >> Q; Q--;) {
		string a;
		int b, c;
		cin >> a >> b >> c;
		query.push_back({ a,{b,c} });
		if (a == "bridge") {
			int x = find(b), y = find(c);
			if (x == y)	continue;
			root[x] = y;
			V[b].push_back(c);
			V[c].push_back(b);
		}
	}
	for (int i = 1; i <= N; i++)	root[i] = i;
	for (int i = 1; i <= N; i++) {
		if (!vis[i])	dfs(i, 0);
	}
	vis = vector<int>(30001, 0);
	for (int i = 1; i <= N; i++) {
		if (!vis[i])	hld(i, 0, i, 0);
	}
	init(1, N, 1);
	for (pair<string, pair<int, int>> i : query) {
		string op = i.first;
		int a = i.second.first, b = i.second.second;
		if (op == "excursion") {
			int x = find(a), y = find(b);
			if (x != y) {
				cout << "impossible\n";
				continue;
			}
			// 경로 쿼리
			int G = lca(a, b);
			int s = 0;
			while (CN[G] != CN[a]) {
				s += cal(1, N, ord[CN[a]], ord[a], 1);
				a = par[CN[a]];
			}
			while (CN[G] != CN[b]) {
				s += cal(1, N, ord[CN[b]], ord[b], 1);
				b = par[CN[b]];
			}
			if (CI[a] > CI[b])	swap(a, b);
			s += cal(1, N, ord[a], ord[b], 1);
			cout << s << '\n';
		}
		else if (op == "bridge") {
			int x = find(a), y = find(b);
			if (x != y) {
				root[x] = y;
				cout << "yes\n";
			}
			else	cout << "no\n";
		}
		else	change(1, N, ord[a], b, 1);
	}
}