#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;
	int left = (c - a1) * n0;
	if (left >= a0) {
		if (left < 0 && a0 < 0)	cout << 0;
		else	cout << 1;
	}
	else	cout << 0;
}