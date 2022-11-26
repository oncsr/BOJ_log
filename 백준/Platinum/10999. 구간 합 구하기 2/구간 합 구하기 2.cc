#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll segtree[2097152];
ll tree[1000001];
ll lazy[2097152];
int N, M, K;

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

void lazycheck(int start, int end, int node) {
	if (lazy[node] != 0) {
		segtree[node] += (ll)(end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

ll sum(int start, int end, int left, int right, int node) {
	lazycheck(start, end, node);
	if (left > end || right < start)	return 0;
	if (left <= start && end <= right) {
		return segtree[node];
	}
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void change(int start, int end, int left, int right, ll data, int node) {
	lazycheck(start, end, node);
	if (left > end || right < start)	return;
	if (left <= start && end <= right) {
		segtree[node] += (ll)(end - start + 1) * data;
		if (start == end)	return;
		else {
			lazy[node * 2] += data;
			lazy[node * 2 + 1] += data;
		}
		return;
	}
	int mid = (start + end) / 2;
	change(start, mid, left, right, data, node * 2);
	change(mid + 1, end, left, right, data, node * 2 + 1);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> tree[i];

	init(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			ll d;
			cin >> b >> c >> d;
			change(1, N, b, c, d, 1);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << sum(1, N, b, c, 1) << '\n';
		}
	}
}