#include <iostream>
using namespace std;

int tree[500001];
int segtree[1048577];
int n, m, o, i, a;

void init(int start, int end, int node) {
	if (start == end) {
		segtree[node] = tree[start];
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

void add(int start, int end, int wh, int cnt, int node) {
	if (start == end) {
		segtree[node] += cnt;
		return;
	}
	int mid = (start + end) / 2;
	if (wh <= mid)	add(start, mid, wh, cnt, node * 2);
	else	add(mid + 1, end, wh, cnt, node * 2 + 1);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int find(int start, int end, int num, int node) {
	if (start == end)	return start;
	int mid = (start + end) / 2;
	if (num <= segtree[node * 2])	return find(start, mid, num, node * 2);
	else	return find(mid + 1, end, num - segtree[node * 2], node * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> tree[i];
	init(1, n, 1);
	cin >> m;
	while (m--) {
		cin >> o >> i;
		if (o == 1) {
			cin >> a;
			add(1, n, i, a, 1);
		}
		else	cout << find(1, n, i, 1) << '\n';
	}
}