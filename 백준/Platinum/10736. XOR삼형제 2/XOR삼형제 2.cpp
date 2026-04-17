#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		if (n == 1) { cout << "1\n1\n"; continue; }
		int k = log2(n), g = (1 << (k - 1)), m = (1 << k) + g - 1;
		int p = min(n, m);
		cout << p - g + 1 << '\n';
		for (int i = g; i <= p; i++)	cout << i << ' ';
		cout << '\n';
	}

}