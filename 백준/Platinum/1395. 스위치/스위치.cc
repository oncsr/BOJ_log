#include <iostream>
using namespace std;
int segtree[262145] = { 0 };
int lazy[262145] = { 0 };

void lazycheck(int start, int end, int node) {
	if (lazy[node] % 2 != 0) {
		segtree[node] = (end - start + 1) - segtree[node];
		if (start != end) {
			lazy[node * 2]++;
			lazy[node * 2 + 1]++;
		}
		lazy[node] = 0;
	}
}

void add(int start, int end, int left, int right, int node) {
	lazycheck(start, end, node);
	if (left > end || right < start)	return;
	if (left <= start && end <= right) {
		segtree[node] = (end - start + 1) - segtree[node];
		if (start != end) {
			lazy[node * 2]++;
			lazy[node * 2 + 1]++;
		}
		return;
	}
	int mid = (start + end) / 2;
	add(start, mid, left, right, node * 2);
	add(mid + 1, end, left, right, node * 2 + 1);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int sum(int start, int end, int left, int right, int node) {
	lazycheck(start, end, node);
	if (left > end || right < start)	return 0;
	if (left <= start && end <= right) {
		return segtree[node];
	}
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int O, S, T;
		cin >> O >> S >> T;
		if (O)
			cout << sum(1, N, S, T, 1) << '\n';
		else
			add(1, N, S, T, 1);
	}
}