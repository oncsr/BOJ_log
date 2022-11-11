#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000;

ll fib(ll n) {
	static map<ll, ll> M;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		if (n % 2) {
			if (!M[n / 2])
				M[n / 2] = fib(n / 2);
			if (!M[n / 2 + 1])
				M[n / 2 + 1] = fib(n / 2 + 1);
			return M[n / 2] % MOD * M[n / 2] % MOD + M[n / 2 + 1] % MOD * M[n / 2 + 1] % MOD;
		}
		else {
			if (!M[n / 2])
				M[n / 2] = fib(n / 2);
			if (!M[n / 2 - 1])
				M[n / 2 - 1] = fib(n / 2 - 1);
			return M[n / 2] % MOD * (2 * M[n / 2 - 1] % MOD + M[n / 2] % MOD) % MOD;
		}
	}
}

int main() {
	int T;
	for (cin >> T; T--;) {
		ll N;
		cin >> N;
		cout << fib(N) % MOD << '\n';
	}
}