#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	string gaji;
	cout << "? " << (n + 1) / 2 << endl;
	cin >> gaji;
	ll s = 1, e = (n + 1) / 2, m = (s + e) / 2;
	ll a, b;
	string t;
	while (s <= e) {
		cout << "? " << m << endl;
		cin >> t;
		if (t == gaji) {
			if (s == m) {
				a = s;
				break;
			}
			e = m;
		}
		else {
			if (s == m) {
				a = s + 1;
				break;
			}
			s = m + 1;
		}
		m = (s + e) / 2;
	}
	s = (n + 1) / 2 + 1, e = n, m = (s + e) / 2;
	while (s <= e) {
		cout << "? " << m << endl;
		cin >> t;
		if (t == gaji) {
			if (s == e) {
				b = s;
				break;
			}
			s = m + 1;
		}
		else {
			if (s == m) {
				b = s - 1;
				break;
			}
			e = m;
		}
		m = (s + e) / 2;
	}
	cout << "! " << a << ' ' << b << endl;
}