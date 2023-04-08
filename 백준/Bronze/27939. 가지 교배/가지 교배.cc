#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, s = 1, m, k;
	bool arr[1000]{};
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		arr[i] = a == 'P';
	}
	for (cin >> m >> k; m--;) {
		int t = 0;
		for (int i = 0; i < k; i++) {
			int a;
			cin >> a;
			t |= arr[a - 1];
		}
		s &= t;
	}
	cout << (s ? 'P' : 'W');
}