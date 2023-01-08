#include <iostream>
using namespace std;

int main() {
	int m, n;
	string a[20]{}, b[20]{};
	cin >> m >> n;
	a[0] = '+', b[0] = '+';
	for (int i = 0; i < 2 * m + 1; i++)	a[0] += '-';
	for (int i = 0; i < 2 * n + 1; i++)	b[0] += '-';
	a[0] += '+', b[0] += '+';
	for (int i = 1; i <= m; i++) {
		a[i] = 'I';
		for (int j = 0; j < m; j++)	a[i] += "-X";
		a[i] += "-I";
	}
	for (int i = 1; i <= n; i++) {
		b[i] = 'I';
		for (int j = 0; j < n; j++)	b[i] += "-X";
		b[i] += "-I";
	}
	a[m + 1] = a[0], b[n + 1] = b[0];
	for (int i = 0; i < min(m, n) + 2; i++)
		cout << a[i] << "          " << b[i] << '\n';
	if (m > n) {
		for (int i = n + 2; i <= m + 1; i++)
			cout << a[i] << '\n';
	}
	else {
		for (int i = m + 2; i <= n + 1; i++) {
			for (int j = 0; j < 2 * m + 3; j++)	cout << ' ';
			cout << "          " << b[i] << '\n';
		}
	}
}