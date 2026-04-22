#include <iostream>
using namespace std;

int main() {
	string a;
	int b, s = 0, g = 1;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] < 60)	s += g * (a[i] - '0');
		else	s += g * (a[i] - 'A' + 10);
		g *= b;
	}
	cout << s;
}