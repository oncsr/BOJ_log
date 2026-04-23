#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	string arm = "+=|=+";
	for (cin >> t; t--;) {
		string a;
		int n, g = 0;
		int ch[26]{};
		cin >> a >> n;
		for (char i : a) {
			if (!ch[i - 'A']) {
				ch[i - 'A'] = 1;
				g++;
			}
		}

		vector<char> p(n);
		for (int i = 0; i < n; i++)	cin >> p[i];
		int s = 0;
		for (char i : p) {
			if (ch[i - 'A'] == 1) {
				g--;
				ch[i - 'A'] = 2;
			}
			else if (!ch[i - 'A'])	s++;
			if (!g)	break;
			if (s == 9)	break;
		}
		cout << a << '\n';
		if (s) {
			s--;
			cout << "  O\n";
		}
		else {
			cout << "SAFE\n";
		}
		if (s) {
			for (int i = 0; i < s && i < 5; i++)
				cout << arm[i];
			s -= min(s, 5);
			cout << '\n';
		}
		if (s) {
			s--;
			cout << "  |\n";
		}
		if (s) {
			cout << " /";
			s--;
			if (s)	cout << " \\" << '\n';
			else	cout << '\n';
		}
		cout << '\n';
	}
}