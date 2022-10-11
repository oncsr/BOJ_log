#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int N, Q, a, b, c, cnt = 0;
vector<vector<int> > V(100001);
int order[100001]{};
vector<vector<int> > chain(100001);
int chain_num[100001]{};
int chain_index[100001]{};
int depth[100001]{};
int parent[100001]{};
int sz[100001]{};
ll seg[262145]{};
pair<ll, ll> lazy[262145]{};
pair<ll, ll> lazy2[262145]{};
int LENGTH = 0;

void dfs(int node, int par) {
	parent[node] = par;
	sz[node] = 1;
	for (int next : V[node]) {
		if (next != par) {
			dfs(next, node);
			sz[node] += sz[next];
		}
	}
}

void HLD(int node, int par, int start, int dep) {
	depth[node] = dep;
	chain_num[node] = start;
	chain_index[node] = chain[start].size();
	chain[start].push_back(node);

	order[node] = ++cnt;
	int heavy = -1;
	for (int next : V[node])
		if (next != par && (heavy == -1 || sz[next] > sz[heavy]))
			heavy = next;

	if (heavy != -1)
		HLD(heavy, node, start, dep);

	for (int next : V[node])
		if (next != par && next != heavy)
			HLD(next, node, next, dep + 1);
}

void prop(int s, int e, int n) {
	if (lazy[n].second) {
		ll val = lazy[n].first;
		ll d = lazy[n].second;
		ll len = (ll)e - s + 1;
		ll tempval = val - (len - 1) * d;
		seg[n] += (tempval * len + d * len * (len - 1) / 2);
		if (s != e) {
			int m = (s + e) / 2;
			lazy[n * 2].first += val;
			lazy[n * 2].second += lazy[n].second;
			lazy[n * 2 + 1].first += (val - ((ll)m + 1 - s) * lazy[n].second);
			lazy[n * 2 + 1].second += lazy[n].second;
		}
		lazy[n] = { 0,0 };
	}
	if (lazy2[n].second) {
		ll val = lazy2[n].first;
		ll d = lazy2[n].second;
		ll len = (ll)e - s + 1;
		seg[n] += (len * val + d * len * (len - 1) / 2);
		if (s != e) {
			int m = (s + e) / 2;
			lazy2[n * 2].first += val;
			lazy2[n * 2].second += lazy2[n].second;
			lazy2[n * 2 + 1].first += (val + ((ll)m + 1 - s)*lazy2[n].second);
			lazy2[n * 2 + 1].second += lazy2[n].second;
		}
		lazy2[n] = { 0,0 };
	}
}

// 아래로 갈 수록 감소
void upt(int s, int e, int l, int r, ll val, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		int m = (s + e) / 2;
		val = val - s + l;
		ll right = val * (val + 1) / 2;
		ll left = (val - e + s) * (val - e + s - 1) / 2;
		seg[n] += (right - left);
		if (s != e) {
			lazy[n * 2].first += val;
			lazy[n * 2].second++;
			lazy[n * 2 + 1].first += (val - m - 1 + s);
			lazy[n * 2 + 1].second++;
		}
		return;
	}
	int m = (s + e) / 2;
	upt(s, m, l, r, val, n * 2);
	upt(m + 1, e, l, r, val, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

// 아래로 갈 수록 증가
void upt2(int s, int e, int l, int r, ll val, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		int m = (s + e) / 2;
		val = val + s - l;
		ll right = (val + e - s) * (val + e - s + 1) / 2;
		ll left = (val - 1) * val / 2;
		seg[n] += (right - left);
		if (s != e) {
			lazy2[n * 2].first += val;
			lazy2[n * 2].second++;
			lazy2[n * 2 + 1].first += (val + m + 1 - s);
			lazy2[n * 2 + 1].second++;
		}
		return;
	}
	int m = (s + e) / 2;
	upt2(s, m, l, r, val, n * 2);
	upt2(m + 1, e, l, r, val, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int LCA(int a, int b) {
	LENGTH = 0;
	while (chain_num[a] != chain_num[b]) {
		if (depth[a] > depth[b]) {
			LENGTH += chain_index[a] + 1;
			a = parent[chain_num[a]];
		}
		else {
			LENGTH += chain_index[b] + 1;
			b = parent[chain_num[b]];
		}
	}
	LENGTH += abs(chain_index[a] - chain_index[b]);
	return chain_index[a] > chain_index[b] ? b : a;
}

ll find(int s, int e, int id, int n) {
	prop(s, e, n);
	if (s == e)	return seg[n];
	int m = (s + e) / 2;
	if (id <= m)	return find(s, m, id, n * 2);
	else	return find(m + 1, e, id, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(1, 0);	HLD(1, 0, 1, 0);
	for (cin >> Q; Q--;) {
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			int G = LCA(b, c);
			ll g = 0;
			while (chain_num[b] != chain_num[G]) {
				g += chain_index[b];
				upt(1, N, order[chain_num[b]], order[b], g, 1);
				b = parent[chain_num[b]];
				g++;
			}
			if (chain_index[b] > chain_index[G]) {
				int nx = chain[chain_num[G]][chain_index[G] + 1];
				g += ((ll)order[b] - order[nx]);
				upt(1, N, order[nx], order[b], g, 1);
				g++;
			}
			while (chain_num[c] != chain_num[G]) {
				upt2(1, N, order[chain_num[c]], order[c], LENGTH - chain_index[c], 1);
				LENGTH -= chain_index[c];
				c = parent[chain_num[c]];
				LENGTH--;
			}
			upt2(1, N, order[G], order[c], g, 1);
		}
		else {
			cout << find(1, N, order[b], 1) << '\n';
		}
	}
}