#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int l = 10001, r = -10001, u = -10001, d = 10001, n, a, b;
	for (cin >> n; n--;) {
		cin >> a >> b;
		l = min(l, a), r = max(r, a);
		u = max(u, b), d = min(d, b);
	}
	cout << (r - l) * (u - d);
}