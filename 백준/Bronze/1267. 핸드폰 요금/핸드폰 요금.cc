#include <iostream>
using namespace std;

int main() {
	int n, a, y = 0, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		y += (a / 30 + 1) * 10;
		m += (a / 60 + 1) * 15;
	}
	if (y < m)	cout << "Y ";
	else if (y > m)	cout << "M ";
	else	cout << "Y M ";
	cout << min(y, m);
}