#include <bits/stdc++.h>
using namespace std;
 
int arr[500001]{}, seg[1048577]{};
 
int init(int s, int e, int n) {
	if (s == e)	return seg[n] = arr[s];
	int m = (s + e) >> 1;
	return seg[n] = init(s, m, n * 2) + init(m + 1, e, n * 2 + 1);
}
 
int F(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return F(s, m, l, r, n * 2) + F(m + 1, e, l, r, n * 2 + 1);
}
 
void U(int s, int e, int i, int n) {
	if (s == e) {
		seg[n] = 0; return;
	}
	int m = (s + e) >> 1;
	if (i <= m)	U(s, m, i, n * 2);
	else	U(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
 
	init(1, N, 1);
 
	for (; M--;) {
		int a;
		cin >> a;
		cout << F(1, N, 1, a, 1) << ' ';
		U(1, N, a, 1);
	}
 
}