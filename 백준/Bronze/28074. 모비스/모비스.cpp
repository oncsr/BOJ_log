#include <iostream>
using namespace std;

int main() {
	int m = 0, o = 0, b = 0, i = 0, s = 0;
	char a;
	while (cin >> a) {
		if (a == 'M')	m++;
		if (a == 'O')	o++;
		if (a == 'B')	b++;
		if (a == 'I')	i++;
		if (a == 'S')	s++;
	}
	if (m && o && b && i && s)	cout << "YES";
	else	cout << "NO";
}