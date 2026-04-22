#include <iostream>
using namespace std;

int main() {
	string a;
	int b;
	int s = 0;
	while (cin >> a >> b) {
		if (a == "Es")	s += 21 * b;
		else	s += 17 * b;
	}
	cout << s;
}