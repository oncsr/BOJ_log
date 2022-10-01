#include <iostream>
using namespace std;

int tree[500001];
int segtree[1048577];
int lazy[1048577] = { 0 };

void init(int start, int end, int node) {
	if (start == end) {
		segtree[node] = tree[start];
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

void lazycheck(int start, int end, int node) {
	if (lazy[node] != 0) {
		if ((end - start) % 2 == 0)
			segtree[node] ^= lazy[node];
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void first_query(int start, int end, int left, int right, int k, int node) {
	lazycheck(start, end, node);
	if (left > end || right < start)	return;
	if (left <= start && end <= right) {
		if ((end - start) % 2 == 0)
			segtree[node] ^= k;
		if (start != end) {
			lazy[node * 2] ^= k;
			lazy[node * 2 + 1] ^= k;
		}
		return;
	}
	int mid = (start + end) / 2;
	first_query(start, mid, left, right, k, node * 2);
	first_query(mid + 1, end, left, right, k, node * 2 + 1);
	segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

int second_query(int start, int end, int left, int right, int node) {
	lazycheck(start, end, node);
	if (left > end || right < start)	return 0;
	if (left <= start && end <= right)	return segtree[node];
	int mid = (start + end) / 2;
	return second_query(start, mid, left, right, node * 2) ^ second_query(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> tree[i];
	init(1, N, 1);
	int M;
	cin >> M;
	while (M--) {
		int a, i, j;
		cin >> a >> i >> j;
		i++;
		j++;
		if (a == 1) {
			int k;
			cin >> k;
			first_query(1, N, i, j, k, 1);
		}
		else	cout << second_query(1, N, i, j, 1) << '\n';
	}
}