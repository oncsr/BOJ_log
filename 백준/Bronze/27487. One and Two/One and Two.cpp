#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int n, arr[1000]{}, two = 0;
		cin >> n;
		for (int i = 0; i < n; i++)	cin >> arr[i], two += arr[i] == 2;
		if (two & 1) {
			cout << -1 << '\n';
			continue;
		}
		if (!two) {
			cout << 1 << '\n';
			continue;
		}
		int ttwo = 0;
		for (int i = 0; i < n; i++) {
			ttwo += arr[i] == 2;
			if (ttwo == (two >> 1)) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
}