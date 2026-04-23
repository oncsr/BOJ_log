#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	for (cin >> t; t--;) {
		string a;
		int n;
		cin >> a >> n;
		string b[10]{};
		cout << a << '\n';
		for (int i = 0; i < n + 1; i++) {
			getline(cin, b[i]);
			if (!i)	continue;
			string c = "";
			char prev = ' ';
			for (char i : b[i]) {
				if (i != ' ' && i < 95 && prev == ' ')	c += i;
				prev = i;
			}
			if (c == a)	cout << b[i] << '\n';
		}
	}
}