#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll gcd(ll a, ll b) {
	ll c = max(a, b);
	ll d = min(a, b);
	if (c % d == 0)
		return d;
	else
		return gcd(d, c % d);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll allcm, allgcd;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (i == 0)
			allcm = a;
		else
			allcm = lcm(allcm, a);
	}
	for (int i = 0; i < m; i++) {
		ll a;
		cin >> a;
		if (i == 0)
			allgcd = a;
		else
			allgcd = gcd(allgcd, a);
	}
	ll cnt = 0;
	for (int i = 1; i * i <= allgcd; i++) {
		if (i * i == allgcd) {
			if (i % allcm == 0)
				cnt++;
		}
		else {
			if (allgcd % i == 0) {
				if (i % allcm == 0)
					cnt++;
				if ((allgcd / i) % allcm == 0)
					cnt++;
			}
		}
	}
	cout << cnt << '\n';
}