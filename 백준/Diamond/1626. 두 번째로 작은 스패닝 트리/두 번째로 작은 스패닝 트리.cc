#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> seg[262145]{};
vector<vector<int>> C(50001);
vector<vector<pair<ll, int>>> V(50001);
int CN[50001]{}, CI[50001]{}, par[50001]{}, sz[50001]{}, dep[50001]{};
int ord[50001]{}, rev[50001]{}, num = 0;
ll arr[50001]{};

int root[50001]{};

int find(int x) {
	if (x == root[x])	return x;
	return root[x] = find(root[x]);
}

int N, M;

void dfs(int n, int p) {
	par[n] = p, sz[n] = 1;
	for (auto e : V[n]) {
		if (e.second == p)	continue;
		arr[e.second] = e.first;
		dfs(e.second, n);
		sz[n] += sz[e.second];
	}
}

void hld(int n, int p, int s, int d) {
	CN[n] = s, CI[n] = C[s].size(), dep[n] = d;
	C[s].push_back(n);
	ord[n] = ++num;
	rev[num] = n;
	int h = -1;
	for (auto e : V[n])
		if (e.second != p && (h == -1 || sz[e.second] > sz[h]))
			h = e.second;
	if (h != -1)	hld(h, n, s, d);
	for (auto e : V[n])
		if (e.second != p && e.second != h)
			hld(e.second, n, e.second, d + 1);
}

int lca(int a, int b) {
	while (CN[a] != CN[b]) {
		if (dep[a] > dep[b])	a = par[CN[a]];
		else	b = par[CN[b]];
	}
	return CI[a] > CI[b] ? b : a;
}

pair<ll, ll> mrg(pair<ll, ll> a, pair<ll, ll> b) {
	pair<ll, ll> res;
	ll temp[4] = { a.first, a.second, b.first, b.second };
	sort(temp, temp + 4, greater<>());
	res.first = temp[0];
	bool enter = 0;
	for (int i = 1; i < 4; i++) {
		if (temp[i] == temp[0])	continue;
		res.second = temp[i];
		enter = 1;
		break;
	}
	if (!enter)	res.second = -1;
	return res;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = { arr[rev[s]], -1 };
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

pair<ll, ll> query(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { -1,-1 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return mrg(query(s, m, l, r, n * 2), query(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)	root[i] = i;

	vector<pair<pair<ll, int>, pair<int, int>>> E;
	for (int i = 0; i < M; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		E.push_back({ {c,i},{a,b} });
	}
	ll mst = 0;
	int used[200001]{}, cnt = 0;
	sort(E.begin(), E.end());
	for (auto e : E) {
		int a = e.second.first, b = e.second.second;
		ll c = e.first.first;
		int x = find(a), y = find(b);
		if (x == y)	continue;
		root[x] = y;
		mst += e.first.first;
		used[e.first.second]++;
		cnt++;
		V[a].push_back({ c,b });
		V[b].push_back({ c,a });
	}

	if (cnt < N - 1) {
		cout << -1;
		return 0;
	}
	dfs(1, 0);	hld(1, 0, 1, 0);
	init(1, N, 1);
	bool poss = 0;
	ll mn = 1e18;
	for (auto e : E) {
		int edge = e.first.second;
		if (used[edge])	continue;
		int a = e.second.first, b = e.second.second;
		ll cost = e.first.first;
		int g = lca(a, b);
		pair<ll, ll> temp = { -1,-1 };
		while (CN[g] != CN[a]) {
			temp = mrg(temp, query(1, N, ord[CN[a]], ord[a], 1));
			a = par[CN[a]];
		}
		temp = mrg(temp, query(1, N, ord[g] + 1, ord[a], 1));
		while (CN[g] != CN[b]) {
			temp = mrg(temp, query(1, N, ord[CN[b]], ord[b], 1));
			b = par[CN[b]];
		}
		temp = mrg(temp, query(1, N, ord[g] + 1, ord[b], 1));
		if (temp.first == cost) {
			if (temp.second == -1)	continue;
			poss = 1;
			mn = min(mn, mst - temp.second + cost);
		}
		else {
			poss = 1;
			mn = min(mn, mst - temp.first + cost);
		}
	}
	if (!poss) {
		cout << -1;
		return 0;
	}
	cout << mn;

}