#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		long long a, b;
		cin >> a >> b;
		if (a <= 2 || b <= 2)	cout << "First\n";
		else if (b & 1) {
			if (a & 1)	cout << "First\n";
			else	cout << "Second\n";
		}
		else	cout << "Second\n";
	}
}