#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(100001);
int par[100001]{}, sz[100001]{};
vector<vector<int> > C(100001);
int DP[100001]{}, CN[100001]{}, CX[100001]{};
int seg[262145]{}, order[100001]{}, pos[100001]{};

int tree[100001]{};
int N, Q, o, a, b, cnt = 0;

void dfs(int n, int p) {
	par[n] = p, sz[n] = 1;
	for (int i : V[n])
		if (i != p) {
			dfs(i, n);
			sz[n] += sz[i];
		}
}

void hld(int n, int p, int s, int d) {
	DP[n] = d, CN[n] = s, CX[n] = C[s].size();
	C[s].push_back(n);
	order[n] = ++cnt;
	pos[cnt] = n;
	int h = -1;
	for (int i : V[n])
		if (i != p && (h == -1 || sz[i] > sz[h]))
			h = i;
	if (h != -1)	hld(h, n, s, d);
	for (int i : V[n])
		if (i != p && i != h)
			hld(i, n, i, d + 1);
}

int lca(int a, int b) {
	while (CN[a] != CN[b]) {
		if (DP[a] > DP[b])	a = par[CN[a]];
		else	b = par[CN[b]];
	}
	return CX[a] > CX[b] ? b : a;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = tree[pos[s]];
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] ^ seg[n * 2 + 1];
}

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] ^ seg[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) ^ find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)	cin >> tree[i];
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	init(1, N, 1);
	for (; Q--;) {
		cin >> o >> a >> b;
		if (o == 1)	upt(1, N, order[a], b, 1);
		else {
			int g = lca(a, b);
			int ans = 0;
			while (CN[a] != CN[g]) {
				ans ^= find(1, N, order[CN[a]], order[a], 1);
				a = par[CN[a]];
			}
			ans ^= find(1, N, order[g] + 1, order[a], 1);
			while (CN[b] != CN[g]) {
				ans ^= find(1, N, order[CN[b]], order[b], 1);
				b = par[CN[b]];
			}
			ans ^= find(1, N, order[g], order[b], 1);
			cout << ans << '\n';
		}
	}
}