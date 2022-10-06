#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;

ii a[500001]{};
int seg[2000005]{};
int N, b;

int find(int s, int e, int l, int r, int n) {
	if (l > e || r < s)	return 0;
	if (l <= s && e <= r)	return seg[n];
	int m = (s + e) / 2;
	return find(s, m, l, r, n * 2) + find(m + 1, e, l, r, n * 2 + 1);
}

void upt(int s, int e, int id, int n) {
	if (s == e) {
		seg[n]++;
		return;
	}
	int m = (s + e) / 2;
	if (id <= m)	upt(s, m, id, n * 2);
	else	upt(m + 1, e, id, n * 2 + 1);
	seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> b;
		a[i] = { b,i };
	}
	sort(a + 1, a + N + 1);
	for (int i = 1; i <= N; i++) {
		a[i] = { a[i].second, i };
	}
	sort(a + 1, a + N + 1);
	
	for (int i = 1; i <= N; i++) {
		cout << find(1, N, a[i].second + 1, N, 1) + 1 << '\n';
		upt(1, N, a[i].second, 1);
	}
}