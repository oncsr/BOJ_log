#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

char op;
ll N, Q, a, b, c;
ll tree[200001]{};
ii seg[524289]{};
ll lazy[524289]{};

void init(int start, int end, int node) {
	if (start == end) {
		seg[node].first = seg[node].second = tree[start];
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	seg[node].first = min(seg[node * 2].first, seg[node * 2 + 1].first);
	seg[node].second = seg[node * 2].second + seg[node * 2 + 1].second;
}

void prop(int start, int end, int node) {
	if (lazy[node]) {
		seg[node].first += lazy[node];
		seg[node].second += lazy[node] * (ll)(end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void add(int start, int end, int left, int right, int val, int node) {
	prop(start, end, node);
	if (left > end || right < start)	return;
	if (left <= start && end <= right) {
		seg[node].first += val;
		seg[node].second += val * (ll)(end - start + 1);
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	add(start, mid, left, right, val, node * 2);
	add(mid + 1, end, left, right, val, node * 2 + 1);
	seg[node].first = min(seg[node * 2].first, seg[node * 2 + 1].first);
	seg[node].second = seg[node * 2].second + seg[node * 2 + 1].second;
}

ii find(int start, int end, int left, int right, int node) {
	prop(start, end, node);
	if (left > end || right < start)	return { 2147483647,0 };
	if (left <= start && end <= right)	return seg[node];
	int mid = (start + end) / 2;
	ii A = find(start, mid, left, right, node * 2);
	ii B = find(mid + 1, end, left, right, node * 2 + 1);
	return { min(A.first,B.first),A.second + B.second };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)	cin >> tree[i];
	init(1, N, 1);
	while (Q--) {
		cin >> op >> a >> b;
		if (op == 'P') {
			cin >> c;
			add(1, N, a, b, c, 1);
		}
		else {
			ii ans = find(1, N, a, b, 1);
			if (op == 'M')	cout << ans.first;
			else	cout << ans.second;
			cout << '\n';
		}
	}
}