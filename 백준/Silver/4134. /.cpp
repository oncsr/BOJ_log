#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int tc;
	for (cin >> tc; tc--;) {
		ll n;
		cin >> n;
		if (n <= 1)	n = 2;

		while (1) {

			bool sosu = true;
			for (int i = 2; i <= sqrt(n); i++) {
				if (n % i == 0) {
					sosu = false;
					break;
				}
			}
			if (sosu == true)	break;
			n++;

		}

		cout << n << '\n';
	}
	
}