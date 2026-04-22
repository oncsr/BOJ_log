#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n, m, a, k, s, x, y;
	cin >> n >> m >> a >> k;
	s = n * m - a - m + k, x = n - s / m, y = n - max(0LL, s - (n - 1) * (m - 1));
	cout << y << ' ' << x;

}