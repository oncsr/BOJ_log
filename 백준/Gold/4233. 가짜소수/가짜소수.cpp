#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int e[100000]{};
vector<ll> prm;

ll mod;

ll power(ll a, ll b) {
	if (b == 0)	return 1;
	if (b == 1)	return a;
	ll p = power(a, b / 2);
	(p *= p) %= mod;
	if (b & 1)	return p * a % mod;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 2; i * i <= 1000000000; i++)
		if (!e[i])
			for (int j = i * 2; j < 100000; j += i)
				e[j] = 1;
	for (int i = 2; i < 100000; i++)
		if (!e[i])
			prm.push_back((ll)i);
	ll p, a;
	for (cin >> p >> a; p != 0 && a != 0; cin >> p >> a) {
		bool f = true;
		ll temp = p;
		for (int i = 0; i < prm.size(); i++) {
			if (prm[i] * prm[i] > temp)	break;
			if (temp % prm[i] == 0) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << "no\n";
			continue;
		}
		mod = p;
		if (power(a, p) == a)	cout << "yes\n";
		else	cout << "no\n";
	}
}