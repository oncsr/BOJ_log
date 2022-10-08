#include <iostream>
using namespace std;

int segtree[4194305] = { 0 };

void add(int start, int end, int val, int o, int node) {
	if (start == end) {
		segtree[node] += o;
		return;
	}
	int mid = (start + end) / 2;
	if (val > mid)	add(mid + 1, end, val, o, node * 2 + 1);
	else	add(start, mid, val, o, node * 2);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int find(int start, int end, int x, int node) {
	if (start == end)	return start;
	int mid = (start + end) / 2;
	if (x <= segtree[node * 2])	return find(start, mid, x, node * 2);
	else	return find(mid + 1, end, x - segtree[node * 2], node * 2 + 1);
}

int main() {
	cin.sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a == 1)	add(1, 2000000, b, 1, 1);
		else {
			int t = find(1, 2000000, b, 1);
			add(1, 2000000, t, -1, 1);
			cout << t << '\n';
		}
	}
}