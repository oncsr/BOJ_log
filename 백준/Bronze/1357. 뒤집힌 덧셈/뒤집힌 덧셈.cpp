#include <iostream>
#include <cmath>
using namespace std;

int rev(int a) {
	int len = log10(a) + 1, g = 1, x = 0, h = 1;
	for (int i = 1; i < len; i++)	g *= 10;
	while (a) {
		x += (a / g) * h;
		a -= (a / g) * g;
		g /= 10, h *= 10;
	}
	return x;
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << rev(rev(x) + rev(y));
}