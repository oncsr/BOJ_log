#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int s = 1, t = 0;
	for (int i = 1; i <= b; i++) {
		if (i >= a)	cout << (s % 10);
		int temp = s;
		s += t;
		t = temp;
		s %= 10;
		t %= 10;
	}
}