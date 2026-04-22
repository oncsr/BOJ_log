#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int ans[1001] = { 0,3 };
	int s = 3;
	for (int x = 2; x <= 1000; x++) {
		for (int i = 1; i < x; i++)
			if (gcd(i, x) == 1)	s += 2;
		ans[x] = s;
	}

	int TC;
	for (cin >> TC; TC--;) {
		int n;
		cin >> n;
		cout << ans[n] << '\n';
	}
}