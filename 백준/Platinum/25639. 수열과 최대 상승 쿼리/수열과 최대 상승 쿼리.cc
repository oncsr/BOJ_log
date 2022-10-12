#include <iostream>
using namespace std;

struct node {
	int mn, mx, res;
};

int tree[100001]{};
node seg[262145]{};
int N, M, o, a, b;

node merge_node(node a, node b) {
	node c;
	c.res = max(b.mx - a.mn, max(a.res, b.res));
	c.mx = max(a.mx, b.mx);
	c.mn = min(a.mn, b.mn);
	return c;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n].mn = seg[n].mx = tree[s];
		seg[n].res = 0;
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = merge_node(seg[n * 2], seg[n * 2 + 1]);
}

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n].mn = v;
		seg[n].mx = v;
		seg[n].res = 0;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = merge_node(seg[n * 2], seg[n * 2 + 1]);
}

node find(int s, int e, int l, int r, int n) {
	if (l > e || r < s) {
		node c;
		c.mx = -1000000000;
		c.mn = 1000000000;
		c.res = -1;
		return c;
	}
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return merge_node(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> tree[i];
	init(1, N, 1);
	for (cin >> M; M--;) {
		cin >> o >> a >> b;
		if (o == 1)	upt(1, N, a, b, 1);
		else {
			node ans = find(1, N, a, b, 1);
			cout << ans.res << '\n';
		}
	}
}