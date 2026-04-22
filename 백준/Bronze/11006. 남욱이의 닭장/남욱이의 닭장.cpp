#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int n, m;
		cin >> n >> m;
		cout << 2 * m - n << ' ' << n - m << '\n';
	}
}