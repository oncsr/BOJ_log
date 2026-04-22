#include <iostream>
using namespace std;
using ll = long long;

ll f(ll n) {
	return n * (n + 1) / 2;
}

int main() {
	ll N, L;
	cin >> N >> L;
	for (ll i = L; i <= 100; i++) {
		ll s = N / i, e = s + i - 1;
		ll sum = f(e) - f(s - 1);
		while (s >= 0 && sum > N) {
			sum -= e;
			e--;
			s--;
			sum += s;
		}
		if (s < 0)	continue;
		if (sum == N) {
			for (ll k = s; k <= e; k++)	cout << k << ' ';
			return 0;
		}
	}
	cout << -1;
}