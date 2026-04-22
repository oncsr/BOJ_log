#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	ll a, b;
	cin >> N >> a >> b;
	if (gcd(a, b) == 1) {
		cout << "Yes\n";
		for (ll i = 0; i < N; i++)
			cout << a + 2 * i * b << ' ' << a + (2 * i + 1) * b << '\n';
		return 0;
	}
	cout << "No";
}