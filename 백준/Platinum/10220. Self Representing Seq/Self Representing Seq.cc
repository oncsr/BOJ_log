#include <iostream>
using namespace std;

int main() {
	int T, n; cin >> T;
	for (; T--;) {
		cin >> n;
		if (n == 4)	cout << 2;
		else if (n == 5)	cout << 1;
		else if (n > 6)	cout << 1;
		else	cout << 0;
		cout << '\n';
	}
}