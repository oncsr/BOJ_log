#include <iostream>
using namespace std;
int segtree[262145] = { 0 };
int n, k, c = 0, temp;

void init(int start, int end, int node) {
	if (start == end) {
		segtree[node]++;
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

void update(int start, int end, int val, int node) {
	if (start == end)	return;
	int mid = (start + end) / 2;
	if(val <= mid)	update(start, mid, val, node * 2);
	else	update(mid + 1, end, val, node * 2 + 1);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int del(int start, int end, int val, int node) {
	if (start == end) {
		segtree[node]--;
		update(1, n, start, 1);
		return start;
	}
	int mid = (start + end) / 2;
	if (val <= segtree[node * 2])	return del(start, mid, val, node * 2);
	else	return del(mid + 1, end, val - segtree[node * 2], node * 2 + 1);
}

int main() {
	cin.sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> k;
	temp = n;
	cout << '<';
	init(1, n, 1);
	for (int i = 1; i <= n; i++) {
		c += k;
		if (c > temp)	c %= temp;
		if (c == 0)	c = temp;
		int t = del(1, n, c, 1);
		
		if (i == n)	cout << t << '>';
		else	cout << t << ", ";
		
		c--;
		temp--;
	}
}