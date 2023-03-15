#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

struct node {
	ll left, right, total, sum;
};

node seg[262145]{};
ll arr[100001]{}, num;
int N, M, x, y, xx, yy;

node mrg(node a, node b) {
	node c;
	c.sum = a.sum + b.sum;
	c.left = max(a.left, a.sum + b.left);
	c.right = max(b.right, a.right + b.sum);
	c.total = max({ a.total, b.total, a.right + b.left });
	return c;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = { arr[s], arr[s], arr[s], arr[s] };
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

node find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { -10000000001,-10000000001 ,-10000000001 ,0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return mrg(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	init(1, N, 1);
	for (cin >> M; M--;) {
		cin >> x >> y >> xx >> yy;
		ll lf, md, rt;
		if (xx > y) {
			if (x == y)	lf = 0;
			else	lf = max(find(1, N, x, y - 1, 1).right, 0LL);
			md = find(1, N, y, xx, 1).sum;
			if (xx == yy)	rt = 0;
			else	rt = max(find(1, N, xx + 1, yy, 1).left, 0LL);
			cout << lf + md + rt << '\n';
		}
		else {
			if (x == xx)	lf = 0;
			else	lf = max(find(1, N, x, xx - 1, 1).right, 0LL);
			node MD = find(1, N, xx, y, 1);
			if (y == yy)	rt = 0;
			else	rt = max(find(1, N, y + 1, yy, 1).left, 0LL);
			ll mx = max({ MD.total, MD.right + rt, MD.left + lf, lf + MD.sum + rt });
			cout << mx << '\n';
		}
	}
}