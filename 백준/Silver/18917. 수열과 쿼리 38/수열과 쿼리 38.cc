#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long s = 0, g = 0, x, m, o;
	cin >> m;
	while (m--) {
		cin >> o;
		if (o < 3) {
			cin >> x;
			g ^= x;
			if (o == 2)	x *= -1;
			s += x;
		}
		else cout << (o == 3 ? s : g) << '\n';
	}
}