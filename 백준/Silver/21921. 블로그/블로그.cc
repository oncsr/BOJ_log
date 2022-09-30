#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;
	ll a[250000]{}, s = 0, mx = 0, g = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		if (i >= m - 1) {
			if (s > mx) {
				mx = s;
				g = 1;
			}
			else if (s == mx)	g++;
			s -= a[i - (m - 1)];
		}
	}
	if (mx)	cout << mx << '\n' << g;
	else	cout << "SAD";
}