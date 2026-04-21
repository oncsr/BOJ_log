#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K;
	bool forever = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		char a, b;
		ll x, y;
		cin >> a >> x >> b >> y;
		if (a == '-') {
			if (b == '-') {
				if (forever)	K = (K - min(x, y) + mod) % mod;
				else	K -= min(K, min(x, y));
			}
			else if (b == '+') {
				if (forever)	K = (K + y) % mod;
				else	K += y;
			}
			else {
				if (y == 0) {
					if (forever)	K = (K - x + mod) % mod;
					else	K -= min(K, x);
				}
				else {
					if (forever)	K = (K * y) % mod;
					else {
						if (log10(K) + log10(y) > 16) {
							forever = 1;
							K = ((K % mod) * (y % mod)) % mod;
						}
						else	K *= y;
					}
				}
			}
		}
		else if (a == '+') {
			if (b == '-') {
				if (forever)	K = (K + x) % mod;
				else	K += x;
			}
			else if (b == '+') {
				if (forever)	K = (K + max(x, y)) % mod;
				else	K += max(x, y);
			}
			else {
				if (y <= 1) {
					if (forever)	K = (K + x) % mod;
					else	K += x;
				}
				else {
					if (forever)	K = (K * y) % mod;
					else {
						if (K == 0)	K += x;
						else {
							if (log10(K) + log10(y) > 16) {
								forever = 1;
								K = ((K % mod) * (y % mod)) % mod;
							}
							else	K = max(K * y, K + x);
						}
					}
				}
			}
		}
		else {
			if (b == '-') {
				if (x == 0) {
					if (forever)	K = (K - y + mod) % mod;
					else	K -= min(K, y);
				}
				else {
					if (forever)	K = (K * x) % mod;
					else {
						if (log10(K) + log10(x) > 16) {
							forever = 1;
							K = ((K % mod) * (x % mod)) % mod;
						}
						else	K *= x;
					}
				}
			}
			else if (b == '+') {
				if (x <= 1) {
					if (forever)	K = (K + y) % mod;
					else	K += y;
				}
				else {
					if (forever)	K = (K * x) % mod;
					else {
						if (K == 0)	K += y;
						else {
							if (log10(K) + log10(x) > 16) {
								forever = 1;
								K = ((K % mod) * (x % mod)) % mod;
							}
							else	K = max(K * x, K + y);
						}
					}
				}
			}
			else {
				if (x == 0 && y == 0)	forever = 0, K = 0;
				else {
					if (forever)	K = (K * max(x, y)) % mod;
					else {
						if (log10(K) + log10(max(x, y)) > 16) {
							forever = 1;
							K = ((K % mod) * (max(x, y) % mod)) % mod;
						}
						else	K *= max(x, y);
					}
				}
			}
		}
		if (!forever && log10(K) > 16) {
			forever = 1;
			K %= mod;
		}
	}
	cout << K % mod;
}