#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, a = 3, p = 4;
	cin >> n;
	for (ll i = 2; i <= n; i++) {
		a = (p * 2 + a) % 1000000007;
		p = (p * 2) % 1000000007;
	}
	cout << a;
}