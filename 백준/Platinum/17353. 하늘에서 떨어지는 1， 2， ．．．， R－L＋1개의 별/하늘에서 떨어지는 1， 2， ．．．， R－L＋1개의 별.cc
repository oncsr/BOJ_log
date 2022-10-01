#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, ll> iii;

ll tree[100001];
ll segtree[262145]{};
iii lazy[262145]{};
int N, Q, o;
ll a, b;

iii addpair(iii a, iii b) {
	return { {a.first.first + b.first.first,a.first.second + b.first.second},a.second + b.second };
}

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

void update(int start, int end, int node) {
	if (lazy[node].second != 0) {
		if (start == end) {
			segtree[node] += lazy[node].first.first;
		}
		else {
			ll mid = ((ll)end - start) / 2 + 1;
			lazy[node * 2] = addpair(lazy[node * 2], { {lazy[node].first.first,lazy[node].first.first + lazy[node].second * (mid - 1)},lazy[node].second });
			lazy[node * 2 + 1] = addpair(lazy[node * 2 + 1], { {lazy[node].first.first + mid * lazy[node].second, lazy[node].first.second},lazy[node].second });
		}
		lazy[node] = { {0,0},0 };
	}
}

void fall(int start, int end, ll left, ll right, int node) {
	if (left > end || right < start)	return;
	if (left <= start && end <= right) {
		lazy[node] = addpair(lazy[node], { {start - left + 1,end - left + 1},1 });
		return;
	}
	int mid = (start + end) / 2;
	fall(start, mid, left, right, node * 2);
	fall(mid + 1, end, left, right, node * 2 + 1);
}

ll find(int start, int end, int pos, int node) {
	update(start, end, node);
	if (start == end)	return segtree[node];
	int mid = (start + end) / 2;
	if (pos <= mid)	return find(start, mid, pos, node * 2);
	else	return find(mid + 1, end, pos, node * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> tree[i];
	init(1, N, 1);
	cin >> Q;
	while (Q--) {
		cin >> o >> a;
		if (o == 1) {
			cin >> b;
			fall(1, N, a, b, 1);
		}
		else	cout << find(1, N, a, 1) << '\n';
	}
}