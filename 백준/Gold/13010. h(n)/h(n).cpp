#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
using ll = long long;

int main() {
	ll x;
	cin >> x;
	

	ll e[1000001]{};
	for (ll i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (ll j = i * 2; j <= 1000000; j += i)
				if (!e[j])	e[j] = i;

	priority_queue<ll, vector<ll>, greater<> > Q;
	ll g = sqrt(x);
	if (g * g == x) {
		bool fd = false;
		for (ll i = 2; i * i <= g; i++) {
			if (g % i == 0) {
				fd = true;
				break;
			}
		}
		if (!fd)	Q.push(g);
	}

	for (ll i = 2; i * i * i <= x; i++) {
		ll temp = i;
		ll cnt = 1, s = 0, T = e[temp];
		while (e[temp]) {
			if (T != e[temp]) {
				cnt *= (s + 1);
				s = 0;
				T = e[temp];
			}
			s++;
			temp /= e[temp];

		}
		if (temp != 1) {
			if (T == temp)	s++;
			else {
				cnt *= 2;
			}
			cnt *= (s + 1);
		}
		if ((double)cnt * log10(i) > 18.)	continue;
		ll C = 1;
		while (cnt--)	C *= i;
		if (C == x) {
			Q.push(i);
			cout << Q.top();
			return 0;
		}
	}
	if (Q.empty())	cout << -1;
	else	cout << Q.top();

}