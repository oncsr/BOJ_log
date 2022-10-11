#include <iostream>
#include <vector>
using namespace std;
using INT = unsigned int;
using ii = pair<INT, INT>;

vector<vector<int> > V(500001);
INT parent[500001]{};
INT sz[500001]{};

vector<vector<int> > C(500001);
INT C_num[500001]{};
INT C_idx[500001]{};
INT depth[500001]{};

ii order[500001]{};
INT seg[1048577]{};
ii lazy[1048577]{};

INT N, Q, op, v, cnt = 0;
int x, y;

void DFS(int node, int par) {
	parent[node] = par;
	sz[node] = 1;
	for (int next : V[node]) {
		if (next != par) {
			DFS(next, node);
			sz[node] += sz[next];
		}
	}
}

void HLD(int node, int par, int start, int dep) {
	depth[node] = dep;
	C_num[node] = start;
	C_idx[node] = C[start].size();
	C[start].push_back(node);

	order[node].first = ++cnt;
	int heavy = -1;
	for (int next : V[node])
		if (next != par && (heavy == -1 || sz[next] > sz[heavy]))
			heavy = next;
	if (heavy != -1)	HLD(heavy, node, start, dep);
	for (int next : V[node])
		if (next != par && next != heavy)
			HLD(next, node, next, dep + 1);
	order[node].second = cnt;
}

int LCA(int a, int b) {
	while (C_num[a] != C_num[b]) {
		if (depth[a] > depth[b])	a = parent[C_num[a]];
		else	b = parent[C_num[b]];
	}
	return C_idx[a] > C_idx[b] ? b : a;
}

void lazy_init(int s, int e, int n) {
	lazy[n].first = 1;
	if (s == e)	return;
	int m = (s + e) / 2;
	lazy_init(s, m, n * 2);	lazy_init(m + 1, e, n * 2 + 1);
}

void prop(int s, int e, int n) {
	if (lazy[n].first != 1 || lazy[n].second) {
		INT val1 = lazy[n].first;
		INT val2 = lazy[n].second;
		seg[n] *= val1;
		seg[n] += val2 * (e - s + 1);
		if (s != e) {
			lazy[n * 2].first *= val1;
			lazy[n * 2].second *= val1;
			lazy[n * 2].second += val2;
			lazy[n * 2 + 1].first *= val1;
			lazy[n * 2 + 1].second *= val1;
			lazy[n * 2 + 1].second += val2;
		}
		lazy[n] = { 1,0 };
	}
}

void upt(int s, int e, int l, int r, int op, INT val, int n) {
	if (l > r)	return;
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		if (op == 1) {
			seg[n] += (e - s + 1) * val;
			if (s != e) {
				lazy[n * 2].second += val;
				lazy[n * 2 + 1].second += val;
			}
		}
		else {
			seg[n] *= val;
			if (s != e) {
				lazy[n * 2].first *= val;
				lazy[n * 2].second *= val;
				lazy[n * 2 + 1].first *= val;
				lazy[n * 2 + 1].second *= val;
			}
		}
		return;
	}
	int m = (s + e) / 2;
	upt(s, m, l, r, op, val, n * 2);	upt(m + 1, e, l, r, op, val, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

INT find(int s, int e, int l, int r, int n) {
	if (l > r)	return 0;
	prop(s, e, n);
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	DFS(1, 0);
	HLD(1, 0, 1, 0);
	lazy_init(1, N, 1);
	for (; Q--;) {
		cin >> op >> x;
		if (op == 5)	cout << find(1, N, order[x].first, order[x].second, 1) << '\n';
		else {
			cin >> y;
			if (op == 1)	upt(1, N, order[x].first, order[x].second, 1, y, 1);
			else if (op == 3)	upt(1, N, order[x].first, order[x].second, 2, y, 1);
			else if (op == 6) {
				INT G = LCA(x, y);
				INT temp = 0;
				while (C_num[x] != C_num[G]) {
					temp += find(1, N, order[C_num[x]].first, order[x].first, 1);
					x = parent[C_num[x]];
				}
				temp += find(1, N, order[G].first + 1, order[x].first, 1);
				while (C_num[y] != C_num[G]) {
					temp += find(1, N, order[C_num[y]].first, order[y].first, 1);
					y = parent[C_num[y]];
				}
				temp += find(1, N, order[G].first, order[y].first, 1);
				cout << temp << '\n';
			}
			else {
				cin >> v;
				op /= 2;
				INT G = LCA(x, y);
				while (C_num[x] != C_num[G]) {
					upt(1, N, order[C_num[x]].first, order[x].first, op, v, 1);
					x = parent[C_num[x]];
				}
				upt(1, N, order[G].first + 1, order[x].first, op, v, 1);
				while (C_num[y] != C_num[G]) {
					upt(1, N, order[C_num[y]].first, order[y].first, op, v, 1);
					y = parent[C_num[y]];
				}
				upt(1, N, order[G].first, order[y].first, op, v, 1);
			}
		}
	}
}