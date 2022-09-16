#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll segtree[262145];
ll tree[100001];
int N, K;

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
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> tree[i];

	init(1, N, 1);
	for (int i = 0; i < K; i++) {
		int a, b, c;
		ll d;
		cin >> a >> b >> c >> d;
		int e = min(a, b);
		int f = max(a, b);
		cout << sum(1, N, e, f, 1) << '\n';
		change(1, N, c, d, 1);
		tree[c] = d;
	}
}