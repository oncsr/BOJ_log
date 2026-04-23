#include <iostream>
using namespace std;

int main() {
	int K, a[6]{}, b[6]{}, s = 0, pos = 0, pat = 0, four = 0;
	cin >> K;
	for (int i = 0; i < 6; i++) {
		cin >> a[i] >> b[i];
		if (a[i] == 4) {
			pos = i;
			four++;
		}
		pat += a[i];
	}
	if (pat == 16) {
		for (int i = 0; i < 6; i++)
			if (a[i] == 3)	pos = i;
	}
	if (pat == 15) {
		if (four == 2) {
			if (a[(pos + 1) % 6] == 1) {
				s -= b[pos % 6] * b[(pos + 1) % 6];
				s += b[(pos + 3) % 6] * b[(pos + 4) % 6];
			}
			else {
				s += b[(pos + 1) % 6] * b[(pos + 2) % 6];
				s -= b[(pos + 4) % 6] * b[(pos + 5) % 6];
			}
		}
		else {
			s += b[pos % 6] * b[(pos + 5) % 6];
			s -= b[(pos + 2) % 6] * b[(pos + 3) % 6];
		}
	}
	else {
		s += b[pos % 6] * b[(pos + 1) % 6];
		s -= b[(pos + 3) % 6] * b[(pos + 4) % 6];
	}
	cout << s * K;
}