#include <iostream>
using namespace std;

int main() {
	int n, s = 2, d = 2;
	cin >> n;
	for (int i = 1; i < n; i++) {
		s += d;
		if (i % 3 == 2)	continue;
		d++;
	}
	cout << s;
}