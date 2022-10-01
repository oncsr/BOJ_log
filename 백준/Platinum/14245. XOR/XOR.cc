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

int find(int start, int end, int x, int node) {
	lazycheck(start, end, node);
	if (start == end)	return segtree[node];
	int mid = (start + end) / 2;
	if (x > mid)
		return find(mid + 1, end, x, node * 2 + 1);
	else
		return find(start, mid, x, node * 2);
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
		int a, i;
		cin >> a >> i;
		i++;
		if (a == 1) {
			int j, k;
			cin >> j >> k;
			j++;
			first_query(1, N, i, j, k, 1);
		}
		else	cout << find(1,N,i,1) << '\n';
	}
}