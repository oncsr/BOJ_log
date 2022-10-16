#include <iostream>
using namespace std;

int main() {
	int a = 0, p = 0, prev = 0;
	string s;
	cin >> s;
	for (char i : s) {
		if (i == 'P') {
			if (prev && p > 1) {
				p--;
				a--;
				prev = 0;
			}
			else {
				prev = 0;
				p++;
			}
		}
		else {
			if (prev)	prev = 0;
			else {
				a++;
				prev = 1;
			}
		}
	}
	if (a || p != 1)	cout << "NP";
	else	cout << "PPAP";
}