#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int, int>;

vector<vector<int> > V(200001);
vector<vector<int> > C(200001);
bool seg[524289]{};
int par[200001]{}, sz[200001]{}, cnt = 0;
int N, Q, a, b, c;
int CN[200001]{}, CI[200001]{}, DEP[200001]{}, order[200001]{};

void D(int n, int p) {
	par[n] = p;
	sz[n] = 1;
	for (int i : V[n]) {
		if (i != p) {
			D(i, n);
			sz[n] += sz[i];
		}
	}
}

void H(int n, int p, int s, int d) {
	DEP[n] = d;
	CN[n] = s;
	CI[n] = C[s].size();
	C[s].push_back(n);

	order[n] = ++cnt;
	int h = -1;
	for (int i : V[n])
		if (i != p && (h == -1 || sz[i] > sz[h]))
			h = i;
	if (h != -1)	H(h, n, s, d);
	for (int i : V[n])
		if (i != p && i != h)
			H(i, n, i, d + 1);
}

void I(int s, int e, int n) {
	if (s == e) {
		seg[n] = 1;
		return;
	}
	int m = (s + e) / 2;
	I(s, m, n * 2);	I(m + 1, e, n * 2 + 1);
	seg[n] = seg[n * 2] && seg[n * 2 + 1];
}

void query(int s, int e, int i, int n) {
	if (s == e) {
		seg[n] = 0;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	query(s, m, i, n * 2);
	else	query(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] && seg[n * 2 + 1];
}

int LCA(int a, int b) {
	while (CN[a] != CN[b]) {
		if (DEP[a] > DEP[b])	a = par[CN[a]];
		else	b = par[CN[b]];
	}
	return CI[a] > CI[b] ? b : a;
}

bool find(int s, int e, int l, int r, int n) {
	if (l > e || r < s || l > r)	return 1;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) && find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) {
		cin >> a;
		V[a].push_back(i);
	}
	D(1, 0);
	H(1, 0, 1, 0);
	I(1, N, 1);
	for (; Q--;) {
		cin >> a >> b >> c;
		bool poss = 1;
		int G = LCA(a, b);
		int p = a, q = b;
		while (CN[G] != CN[a]) {
			poss = poss && find(1, N, order[CN[a]], order[a], 1);
			a = par[CN[a]];
		}
		poss = poss && find(1, N, order[G] + 1, order[a], 1);
		while (CN[G] != CN[b]) {
			poss = poss && find(1, N, order[CN[b]], order[b], 1);
			b = par[CN[b]];
		}
		poss = poss && find(1, N, order[G] + 1, order[b], 1);
		if (c == 1) {
			if (poss)	query(1, N, order[p], 1);
			else	query(1, N, order[q], 1);
		}
		cout << (poss ? "YES\n" : "NO\n");
	}
}