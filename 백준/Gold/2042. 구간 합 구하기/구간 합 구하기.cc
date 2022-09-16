#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll segtree[2097152];
ll tree[1000001];
int N, M, K;

ll init(int start, int end, int node) {
	if (start == end)
		return segtree[node] = tree[start];
	int mid = (start + end) / 2;
	return segtree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int left, int right, int node) {
	if (left > end || right < start)	return 0;
	if (left <= start && end <= right)	return segtree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void change(int start, int end, int i, ll data, int node) {
	if (start <= i && i <= end) {
		segtree[node] += (data - tree[i]);
		if (start == end)	return;
		int mid = (start + end) / 2;
		change(start, mid, i, data, node * 2);
		change(mid + 1, end, i, data, node * 2 + 1);
	}
	else	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> tree[i];

	init(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			change(1, N, b, c, 1);
			tree[b] = c;
		}
		else	cout << sum(1, N, b, c, 1) << '\n';
	}
}