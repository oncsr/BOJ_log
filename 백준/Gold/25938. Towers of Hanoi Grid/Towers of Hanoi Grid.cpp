#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int d, n;
		cin >> d >> n;
		cout << "Grid #" << t << ": ";
		if (d > (n - 1) * (n - 1) + 1)	cout << "impossible\n";
		else	cout << 2 * (n - 1) * d << '\n';
		if (t < T)	cout << '\n';
	}
}