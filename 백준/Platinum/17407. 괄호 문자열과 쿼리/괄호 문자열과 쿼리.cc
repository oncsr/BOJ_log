#include <iostream>
using namespace std;

string S;
int N, M, x, ans = 0;
int arr[100001]{}, seg[262145]{}, lazy[262145]{};
int state[100001]{};

void init(int s, int e, int n) {
	if (s == e) {
		seg[n] = arr[s];
		return;
	}
	int m = (s + e) / 2;
	init(s, m, n * 2);	init(m + 1, e, n * 2 + 1);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

void prop(int s, int e, int n) {
	if (lazy[n]) {
		seg[n] += lazy[n];
		if (s != e) {
			lazy[n * 2] += lazy[n];
			lazy[n * 2 + 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

void query(int s, int e, int l, int r, int v, int n) {
	prop(s, e, n);
	if (l > e || r < s)	return;
	if (l <= s && e <= r) {
		seg[n] += v;
		if (s != e) {
			lazy[n * 2] += v;
			lazy[n * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) / 2;
	query(s, m, l, r, v, n * 2);	query(m + 1, e, l, r, v, n * 2 + 1);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}
int find(int s, int e, int i, int n) {
	prop(s, e, n);
	if (s == e)	return seg[n];
	int m = (s + e) / 2;
	if (i <= m)	return find(s, m, i, n * 2);
	else	return find(m + 1, e, i, n * 2 + 1);
}

int main() {
	cin >> S;
	N = S.size();
	for (int i = 0; i < N; i++) {
		if (S[i] == '(')	arr[i + 1] = arr[i] + 1, state[i + 1] = 1;
		else	arr[i + 1] = arr[i] - 1, state[i + 1] = 0;
	}
	init(1, N, 1);
	for (cin >> M; M--;) {
		cin >> x;
		if (state[x])	query(1, N, x, N, -2, 1);
		else	query(1, N, x, N, 2, 1);
		state[x] ^= 1;
		int start = find(1, N, 1, 1), end = find(1, N, N, 1);
		if (start == 1 && end == 0 && seg[1] == 0)	ans++;
	}
	cout << ans;
}