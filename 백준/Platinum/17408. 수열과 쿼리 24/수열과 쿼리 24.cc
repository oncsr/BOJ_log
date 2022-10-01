#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int tree[100001];
pii segtree[262145];

int summ(pii a) { return a.first + a.second; }

pii mxpair(pii a, pii b) {
	int arr[4] = { a.first, a.second, b.first, b.second };
	sort(arr, arr + 4);
	return { arr[3],arr[2] };
}

void init(int start, int end, int node) {
	if (start == end) {
		segtree[node] = { tree[start],0 };
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	segtree[node] = mxpair(segtree[node * 2], segtree[node * 2 + 1]);
}

void change(int start, int end, int i, int v, int node) {
	if (start == end) {
		segtree[node] = { v,0 };
		return;
	}
	if (i < start || end < i)	return;
	int mid = (start + end) / 2;
	if (i > mid)
		change(mid + 1, end, i, v, node * 2 + 1);
	else
		change(start, mid, i, v, node * 2);
	segtree[node] = mxpair(segtree[node * 2], segtree[node * 2 + 1]);
}

pii mxreturn(int start, int end, int left, int right, int node) {
	if (end < left || right < start)	return { 0,0 };
	if (left <= start && end <= right)	return segtree[node];
	int mid = (start + end) / 2;
	pii p1 = mxreturn(start, mid, left, right, node * 2);
	pii p2 = mxreturn(mid + 1, end, left, right, node * 2 + 1);
	return mxpair(p1, p2);
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
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			change(1, N, b, c, 1);
		else {
			pii ans = mxreturn(1, N, b, c, 1);
			cout << ans.first + ans.second << '\n';
		}
	}
}