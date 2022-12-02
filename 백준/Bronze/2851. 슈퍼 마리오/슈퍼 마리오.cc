#include <iostream>
using namespace std;

int main() {
	int s = 0, mn = 100, a, t = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		s += a;
		if (abs(100 - s) <= mn)	mn = abs(100 - s), t = s;
	}
	cout << t;
}