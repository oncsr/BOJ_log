#include <iostream>
using namespace std;

int main() {
	int N, n = 1;
	string a;
	char c = '0';
	for (cin >> N; N--;) {
		cin >> a;
		if (c == '0')	c = a[0];
		else {
			if (c != a[0]) {
				n = 0;
				break;
			}
		}
	}
	cout << n;
}