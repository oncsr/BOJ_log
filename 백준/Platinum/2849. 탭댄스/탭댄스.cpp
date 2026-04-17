#include <bits/stdc++.h>
using namespace std;

struct node {
	int s, e, len, l, r, t;
};

node seg[524289]{};

node mrg(node a, node b) {
	node res;
	res.s = a.s, res.e = b.e;
	res.len = a.len + b.len;
	res.l = a.l;
	if (a.l == a.len && a.e != b.s)	res.l = a.len + b.l;
	res.r = b.r;
	if (b.r == b.len && a.e != b.s)	res.r = b.len + a.r;
	res.t = max(a.t, b.t);
	if (a.e != b.s)	res.t = max(res.t, a.r + b.l);
	return res;
}

node init(int s, int e, int n) {
	if (s == e)	return seg[n] = { 0,0,1,1,1,1 };
	int m = (s + e) >> 1;
	return seg[n] = mrg(init(s, m, n * 2), init(m + 1, e, n * 2 + 1));
}

void upt(int s, int e, int i, int n) {
	if (s == e) {
		seg[n] = { seg[n].s ^ 1,seg[n].s ^ 1,1,1,1,1 };
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, n * 2);
	else	upt(m + 1, e, i, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	init(1, N, 1);
	for (; Q--;) {
		int a;
		cin >> a;
		upt(1, N, a, 1);
		cout << seg[1].t << '\n';
	}

}