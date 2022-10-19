#include <iostream>
#include <algorithm>
using namespace std;
int a[500001];

int bin(int s, int e, int v) {
	int m = (s + e) / 2;
	if (s > e)	return 0;
	if (s == e) {
		if (v == a[m])	return 1;
		else	return 0;
	}
	else {
		if (v > a[m])	return bin(m + 1, e, v);
		else if (v == a[m])	return 1;
		else	return bin(s, m - 1, v);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, b;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	cin >> m;
	while (m--) {
		cin >> b;
		cout << bin(0, n - 1, b) << ' ';
	}
}