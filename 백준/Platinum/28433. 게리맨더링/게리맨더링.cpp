#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		int N;
		cin >> N;
		
		int pos = 0, neg = 0;
		ll s = 0;
		for (int i = 0; i < N; i++) {
			ll a;
			cin >> a;
			if (a < 0) {
				bool poss = s > 0;
				s += a;
				if (poss) {
					if (s <= 0)	s = a;
				}
			}
			else if (a > 0) {
				bool poss = s <= 0;
				pos++;
				s += a;
				if (poss) {
					if (s > 0)	continue;
					neg++;
				}
				s = a;
			}
		}
		if (s < 0)	neg++;
		cout << (pos > neg ? "YES\n" : "NO\n");

	}
}