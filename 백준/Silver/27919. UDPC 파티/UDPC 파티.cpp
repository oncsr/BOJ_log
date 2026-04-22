#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	int u = 0, d = 0, p = 0, c = 0;
	for (char i : a) {
		if (i == 'U')	u++;
		if (i == 'D')	d++;
		if (i == 'P')	p++;
		if (i == 'C')	c++;
	}
	bool s = 0;
	if (u + c > (d + p + 1) / 2)	cout << 'U', s = 1;
	if (d)	cout << 'D', s = 1;
	else {
		if (p)	cout << 'D', s = 1;
	}
	if (p)	cout << 'P', s = 1;
	else {
		if (d)	cout << 'P', s = 1;
	}
	if (!s)	cout << 'C';
}