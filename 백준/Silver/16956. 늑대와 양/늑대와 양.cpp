#include <iostream>
using namespace std;

int main() {
	int n, m;
	string a[500]{};
	cin >> n >> m;
	bool f = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bool ps = false, pw = false;
		for (int j = 0; j < m - 1; j++) {
			if (a[i][j] == 'S' && a[i][j + 1] == 'W'
				|| a[i][j] == 'W' && a[i][j + 1] == 'S')	f = true;
		}
		if (i) {
			for (int j = 0; j < m; j++) {
				if (a[i - 1][j] == 'S' && a[i][j] == 'W'
					|| a[i - 1][j] == 'W' && a[i][j] == 'S')	f = true;
			}
		}
	}
	if (f)	cout << 0;
	else {
		cout << "1\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << (a[i][j] == '.' ? 'D' : a[i][j]);
			cout << '\n';
		}
	}
}