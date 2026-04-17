#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int n;
		cin >> n;
		cout << (n < 3 ? 1 : 3) << '\n';
	}

}