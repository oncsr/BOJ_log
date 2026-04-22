#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	if (k <= n) {
		cout << "NO";
		return 0;
	}
	ll s = 0, e = n / 2, m = (s + e) / 2;
	while (s <= e) {
		ll G = (n - m + 1) * (m + 1);
		if (G == k) {
			cout << "YES";
			return 0;
		}
		if (G < k) {
			if (s == e) {
				cout << "NO";
				return 0;
			}
			s = m + 1;
		}
		else {
			if (s == e) {
				cout << "NO";
				return 0;
			}
			e = m;
		}
		m = (s + e) / 2;
	}
	cout << "YES";
}