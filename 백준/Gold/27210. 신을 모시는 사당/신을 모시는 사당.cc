#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, mx = 0, mn = 0, s = 0, a;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		s += (a == 1);
		mx = max(mx, 2 * s - i);
		mn = min(mn, 2 * s - i);
	}
	cout << mx - mn;
}