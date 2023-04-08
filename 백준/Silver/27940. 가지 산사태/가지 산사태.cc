#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k, s = 0, a, b;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		s += b;
		if (s > k) {
			cout << i << ' ' << 1;
			return 0;
		}
	}
	cout << -1;
}