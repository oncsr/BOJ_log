#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	for (cin >> t; t--;) {
		ll n, m, k;
		cin >> n >> m >> k;
		if (3 * n + 3 * m - 12 == k && n >= 3 && m >= 3)	cout << "1 1 2 2 3 3\n";
		else if (3 * n + 2 * m - 9 == k && n >= 2 && m >= 3)	cout << "1 1 2 2 2 3\n";
		else if (2 * n + 3 * m - 9 == k && n >= 3 && m >= 2)	cout << "1 1 2 2 3 2\n";
		else if (3 * n + m - 6 == k && n >= 1 && m >= 3)	cout << "1 1 1 2 1 3\n";
		else if (2 * n + 2 * m - 7 == k && n >= 2 && m >= 2)	cout << "1 1 1 2 2 2\n";
		else if (n + 3 * m - 6 == k && n >= 3 && m >= 1)	cout << "1 1 2 1 3 1\n";
		else	cout << "IMPOSSIBLE\n";
	}

}