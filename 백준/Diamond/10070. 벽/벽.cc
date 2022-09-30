#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;	// {최대, 최소}

//	2022-08-17
//	BOJ 10070

pll seg[4194305]{};
ll lazy[4194305]{};
int n, k, op, a, b;
ll h;

void lazy_init(int start, int end, int node) {
	lazy[node] = -1;
	if (start == end)	return;
	int mid = (start + end) / 2;
	lazy_init(start, mid, node * 2);
	lazy_init(mid + 1, end, node * 2 + 1);
}

void prop(int start, int end, int node) {
	if (lazy[node] != -1) {
		seg[node] = { lazy[node],lazy[node] };
		if (start != end) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = -1;
	}
}

// 높이는 쿼리
void query1(int start, int end, int left, int right, ll val, int node) {
	prop(start, end, node);
	if (left > end || right < start || seg[node].first >= val)	return;
	if (left <= start && end <= right && seg[node].second <= val) {
		seg[node] = { val,val };
		if (start != end) {
			lazy[node * 2] = val;
			lazy[node * 2 + 1] = val;
		}
		return;
	}
	int mid = (start + end) / 2;
	query1(start, mid, left, right, val, node * 2);
	query1(mid + 1, end, left, right, val, node * 2 + 1);
	seg[node] = { min(seg[node * 2].first,seg[node * 2 + 1].first), max(seg[node * 2].second, seg[node * 2 + 1].second) };
}

// 낮추는 쿼리
void query2(int start, int end, int left, int right, ll val, int node) {
	prop(start, end, node);
	if (left > end || right < start || seg[node].second <= val)	return;
	if (left <= start && end <= right && seg[node].first >= val) {
		seg[node] = { val,val };
		if (start != end) {
			lazy[node * 2] = val;
			lazy[node * 2 + 1] = val;
		}
		return;
	}
	int mid = (start + end) / 2;
	query2(start, mid, left, right, val, node * 2);
	query2(mid + 1, end, left, right, val, node * 2 + 1);
	seg[node] = { min(seg[node * 2].first,seg[node * 2 + 1].first), max(seg[node * 2].second, seg[node * 2 + 1].second) };
}

// 마지막 출력
void print(int start, int end, int node) {
	prop(start, end, node);
	if (start == end) {
		cout << seg[node].first << '\n';
		return;
	}
	int mid = (start + end) / 2;
	print(start, mid, node * 2);
	print(mid + 1, end, node * 2 + 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	lazy_init(1, n, 1);
	while (k--) {
		cin >> op >> a >> b >> h;
		if (op == 1)	query1(1, n, a + 1, b + 1, h, 1);
		else	query2(1, n, a + 1, b + 1, h, 1);
	}
	print(1, n, 1);
}