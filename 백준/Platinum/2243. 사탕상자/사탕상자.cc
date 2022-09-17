#include <iostream>
using namespace std;
#define MAXSIZE 1000000
int n, a, b, c;
int segtree[2097153] = { 0 };

void add(int start, int end, int val, int cnt, int node) {
	if (start == end) {
		segtree[node] += cnt;
		return;
	}
	int mid = (start + end) / 2;
	if (val <= mid)	add(start, mid, val, cnt, node * 2);
	else	add(mid + 1, end, val, cnt, node * 2 + 1);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}
int find(int start, int end, int val, int node) {
	if (start == end)	return start;
	int mid = (start + end) / 2;
	if (val <= segtree[node * 2])	return find(start, mid, val, node * 2);
	else	return find(mid + 1, end, val - segtree[node * 2], node * 2 + 1);
}
int main() {
	cin.sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a == 1) {
			int t = find(1, MAXSIZE, b, 1);
			cout << t << '\n';
			add(1, MAXSIZE, t, -1, 1);
		}
		else {
			cin >> c;
			add(1, MAXSIZE, b, c, 1);
		}
	}
}