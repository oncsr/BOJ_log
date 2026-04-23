#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int d[300001]{}, n, D, a, mx = 0;
	cin >> n >> D;
	for (int i = 0; i < n; i++) {
		cin >> a;
		d[a]++;
		mx = max(mx, a);
	}
	ll s = 0;
	for (; D--;) {
		if (!mx)	break;
		s += d[mx];
		d[mx - 1] += d[mx];
		mx--;
	}
	cout << s;
}