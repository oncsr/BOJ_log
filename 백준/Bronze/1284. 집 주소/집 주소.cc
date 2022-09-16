#include <iostream>
using namespace std;

int main() {
	string n;	cin >> n;
	while (n != "0") {
		int s = 1;
		for (auto& i : n) {
			if (i == '0')	s += 5;
			else if (i == '1')	s += 3;
			else	s += 4;
		}
		cout << s << '\n';
		cin >> n;
	}
}