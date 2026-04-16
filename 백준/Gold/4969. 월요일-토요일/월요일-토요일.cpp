#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<int> s;
	for (int i = 2; i < 300000; i++) {
		if (i % 7 != 1 && i % 7 != 6)	continue;
		bool g = 0;
		for (int j : s) {
			if (j > i / j)	break;
			if (i % j == 0) { g = 1; break; }
		}
		if (!g)	s.push_back(i);
	}
	int n;
	for (cin >> n; n > 1; cin >> n) {
		cout << n << ": ";
		for (int i : s)	if (n % i == 0)	cout << i << ' ';
		cout << '\n';
	}

}