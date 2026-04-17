#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	for (cin >> s; s != "."; cin >> s) {
		ll ans = 1, n = s.size();
		for (ll i = 1; i * i <= n; i++) {
			if (n % i)	continue;
			bool poss = 1;
			ll interval = i;
            string temp = s.substr(0, interval);
			for (ll j = interval; j < n; j += interval) {
				if (temp == s.substr(j, interval))	continue;
				poss = 0;
				break;
			}
			if (poss)   ans = max(ans, n / i);
            poss = 1;
            interval = n/i;
            temp = s.substr(0, interval);
			for (ll j = interval; j < n; j += interval) {
				if (temp == s.substr(j, interval))	continue;
				poss = 0;
				break;
			}
            if (poss)   ans = max(ans, i);
		}
		cout << ans << '\n';
	}

}