#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		bool f = 0;
		int x = N + (10 - (N % 10));
		while (x <= N + 100) {
			int s = N;
			for (char j : to_string(x))	s += j - '0';
			if (s == x) {
				cout << x << ' ';
				f = 1;
				break;
			}
			x += 10;
		}
		if (!f)	cout << -1 << ' ';
	}

}