#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int T;
	ll a, b, c, d;
	for (cin >> T; T--;) {
		cin >> a >> b >> c >> d;
		if (a * b > c * d)	cout << "TelecomParisTech\n";
		else if (a * b == c * d)	cout << "Tie\n";
		else	cout << "Eurecom\n";
	}
}