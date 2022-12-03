#include <iostream>
using namespace std;

int main() {
	int a, n = 1, i = 8;
	while (i--) {
		cin >> a;
		if (a == 9)	n = 0;
	}
	cout << (n ? 'S' : 'F');
}