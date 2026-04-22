#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int n, d[1001]{}, mx = -1000001;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> d[i];
			d[i] = (d[i - 1] >= 0 ? d[i - 1] + d[i] : d[i]);
			mx = max(mx, d[i]);
		}
		cout << mx << '\n';
	}
}