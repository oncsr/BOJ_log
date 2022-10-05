#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int sum, left, right, total;
};
/*
bool operator==(node a, node b) {
	return a.sum == b.sum && a.left == b.left && a.right == b.right && a.total == b.total;
}
*/

int tree[100001]{}, N, M, a, b;
node seg[262145]{};
node none = { 0,0,0,0 };

node solve(node L, node R) {
	node t;
	/*
	if (L == none)	return R;
	if (R == none)	return L;
	*/
	t.sum = L.sum + R.sum;
	t.left = max(L.left, L.sum + R.left);
	t.right = max(R.right, R.sum + L.right);
	t.total = max({ L.total, R.total, L.right + R.left });
	return t;
}

void init(int s, int e, int n) {
	if (s == e) {
		int r = tree[s];
		seg[n] = { r,r,r,r };
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	node L = seg[n * 2], R = seg[n * 2 + 1];
	seg[n] = solve(seg[n * 2], seg[n * 2 + 1]);
}

node find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return { 0,-1000000001,-1000000001,-1000000001 };
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return solve(find(s, m, l, r, n * 2), find(m + 1, e, l, r, n * 2 + 1));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> tree[i];
	init(1, N, 1);
	for (cin >> M; M--;) {
		cin >> a >> b;
		cout << find(1, N, a, b, 1).total << '\n';
	}
}