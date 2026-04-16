#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct node {
	ll mx, idx, sum, lsum, rsum, tsum;
};
 
ll arr[200001]{};
node seg[524289]{};
 
node mrg(node a, node b) {
	node c;
	if (b.mx > a.mx)	c.mx = b.mx, c.idx = b.idx;
	else	c.mx = a.mx, c.idx = a.idx;
	c.sum = a.sum + b.sum;
 
	if (a.lsum == 0)	c.lsum = 0;
	else if (a.lsum == a.sum && a.sum == a.rsum)	c.lsum = a.sum + b.lsum;
	else	c.lsum = a.lsum;
 
	if (b.rsum == 0)	c.rsum = 0;
	else if (b.lsum == b.sum && b.sum == b.rsum)	c.rsum = b.sum + a.rsum;
	else	c.rsum = b.rsum;
 
	c.tsum = max({ a.tsum, b.tsum, a.rsum + b.lsum });
	return c;
}
 
void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = { arr[s],s,arr[s],arr[s],arr[s],arr[s] };
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}
 
void upt(int s, int e, int i, ll v, int n) {
	if (s == e) {
		arr[s] += v;
		seg[n] = { arr[s],s,arr[s],arr[s],arr[s],arr[s] };
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}
 
pair<ll, int> find_max(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { -1,0 };
	if (l <= s && e <= r)	return { seg[n].mx, seg[n].idx };
	int m = (s + e) >> 1;
	auto L = find_max(s, m, l, r, n * 2);
	auto R = find_max(m + 1, e, l, r, n * 2 + 1);
	if (R.first > L.first)	return R;
	return L;
}
 
node find_len(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { -1,0,0,0,0,0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return mrg(find_len(s, m, l, r, n * 2), find_len(m + 1, e, l, r, n * 2 + 1));
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	init(1, N, 1);
 
	for (; Q--;) {
		ll o, a, b;
		cin >> o >> a >> b;
		if (o == 1) {
			while (b) {
				ll v = min(b, arr[a]);
				upt(1, N, a, -v, 1);
				b -= v;
				auto info = find_max(1, N, a + 1, N, 1);
				if (info.first <= 0)	break;
				a = info.second;
			}
		}
		else if (o == 2)	upt(1, N, a, b, 1);
		else	cout << find_len(1, N, a, b, 1).tsum << '\n';
	}
 
}
