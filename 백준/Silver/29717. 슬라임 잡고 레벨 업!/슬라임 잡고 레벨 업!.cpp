#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	for (cin >> T; T--;) {
		ll N;
		cin >> N;
		N = N * (N + 1) / 2;
		ll s = 1, e = 1e9, m = (s + e) >> 1;
		while (s <= e) {
			ll M1 = m * (m - 1), M2 = m * (m + 1);
			
			if (M1 <= N && N < M2)	break;
			if (N >= M2)	s = m + 1;
			else	e = m - 1;

			m = (s + e) >> 1;
		}
		cout << m << '\n';
	}

}