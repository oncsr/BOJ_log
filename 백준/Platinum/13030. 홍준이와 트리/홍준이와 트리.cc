#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

const ll mod = 1000000007;
int N, Q, a, b, cnt = 0;
ll c, d;
ii order[300001]{};
ll tree[300001]{};
pll lazy[1048577]{};
int dep[300001]{};
int idx[300001]{};
vector<vector<int> > V(300001);

void dfs(int n, int dp) {
	dep[n] = dp;
	order[n].first = ++cnt;
	idx[cnt] = n;
	for (int i : V[n])	dfs(i, dp + 1);
	order[n].second = cnt;
}

void prop(int s, int e, int n) {
	if (lazy[n].first || lazy[n].second) {
		if (s == e) {
			tree[idx[s]] += lazy[n].first - dep[idx[s]] * lazy[n].second;
			tree[idx[s]] %= mod;
		}
		else {
			lazy[n * 2].first += lazy[n].first;
			lazy[n * 2].second += lazy[n].second;
			lazy[n * 2 + 1].first += lazy[n].first;
			lazy[n * 2 + 1].second += lazy[n].second;
		}
		lazy[n] = { 0,0 };
	}
}

void query(int s, int e, int l, int r, ll x, ll k, int n) {
	if (l > r)	return;
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		if (s == e) {
			tree[idx[s]] += x - dep[idx[s]] * k;
			tree[idx[s]] %= mod;
		}
		else {
			lazy[n * 2].first += x;
			lazy[n * 2].second += k;
			lazy[n * 2 + 1].first += x;
			lazy[n * 2 + 1].second += k;
		}
		return;
	}
	int m = (s + e) / 2;
	query(s, m, l, r, x, k, n * 2);	query(m + 1, e, l, r, x, k, n * 2 + 1);
}

ll find(int s, int e, int v, int n) {
	prop(s, e, n);
	if (s == e)	return tree[idx[s]];
	int m = (s + e) / 2;
	if (v <= m)	return find(s, m, v, n * 2);
	return find(m + 1, e, v, n * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) {
		cin >> a;
		V[a].push_back(i);
	}
	dfs(1, 0);
	for (; Q--;) {
		cin >> a >> b;
		if (a == 1) {
			cin >> c >> d;
			tree[b] += c;
			c += dep[b] * d;
			query(1, N, order[b].first + 1, order[b].second, c, d, 1);
		}
		else {
			ll sum = find(1, N, order[b].first, 1);
			sum %= mod;
			if (sum < 0)	sum += mod;
			cout << sum << '\n';
		}
	}
}