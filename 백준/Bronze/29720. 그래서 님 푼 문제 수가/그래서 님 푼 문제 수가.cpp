#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, k, a, b;
	cin >> n >> m >> k;
	a = n - m * k, b = a + m - 1;
	cout << max(0, a) << ' ' << max(0, b);

}