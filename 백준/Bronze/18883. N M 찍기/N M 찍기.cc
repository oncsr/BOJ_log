#include <iostream>
using namespace std;

int main() {
	int n, m, s = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << s++;
			if (j != m - 1)	cout << ' ';
		}
		cout << '\n';
	}
}