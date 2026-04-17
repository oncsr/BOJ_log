#include <bits/stdc++.h>
using namespace std;

struct node {
	int left, right, cnt;
};

int arr[200001]{};
node seg[524289]{};

node mrg(node a, node b) {
	if (!a.left)	return b;
	if (!b.left)	return a;
	node c;
	c.left = a.left, c.right = b.right, c.cnt = a.cnt + b.cnt;
	if (a.right == b.left)	c.cnt--;
	return c;
}

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = { arr[s], arr[s], 1 };
		return;
	}
	int m = (s + e) >> 1;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

void upt(int s, int e, int i, int v, int n) {
	if (s == e) {
		seg[n] = { v,v,1 };
		return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, v, n * 2);
	else	upt(m + 1, e, i, v, n * 2 + 1);
	seg[n] = mrg(seg[n * 2], seg[n * 2 + 1]);
}

node find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return { 0,0,0 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return mrg(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)	cin >> arr[i];
	init(1, n, 1);
	for (; q--;) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)	upt(1, n, b, c, 1);
		else	cout << find(1, n, b, c, 1).cnt << '\n';
	}

}