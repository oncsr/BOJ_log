#include <iostream>
using namespace std;

int main() {
	int n, a = 0, b = 0;
	string s;
	cin >> n >> s;
	for (char i : s) {
		a += (i == '2');
		b += (i == 'e');
	}
	if (a == b)	cout << "yee";
	else if (a > b)	cout << 2;
	else	cout << 'e';
}