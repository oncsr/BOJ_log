#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string arr[51];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int mn = min(n, m) - 1;
	int result = 1;
	bool br = false;
	for (int i = mn; i > 0; i--) {
		for (int j = 0; j + i < n; j++) {
			for (int k = 0; k + i < m; k++) {
				char a, b, c, d;
				a = arr[j][k];
				b = arr[j + i][k];
				c = arr[j][k + i];
				d = arr[j + i][k + i];
				if (a == b && c == d && b == c) {
					result = (i + 1) * (i + 1);
					br = true;
					break;
				}
			}
			if (br)
				break;
		}
		if (br)
			break;
	}
	cout << result << '\n';
}