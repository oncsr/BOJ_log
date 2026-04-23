#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << "YES\n";
	if (n % 4 == 3) {
		cout << "1 3 2 ";
		int s = 4;
		for (int i = 0; i < n / 4; i++) {
			cout << s << ' ' << s + 1 << ' ' << s + 3 << ' ' << s + 2 << ' ';
			s += 4;
		}
	}
	else {
		int s = 1;
		for (int i = 0; i < n / 4; i++) {
			cout << s << ' ' << s + 1 << ' ' << s + 3 << ' ' << s + 2 << ' ';
			s += 4;
		}
		if (n % 4 == 1)	cout << s;
		if (n % 4 == 2)	cout << s << ' ' << s + 1;
	}
}