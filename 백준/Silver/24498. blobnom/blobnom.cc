#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b, c, d, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin >> a;
			mx = a;
		}
		else if (i == 1) {
			cin >> b;
			mx = max(mx, b);
		}
		else if (i == 2) {
			cin >> c;
			mx = max(mx, max(b, c));
		}
		else {
			a = b, b = c;
			cin >> c;
			d = max(c, b + min(a, c));
			mx = max(mx, d);
		}
	}
	cout << mx;
}