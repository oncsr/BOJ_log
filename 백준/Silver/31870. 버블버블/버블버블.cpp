#include <bits/stdc++.h>
using namespace std;
 
int N;
vector<int> seg;
void upt(int s, int e, int i, int n) {
	if (s == e) { seg[n]++; return; }
	int m = (s + e) >> 1;
	if (i <= m)	upt(s, m, i, n * 2);
	else	upt(m + 1, e, i, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}
 
int find(int s, int e, int l, int r, int n) {
	if (l > r || l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) >> 1;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	cin >> N;
	
	vector<int> arr(N);
	
	for (int& i : arr)	cin >> i;
	vector<pair<int, int>> arr1(N), arr2(N);
	
	for (int i = 0; i < N; i++) {
		arr1[i] = { arr[i],i + 1 };
		arr2[N - i - 1] = { arr[i],N - i };
	}
 
	seg = vector<int>(4 * N);
	sort(arr1.begin(), arr1.end(), greater<>());
	sort(arr2.begin(), arr2.end(), greater<>());
	
	long long A = 0, B = 1;
	for (auto [a, b] : arr1) {
		A += find(1, N, 1, b - 1, 1);
		upt(1, N, b, 1);
	}
 
	seg = vector<int>(4 * N);
	for (auto [a, b] : arr2) {
		B += find(1, N, 1, b - 1, 1);
		upt(1, N, b, 1);
	}
	cout << min(A, B);
 
}