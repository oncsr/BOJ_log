#include <iostream>
using namespace std;
typedef unsigned long long int ll;

int main() {
	ll a, b;
	cin >> a >> b;
	a--;
	ll aa = 0, bb = 0;
	ll elsa = 0, elsb = 0;
	ll cnta = 1, cntb = 1;
	while (b > 0) {
		if (b % 4 <= 1)
			elsb = b % 4;
		else
			elsb = b % 4 + 1;
		bb += cntb * ((b / 4) * 4 + elsb);
		b /= 4;
		cntb *= 4;
	}
	while (a > 0) {
		if (a % 4 <= 1)
			elsa = a % 4;
		else
			elsa = a % 4 + 1;
		aa += cnta * ((a / 4) * 4 + elsa);
		a /= 4;
		cnta *= 4;
	}
	cout << bb - aa << '\n';
}