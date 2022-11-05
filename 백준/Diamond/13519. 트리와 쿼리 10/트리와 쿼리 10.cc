#include <iostream>
#include <vector>
using namespace std;

struct node {
	int sum, left, right, total;
};

vector<vector<int> > V(100001);

int par[100001]{}, sz[100001]{}, tree[100001]{}, order[100001]{};
int dep[100001]{}, C_num[100001]{}, C_idx[100001]{};
vector<vector<int> > C(100001);
int N, M, cnt = 0, a, b, c, d;

node seg[262145]{};
int lazy[262145]{};

void dfs(int n, int p) {
	sz[n] = 1;
	par[n] = p;
	for (int i : V[n]) {
		if (i != p) {
			dfs(i, n);
			sz[n] += sz[i];
		}
	}
}

void HLD(int n, int p, int s, int d) {
	dep[n] = d;
	C_num[n] = s;
	C_idx[n] = C[s].size();
	C[s].push_back(n);

	order[n] = ++cnt;
	int h = -1;
	for (int i : V[n])
		if (i != p && (h == -1 || sz[i] > sz[h]))
			h = i;
	if (h != -1)	HLD(h, n, s, d);
	for (int i : V[n])
		if (i != p && i != h)
			HLD(i, n, i, d + 1);
}

node merge(node a, node b) {
	node c;
	c.sum = a.sum + b.sum;
	c.left = max(a.left, a.sum + b.left);
	c.right = max(b.right, b.sum + a.right);
	c.total = max(a.right + b.left, max(a.total, b.total));
	return c;
}

void init(int s, int e, int n) {
	if (s == e) {
		lazy[n] = 10001;
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
}

void prop(int s, int e, int n) {
	if (lazy[n] != 10001) {
		int t = lazy[n] * (e - s + 1);
		seg[n] = { t,max(0,t),max(0,t),max(0,t) };
		if (s != e)
			lazy[n * 2] = lazy[n * 2 + 1] = lazy[n];
		lazy[n] = 10001;
	}
}

int LCA(int a, int b) {
	while (C_num[a] != C_num[b]) {
		if (dep[a] > dep[b])	a = par[C_num[a]];
		else	b = par[C_num[b]];
	}
	return C_idx[a] > C_idx[b] ? b : a;
}

node find(int s, int e, int l, int r, int n) {
	if (l > r)	return { 0,0,0,0 };
	prop(s, e, n);
	if (l > e || r < s)	return { 0,0,0,0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return merge(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

node find2(int s, int e, int l, int r, int n) {
	if (l > r)	return { 0,0,0,0 };
	prop(s, e, n);
	if (l > e || r < s)	return { 0,0,0,0 };
	if (l <= s && e <= r) {
		return seg[n];
	}
	int m = (s + e) / 2;
	node t1 = find2(s, m, l, r, n * 2);
	node t2 = find2(m + 1, e, l, r, n * 2 + 1);
	return merge(t1, t2);
}

void query(int s, int e, int l, int r, int v, int n) {
	if (l > r)	return;
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		int t = v * (e - s + 1);
		seg[n] = { t,max(0,t),max(0,t),max(0,t) };
		if (s != e)
			lazy[n * 2] = lazy[n * 2 + 1] = v;
		return;
	}
	int m = (s + e) / 2;
	query(s, m, l, r, v, n * 2);	query(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> tree[i];
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);
	HLD(1, 0, 1, 0);
	for (int i = 1; i <= N; i++)
		query(1, N, order[i], order[i], tree[i], 1);
	init(1, N, 1);
	for (cin >> M; M--;) {
		cin >> a >> b >> c;
		int G = LCA(b, c);
		if (a == 1) {
			node T = { 0,0,0,0 };
			while (C_num[b] != C_num[G]) {
				node t2 = find2(1, N, order[C_num[b]], order[b], 1);
				swap(t2.left, t2.right);
				T = merge(T, t2);
				b = par[C_num[b]];
			}
			node t2 = find2(1, N, order[G] + 1, order[b], 1);
			swap(t2.left, t2.right);
			T = merge(T, t2);
			node temp = { 0,0,0,0 };
			int id = 0;
			while (C_num[c] != C_num[G]) {
				temp = merge(find(1, N, order[C_num[c]], order[c], 1), temp);
				c = par[C_num[c]];
			}
			temp = merge(find(1, N, order[G], order[c], 1), temp);
			T = merge(T, temp);
			cout << max(0, T.total) << '\n';
		}
		else {
			cin >> d;
			while (C_num[b] != C_num[G]) {
				query(1, N, order[C_num[b]], order[b], d, 1);
				b = par[C_num[b]];
			}
			query(1, N, order[G] + 1, order[b], d, 1);
			while (C_num[c] != C_num[G]) {
				query(1, N, order[C_num[c]], order[c], d, 1);
				c = par[C_num[c]];
			}
			query(1, N, order[G], order[c], d, 1);
		}
	}
}