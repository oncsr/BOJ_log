#include <iostream>
using namespace std;
using ll = long long;
int main() {
	ll n;
	cin >> n;
	ll a = 0, b = 3037000500, h = b / 2;
	while (b - a > 1) {
		if (h * h >= n)	b = h;
		else	a = h;
		h = (a + b) / 2;
	}
	cout << (n ? b : 0);
}