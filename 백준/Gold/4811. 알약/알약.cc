#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll t, n, d[31][31]{}, b[31]{};
	d[1][1] = 1, b[1] = 1;
	for (int i = 1; i < 30; i++) {
		ll s = 0;
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= j + 1; k++)
				d[i + 1][k] += d[i][j];
			s += d[i][j] * ((ll)j + 1);
		}
		b[i + 1] = s;
	}
	for (cin >> n; n; cin >> n)	cout << b[n] << '\n';
}