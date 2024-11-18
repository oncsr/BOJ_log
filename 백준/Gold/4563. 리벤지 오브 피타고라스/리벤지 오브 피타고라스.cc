#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll A;
	for (cin >> A; A; cin >> A) {
		int cnt = 0;
		for (ll i = 1; i <= A; i++) {
			if ((A * A - i * i) % (2 * i) == 0 && (A * A - i * i) / (2 * i) > A)	cnt++;
		}
		cout << cnt << '\n';
	}

}