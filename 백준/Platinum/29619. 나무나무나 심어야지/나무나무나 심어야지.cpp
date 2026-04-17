#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int N, M, L, cnt = 0;
int seg[524289]{};
int arr[200001]{}, rev[200001]{};
ii ord[200001]{};
vector<vector<int>> V(200001);
vector<tuple<int, int, int, int>> Q;

void dfs(int n, int p) {
	ord[n].first = ++cnt;
	rev[cnt] = n;
	for (int i : V[n]) {
		if (i == p)	continue;
		dfs(i, n);
	}
	ord[n].second = cnt;
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

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = v;
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

int main() {
	cin >> N >> M;
	L = N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (i == 1)	continue;
		V[a].push_back(i);
	}
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (; M--;) {
		int o, a, b = 0, c = 0;
		cin >> o >> a;
		if (o == 1) {
			cin >> b >> c;
			V[a].push_back(b);
			V[b].push_back(a);
			L++;
		}
		Q.emplace_back(o, a, b, c);
	}
	dfs(1, 0);
	init(1, L, 1);

	for (auto [o, a, b, c] : Q) {
		if (o == 1)	upt(1, L, ord[b].first, c, 1);
		else {
			int res = find(1, L, ord[a].first, ord[a].second, 1);
			cout << (res ? res : -1) << '\n';
		}
	}

}