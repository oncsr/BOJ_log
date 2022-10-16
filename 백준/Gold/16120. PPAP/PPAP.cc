#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int a = 0, p = 0, prev = 0;
	char s[1000000]{}, i;
	while (cin >> i) {
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