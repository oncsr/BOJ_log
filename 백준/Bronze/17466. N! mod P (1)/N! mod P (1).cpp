#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll N, P;
	cin >> N >> P;
	ll s = 1;
	for (ll i = 1; i <= N; i++) {
		s *= i;
		s %= P;
	}
	cout << s;
}