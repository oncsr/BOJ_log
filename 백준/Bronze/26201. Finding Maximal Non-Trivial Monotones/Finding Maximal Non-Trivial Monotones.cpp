#include <iostream>
using namespace std;

int main() {
	int n, a = 0, s = 0;
	char i;
	cin >> n;
	while (n--) {
		cin >> i;
		if (i == 'a')	a++;
		else {
			if (a > 1)	s += a;
			a = 0;
		}
	}
	if (a > 1)	s += a;
	cout << s;
}