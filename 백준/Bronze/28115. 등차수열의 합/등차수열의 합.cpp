#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, a, d, temp, fir;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (!i)	fir = a;
		else if (i == 1)	d = a - temp;
		else if (a - temp != d) {
			cout << "NO";
			return 0;
		}
		temp = a;
	}
	cout << "YES\n";
	for (ll i = 0; i < n; i++)	cout << fir + d * i << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++)	cout << "0 ";
}