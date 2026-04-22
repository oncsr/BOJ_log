#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, t;
	cin >> N >> t;
	cout << "! " << N / 2 + t << endl;
	int T = N / 2, a, b;
	if (!t) {
		while (T--) {
			cin >> a >> b;
			cout << b << ' ' << a << endl;
		}
	}
	else {
		int arr[2001] = { 1,1 };
		cout << "1 1" << endl;
		T--;
		while (T--) {
			cin >> a >> b;
			arr[a]++, arr[b]++;
			cout << b << ' ' << a << endl;
		}
		for (int i = 1; i <= N; i++) {
			if (!arr[i]) {
				cout << i << ' ' << i << endl;
				return 0;
			}
		}
	}
}