#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int e[10001]{};
	for (int i = 2; i * i <= 10000; i++)
		if (!e[i])
			for (int j = i * i; j <= 10000; j += i)
				e[j] = 1;
	vector<ll> sosu;
	for (int i = 2; i <= 10000; i++)
		if (!e[i])	sosu.push_back(i);

	int n, arr[10000001]{};
	for (cin >> n; n--;) {
		ll a, b;
		cin >> a >> b;
		a = b - a;
		for (ll i : sosu) {
			if (i * i > a)	break;
			while (a % i == 0) {
				a /= i;
				arr[i]++;
			}
		}
		for (ll i : sosu) {
			if (i * i > b)	break;
			while (b % i == 0) {
				b /= i;
				arr[i]--;
			}
		}
		if (a > 1)	arr[a]++;
		if (b > 1)	arr[b]--;
	}
	ll hi = 1, lo = 1;
	for (int i = 2; i <= 10000000; i++) {
		while (arr[i] > 0) {
			hi = (hi * i) % mod;
			arr[i]--;
		}
		while (arr[i] < 0) {
			lo = (lo * i) % mod;
			arr[i]++;
		}
	}
	cout << hi << ' ' << lo;
}