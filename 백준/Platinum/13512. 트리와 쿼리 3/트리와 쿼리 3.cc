#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(100001);
int par[100001]{}, sz[100001]{};
vector<vector<int> > C(100001);
int DP[100001]{}, CN[100001]{}, CX[100001]{};
int seg[262145]{}, order[100001]{}, pos[100001]{};

int N, Q, o, a, cnt = 0;

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

void upt(int s, int e, int i, int n) {
	if (s == e) {
		seg[n] ^= pos[s];
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	upt(s, m, i, n * 2);
	else	upt(m + 1, e, i, n * 2 + 1);
	if (seg[n * 2])	seg[n] = seg[n * 2];
	else	seg[n] = seg[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	int t1 = find(s, m, l, r, n * 2);
	int t2 = find(m + 1, e, l, r, n * 2 + 1);
	return t1 ? t1 : t2;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> o >> a;
		V[a].push_back(o);
		V[o].push_back(a);
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	for (cin >> Q; Q--;) {
		cin >> o >> a;
		if (o == 1)	upt(1, N, order[a], 1);
		else {
			int ans = -1;
			while (CN[a] != CN[1]) {
				int t = find(1, N, order[CN[a]], order[a], 1);
				if (t)	ans = t;
				a = par[CN[a]];
			}
			int t = find(1, N, order[1], order[a], 1);
			if (t)	ans = t;
			cout << ans << '\n';
		}
	}
}