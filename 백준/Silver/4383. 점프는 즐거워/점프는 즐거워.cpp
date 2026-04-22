#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	while (cin >> n) {
		int a, t;
		cin >> t;
		int arr[3000]{};
		for (int i = 1; i < n; i++) {
			cin >> a;
			arr[abs(a - t)]++;
			t = a;
		}
		bool f = 0;
		for (int i = 1; i < n; i++) {
			if (!arr[i]) {
				cout << "Not jolly\n";
				f = 1;
				break;
			}
		}
		if (f)	continue;
		cout << "Jolly\n";
	}
}