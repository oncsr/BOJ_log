#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1)	cout << 1;
	else {
		if (n % 2)	cout << -1;
		else {
			cout << n << ' ';
			int g = n - 1, t = 2;
			for (int i = 0; i < n / 2 - 1; i++) {
				cout << g << ' ' << t << ' ';
				g -= 2, t += 2;
			}
			cout << 1;
		}
	}
}