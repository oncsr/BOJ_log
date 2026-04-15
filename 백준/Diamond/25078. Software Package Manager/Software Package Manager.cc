#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int, int>;

vector<vector<int> > V(100001);
int parent[100001]{}, sz[100001]{};
vector<vector<int> > C(100001);
int depth[100001]{}, C_num[100001]{}, C_idx[100001]{};
int seg[262145]{}, lazy[262145]{};
ii order[100001]{};

int N, Q, a, cnt = 0, len = 0;
string op;

void lazy_init(int s, int e, int n) {
	lazy[n] = -1;
	if (s == e)	return;
	int m = (s + e) / 2;
	lazy_init(s, m, n * 2);	lazy_init(m + 1, e, n * 2 + 1);
}

void dfs(int node, int par) {
	parent[node] = par;
	sz[node] = 1;
	for (int i : V[node]) {
		if (i != par) {
			dfs(i, node);
			sz[node] += sz[i];
		}
	}
}

void hld(int node, int par, int st, int dep) {
	depth[node] = dep;
	C_num[node] = st;
	C_idx[node] = C[st].size();
	C[st].push_back(node);
	order[node].first = ++cnt;
	int heavy = -1;
	for (int i : V[node])
		if (i != par && (heavy == -1 || sz[i] > sz[heavy]))
			heavy = i;
	if (heavy != -1)	hld(heavy, node, st, dep);
	for (int i : V[node])
		if (i != par && i != heavy)
			hld(i, node, i, dep + 1);
	order[node].second = cnt;
}

void length(int a) {
	len = 0;
	while (C_num[a] != C_num[1]) {
		len += C_idx[a] + 1;
		a = parent[C_num[a]];
	}
	len += C_idx[a] + 1;
}

void prop(int s, int e, int n) {
	if (lazy[n] != -1) {
		seg[n] = lazy[n] * (e - s + 1);
		if (s != e)	lazy[n * 2] = lazy[n * 2 + 1] = lazy[n];
		lazy[n] = -1;
	}
}

int find(int s, int e, int l, int r, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

void upt(int s, int e, int l, int r, int val, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		if (val) {
			seg[n] = e - s + 1;
			if (s != e)	lazy[n * 2] = lazy[n * 2 + 1] = 1;
		}
		else {
			seg[n] = 0;
			if (s != e)	lazy[n * 2] = lazy[n * 2 + 1] = 0;
		}
		return;
	}
	int m = (s + e) / 2;
	upt(s, m, l, r, val, n * 2);	upt(m + 1, e, l, r, val, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> a;
		a++;
		V[i].push_back(a);
		V[a].push_back(i);
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	lazy_init(1, N, 1);
	for (cin >> Q; Q--;) {
		cin >> op >> a;
		a++;
		if (op == "install") {
			length(a);
			int temp = 0;
			while (C_num[a] != C_num[1]) {
				temp += find(1, N, order[C_num[a]].first, order[a].first, 1);
				upt(1, N, order[C_num[a]].first, order[a].first, 1, 1);
				a = parent[C_num[a]];
			}
			temp += find(1, N, order[1].first, order[a].first, 1);
			upt(1, N, order[1].first, order[a].first, 1, 1);
			cout << len - temp << '\n';
		}
		else {
			cout << find(1, N, order[a].first, order[a].second, 1) << '\n';
			upt(1, N, order[a].first, order[a].second, 0, 1);
		}
	}
}