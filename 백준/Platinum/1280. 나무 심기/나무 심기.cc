#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
pll segtree[524289];	// {개수, 합}

inline pll pair_update(pll a, pll b) { return { a.first + b.first, a.second + b.second }; }

void init(int start, int end, int node) {
	if (start == end) {
		segtree[node] = { 0,0 };
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	segtree[node] = { 0,0 };
}

void add(int start, int end, int node, int val) {
	if (start == end) {
		segtree[node] = pair_update(segtree[node], { 1,val });
		return;
	}
	int mid = (start + end) / 2;
	if (val > mid)	add(mid + 1, end, node * 2 + 1, val);
	else	add(start, mid, node * 2, val);
	segtree[node] = pair_update(segtree[node * 2], segtree[node * 2 + 1]);
}

pll sum(int start, int end, int left, int right, int node) {
	if (left > end || right < start)	return { 0,0 };
	if (left <= start && end <= right)	return segtree[node];
	int mid = (start + end) / 2;
	return pair_update(sum(start, mid, left, right, node * 2), sum(mid + 1, end, left, right, node * 2 + 1));
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a;
	cin >> n;
	ll ans = 1;
	for (int i = 1; i <= n;i++) {
		cin >> a;
		pll f = sum(0, 200000, 0, a - 1, 1);
		pll g = sum(0, 200000, a + 1, 200000, 1);
		if (ans == 0)
			ans = (((ll)a * f.first - f.second) + (g.second - (ll)a * g.first)) % MOD;
		else
			if(i != 1)	ans = (ans % MOD * (((ll)a * f.first - f.second) % MOD + (g.second - (ll)a * g.first) % MOD) % MOD) % MOD;
		add(0, 200000, 1, a);
	}
	cout << ans << '\n';
}