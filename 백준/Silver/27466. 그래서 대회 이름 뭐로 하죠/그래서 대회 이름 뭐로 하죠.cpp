#include <iostream>
using namespace std;

int main() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	int a = 0, c = 0;
	char h;
	for (int i = m - 3; i < n; i++) {
		if (s[i] == 'A')	a++;
		if (a > 1) {
			if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
				c++;
				h = s[i];
			}
		}
	}
	if (c) {
		cout << "YES\n";
		for (int i = 0; i < m - 3; i++)	cout << s[i];
		cout << "AA" << h;
	}
	else	cout << "NO";
}