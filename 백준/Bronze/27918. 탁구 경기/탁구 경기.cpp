#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, d = 0, p = 0;
	for (cin >> N; N--;) {
		char i;
		cin >> i;
		d += (i == 'D');
		p += (i == 'P');
		if (abs(d - p) == 2)	break;
	}
	cout << d << ':' << p;
}