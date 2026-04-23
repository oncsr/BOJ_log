#include <iostream>
using namespace std;

int main() {
	int t, n, m;
	for (cin >> t; t--;) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)	cout << 'X';
			cout << '\n';
		}
		cout << '\n';
	}
}