#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll N, ans1 = 0, ans2 = 1, mod = 1000000007, s = 0;
	cin >> N;
	for (ll i = N; i >= 1; i--) {
		s += i;
		ans1 = (ans1 + s * 2 * i) % mod;
		ans2 = (ans2 * i * i) % mod;
	}
	cout << ans1 << ' ' << ans2;
}