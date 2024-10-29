#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Line {
	ll a, b;
	ll get(ll x) { return a * x + b; }
};

struct Node {
	int l, r;
	ll s, e;
	Line line;
};

struct Li_Chao {
	vector<Node> tree;

	void init(ll s, ll e) {
		tree.push_back({ -1, -1, s, e, {0, LLONG_MAX} });
	}

	void upt(int node, Line v) {
		ll s = tree[node].s, e = tree[node].e, m = (s + e) >> 1;

		Line low = tree[node].line, high = v;
		if (low.get(s) > high.get(s))	swap(low, high);

		if (low.get(e) <= high.get(e)) { tree[node].line = low; return; }

		if (low.get(m) < high.get(m)) {
			tree[node].line = low;
			if (tree[node].r == -1) {
				tree[node].r = tree.size();
				tree.push_back({ -1, -1, m + 1, e, {0, LLONG_MAX} });
			}
			upt(tree[node].r, high);
		}
		else {
			tree[node].line = high;
			if (tree[node].l == -1) {
				tree[node].l = tree.size();
				tree.push_back({ -1, -1, s, m, {0, LLONG_MAX} });
			}
			upt(tree[node].l, low);
		}
	}

	ll query(int node, ll x) {
		if (node == -1)	return LLONG_MAX;
		ll s = tree[node].s, e = tree[node].e, m = (s + e) >> 1, v = tree[node].line.get(x);
		if (x <= m)	return min(v, query(tree[node].l, x));
		return min(v, query(tree[node].r, x));
	}
} seg;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll N, c = 0;
	cin >> N;
	seg.init(0, 1000010);
	
	vector<pair<ll, ll>> arr(N);
	for (auto& [a, b] : arr)	cin >> a, b = ++c;
	sort(arr.begin(), arr.end());
	ll idx = N + 1;
	ll ans = 1e18;
	for (auto& [a, b] : arr) {
		ll v = b < idx ? 0 : seg.query(0, b);
		ll val = v + (b - 1) * (b - 1);
		ans = min(ans, val + (N - b) * (N - b));
		seg.upt(0, { -2 * b,val + b * b + 2 * b });
		idx = min(idx, b);
	}
	cout << ans;

}