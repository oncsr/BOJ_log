#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int segtree[300000] = { 0 };
queue<int> Q;
void add(int start, int end, int val, int cnt, int node) {
	if (start == end) {
		segtree[node] += cnt;
		return;
	}
	int mid = (start + end) / 2;
	if (val <= mid)	add(start, mid, val, cnt, node * 2 + 1);
	else	add(mid + 1, end, val, cnt, node * 2 + 2);
	segtree[node] = segtree[node * 2 + 1] + segtree[node * 2 + 2];
}
int find(int start, int end, int val, int node) {
	if (start == end)	return start;
	int mid = (start + end) / 2;
	if (val <= segtree[node * 2 + 1])	return find(start, mid, val, node * 2 + 1);
	else	return find(mid + 1, end, val - segtree[node * 2 + 1], node * 2 + 2);
}
int main() {
	int n, k, x;
	ll ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		Q.push(x);
		add(0, 65536, x, 1, 0);
		if (i >= k) {
			ans += (ll)find(0, 65536, (k + 1) / 2, 0);
			add(0, 65536, Q.front(), -1, 0);
			Q.pop();
		}
	}
	cout << ans << '\n';
}