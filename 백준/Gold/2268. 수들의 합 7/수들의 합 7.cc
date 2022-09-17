#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll segtree[2097152] = { 0 };
ll tree[1000001] = { 0 };
int N, K;

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
	for (int i = 0; i < K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			change(1, N, b, c, 1);
			tree[b] = c;
		}
		else {
			if (b > c) {
				int tm = b;
				b = c;
				c = tm;
			}
			cout << sum(1, N, b, c, 1) << '\n';
		}
	}
}