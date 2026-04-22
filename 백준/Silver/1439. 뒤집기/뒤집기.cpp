#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	cin >> a;
	int one = 0, zero = 0;
	char temp = ' ';
	for (char i : a) {
		if (i != temp) {
			if (i == '1')	one++;
			else	zero++;
		}
		temp = i;
	}
	cout << min(one, zero);
}