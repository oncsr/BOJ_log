#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	int s = 0, mx = 0;
	for (char i : a) {
		if (i == 'a')	s++;
		else	s = 0;
		mx = max(mx, s);
	}
	for (int i = 0; i < mx + 1; i++)	cout << 'a';
}