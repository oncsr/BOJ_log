#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > V(250001);
vector<vector<int> > C(250001);
int dep[250001]{}, cn[250001]{}, ci[250001]{};
int par[250001]{}, sz[250001]{}, order[250001]{};
int seg[524289]{};
int n, cnt = 0, a, b, m;
char o;

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = 1;
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

void dfs(int n, int p) {
	par[n] = p;
	sz[n] = 1;
	for (int i : V[n]) {
		if (i != p) {
			dfs(i, n);
			sz[n] += sz[i];
		}
	}
}

void hld(int n, int p, int s, int d) {
	dep[n] = d, cn[n] = s, ci[n] = C[s].size(), order[n] = ++cnt;
	C[s].push_back(n);
	int h = -1;
	for (int i : V[n])
		if (i != p && (h == -1 || sz[i] > sz[h]))
			h = i;
	if (h != -1)	hld(h, n, s, d);
	for (int i : V[n])
		if (i != p && i != h)
			hld(i, n, i, d + 1);
}

void query(int s, int e, int i, int n) {
	if (s == e) {
		seg[n] = 0;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, n * 2);
	else	query(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	init(1, n, 1);
	cin >> m;
	for (m += n - 1; m--;) {
		cin >> o >> a;
		if (o == 'W') {
			int t = 0;
			while (cn[1] != cn[a]) {
				t += find(1, n, order[cn[a]], order[a], 1);
				a = par[cn[a]];
			}
			t += find(1, n, 2, order[a], 1);
			cout << t << '\n';
		}
		else {
			cin >> b;
			if (par[a] == b)	query(1, n, order[a], 1);
			else	query(1, n, order[b], 1);
		}
	}
}